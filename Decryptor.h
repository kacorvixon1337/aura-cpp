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


#pragma once
#include <iostream>
#include <string>
#include "LoaderUtils.h"
#include <jni.h>

using namespace std;

class Decryptor
{
private:
	JNIEnv* env;

	jstring key;
	jobject secretKey;
	jobject cipher;

public:
	Decryptor(JNIEnv* env, const char* key);
	Decryptor(JNIEnv* env, const unsigned char data[], int dataSize);
	jbyteArray Decrypt(jbyteArray data);

private:
	void Init();
	void SetKey(jstring key);
	void SetKey(const unsigned char data[], int dataSize);
};

