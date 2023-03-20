/*
 * Copyright 2021 AFYaan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License atv
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Loader.h"

#include "LoaderUtils.h"
#include <iostream>

#include "Decryptor.h"
#include "Resources.h"
#include "ClassLoader.h"

using namespace std;
Loader* instance;
Loader::Loader(const string mainClass) {
	this->Loader::Loader(GetCurrentExeName(), mainClass);
}

Loader::Loader(const string jarPath, const string mainClass) {
	this->jarPath = jarPath;
	this->mainClassPath = mainClass;
	this->isInit = false;
	this->jvm = nullptr;
	this->passwordSize = 0;
	instance = this;
}

static jrawMonitorID vmtrace_lock;
static jlong start_time;

jbyteArray asByteArray(JNIEnv* env, const unsigned char* buf, int len) {
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)buf);
	return array;
}

unsigned char* asUnsignedCharArray(JNIEnv* env, jbyteArray array) {
	int len = env->GetArrayLength(array);
	unsigned char* buf = new unsigned char[len];
	env->GetByteArrayRegion(array, 0, len, reinterpret_cast<jbyte*>(buf));
	return buf;
}

static int index, classesToRedefine;
static int redefine(jvmtiEnv* jvmti, jvmtiClassDefinition* class_def) {
	if (!jvmti->RedefineClasses(1, class_def))
		return 0;

	return 1;
}

static jrawMonitorID lock;
int classCount = 0;
void JNICALL ClassFileLoadHook(jvmtiEnv* jvmti, JNIEnv* jni,
	jclass class_being_redefined, jobject loader,
	const char* name, jobject protection_domain,
	jint data_len, const unsigned char* data,
	jint* new_data_len, unsigned char** new_data) {

	jvmti->RawMonitorEnter(lock);

	if (name != NULL) {
		string className = string(name);
		if (className.rfind("java/", 0) == 0) {
			return;
		}
		if (className.rfind("sun/", 0) == 0) {
			return;
		}
		if (className.rfind("com/", 0) == 0) {
			return;
		}
		if (className.rfind("javax/", 0) == 0) {
			return;
		}
		if (className.rfind("paulscode/", 0) == 0) {
			return;
		}
		if (className.rfind("org/", 0) == 0) {
			return;
		}
		if (className.rfind("oshi/", 0) == 0) {
			return;
		}
		if (className.rfind("internal/", 0) == 0) {
			return;
		}
		if (className.rfind("jdk/", 0) == 0) {
			return;
		}
		if (className.rfind("joptsimple/", 0) == 0) {
			return;
		}
		if (className.rfind("net/java", 0) == 0) {
			return;
		}
		if (className.rfind("net/minecraft/client/main/Main", 0) == 0) {
			//return;
		}
		if (className.rfind("pl/afyaan", 0) == 0) {
			return;
		}
		if (className.rfind("javassist", 0) == 0) {
			return;
		}
		if (className.rfind("module-info", 0) == 0) {
			return												;
		}
		//if ((int)name[0] == -64 && (int)name[1] == -128) {

			//cout << "KLASA KURWA NAZWA KLASY|" << className << "|KONIEC NAZWY KLASY" << endl;
		jvmti->Allocate(data_len, new_data);
		*new_data_len = data_len;
		memcpy(*new_data, data, data_len);

		//Transform classn
		const jbyteArray bytecode = (jbyteArray)jni->CallObjectMethod(instance->killaura, instance->killauraTransform, loader, jni->NewStringUTF(className.c_str()), asByteArray(jni, *new_data, *new_data_len));
		unsigned char* bytecodedata = asUnsignedCharArray(jni, bytecode);
		const jint newLength = (jint)jni->GetArrayLength(bytecode);
		jvmti->Allocate(newLength, new_data);
		*new_data_len = newLength;
		memcpy(*new_data, bytecodedata, newLength);
		//}
		jvmti->RawMonitorExit(lock);
	}



	//trace(jvmti, "Loading class: %s", name);
}

void Loader::Init() {
	if (isInit) return;

	jvmMod = LoadLibraryA((GetExeDir() + string("\\bin\\server\\jvm.dll")).c_str());

	if (jvmMod == nullptr) {
		cout << "Error: " << "jvm.dll could not be loaded" << endl;
		exit(EXIT_FAILURE);
	}

	typedef jint(JNICALL* PtrCreateJavaVM)(JavaVM**, void**, void*);
	PtrCreateJavaVM ptrCreateJavaVM = (PtrCreateJavaVM)GetProcAddress(jvmMod, "JNI_CreateJavaVM");

	JavaVMInitArgs vmArgs;
	JavaVMOption* vmOptions = new JavaVMOption[32];

	string optClassPath = string("-Djava.class.path=") + this->jarPath;

	int argLength = 0;
	vmOptions[argLength].optionString = (char*)optClassPath.c_str();

	for (const char* arg : jvmArgList) {
		argLength++;
		vmOptions[argLength].optionString = (char*)arg;
	}

	vmArgs.version = JNI_VERSION_1_8;
	vmArgs.nOptions = argLength + 1;
	vmArgs.options = vmOptions;
	vmArgs.ignoreUnrecognized = JNI_FALSE;

	jint vm = ptrCreateJavaVM(&jvm, (void**)&env, &vmArgs);

	if (vm != JNI_OK) {
		cout << "Error: " << "Can't create java vm" << endl;
		exit(EXIT_FAILURE);
	}

	isInit = true;

	jvm->GetEnv((void**)&jvmti, JVMTI_VERSION_1_0);
	jvmti->CreateRawMonitor("vmtrace_lock", &vmtrace_lock);
	jvmti->GetTime(&start_time);
	//trace(jvmti, "VMTrace started");

	jvmtiCapabilities capabilities;
	capabilities.can_generate_all_class_hook_events = 1;
	capabilities.can_retransform_any_class = 1;
	capabilities.can_retransform_classes = 1;
	capabilities.can_redefine_any_class = 1;
	capabilities.can_redefine_classes = 1;
	jvmti->AddCapabilities(&capabilities);

	jvmtiEventCallbacks callbacks = { 0 };
	/*callbacks.VMStart = VMStart;
	callbacks.VMInit = VMInit;
	callbacks.VMDeath = VMDeath;*/
	callbacks.ClassFileLoadHook = ClassFileLoadHook;
	/* callbacks.ClassPrepare = ClassPrepare;
	 callbacks.DynamicCodeGenerated = DynamicCodeGenerated;
	 callbacks.CompiledMethodLoad = CompiledMethodLoad;
	 callbacks.GarbageCollectionStart = GarbageCollectionStart;
	 callbacks.GarbageCollectionFinish = GarbageCollectionFinish;*/
	jvmti->SetEventCallbacks(&callbacks, sizeof(callbacks));

	instance->jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_CLASS_FILE_LOAD_HOOK, NULL);
	/*jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_VM_START, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_VM_INIT, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_VM_DEATH, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_CLASS_FILE_LOAD_HOOK, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_CLASS_PREPARE, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_DYNAMIC_CODE_GENERATED, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_COMPILED_METHOD_LOAD, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_GARBAGE_COLLECTION_START, NULL);
	jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_GARBAGE_COLLECTION_FINISH, NULL);*/
	//jvmti->CreateRawMonitor("agent lock", &lock);

	//jvmti->RetransformClasses
}

void Loader::SetPassword(const string password) {
	this->password = password;
	this->rawPassword = false;
}

void Loader::SetPassword(const unsigned char data[], int dataSize) {
	memcpy(this->passwordData, data, dataSize);
	this->passwordSize = dataSize;
	this->rawPassword = true;
}

JNIEnv* Loader::getEnv()
{
	return env;
}

void Loader::Run() {
	Run(NULL, 0);
}

void Loader::Run(const char* args[], int argsLength) {
	Init();

	jclass mainClass = env->FindClass(mainClassPath.c_str());

	if (mainClass == nullptr) {
		cout << "Error: " << "Main class not found" << endl;
		exit(EXIT_FAILURE);
	}

	jmethodID mainMethod = env->GetStaticMethodID(mainClass, "main", "([Ljava/lang/String;)V");

	if (mainMethod == nullptr) {
		cout << "Error: " << "Main method not found" << endl;
		exit(EXIT_FAILURE);
	}

	const char* newArgs[1024];
	int newLength = 0;

	for (int i = 0; i < argsLength; i++) {
		newArgs[i] = args[i];
		newLength++;
	}

	for (const char* arg : appArgs) {
		newArgs[newLength] = arg;
		newLength++;
	}

	for (int i = 0; i < newLength; i++) {
		cout << "Arg: " << newArgs[i] << endl;
	}
	env->CallStaticVoidMethod(mainClass, mainMethod, CharArrayToJavaStringArray(env, newArgs, newLength));
}

void Loader::RunFromMemory(const unsigned char data[], int dataSize, bool autoDestroy) {
	RunFromMemory(data, dataSize, NULL, 0, autoDestroy);
}

void Loader::RunFromMemory(const unsigned char data[], int dataSize, const char* args[], int argsLength, bool autoDestroy) {
	Init();


	jclass byteArrayinputStream = env->FindClass("java/io/ByteArrayInputStream");
	jmethodID byteArrayinputStreamConstructor = env->GetMethodID(byteArrayinputStream, "<init>", "([B)V");
	jobject stream = nullptr;
	if (!this->password.empty() || this->passwordSize != 0) {
		unique_ptr<Decryptor> decryptor;
		if (!this->password.empty()) {
			decryptor = unique_ptr<Decryptor>(new Decryptor(env, password.c_str()));
		}
		else if (this->passwordSize != 0) {
			decryptor = unique_ptr<Decryptor>(new Decryptor(env, passwordData, passwordSize));
		}
		jobject decryptedData = decryptor->Decrypt(CharArrayToJavaByteArray(env, data, dataSize));

		stream = env->NewObject(byteArrayinputStream, byteArrayinputStreamConstructor, decryptedData);
	}
	else {
		stream = env->NewObject(byteArrayinputStream, byteArrayinputStreamConstructor, CharArrayToJavaByteArray(env, data, dataSize));
	}

	unique_ptr<ClassLoader> classLoader(new ClassLoader(env, stream, password));
	classLoader->load();
	killauraClass = env->FindClass("pl/afyaan/Transformer");
	jmethodID killauraInit = env->GetMethodID(killauraClass, "<init>", "()V");
	killaura = env->NewObject(killauraClass, killauraInit);
	killauraTransform = env->GetMethodID(killauraClass, "retransformClass", "(Ljava/lang/ClassLoader;Ljava/lang/String;[B)[B");

}

void Loader::DestroyVM() {
	jvm->DestroyJavaVM();
}

void Loader::SetJVMArgs(const char* args[], int size) {
	jvmArgList.clear();
	for (int i = 0; i < size; i++) {
		jvmArgList.push_back(args[i]);
	}
}

void Loader::AddJVMArg(const char* arg) {
	jvmArgList.push_back(arg);
}

void Loader::AddArg(const char* arg) {
	appArgs.push_back(arg);
}