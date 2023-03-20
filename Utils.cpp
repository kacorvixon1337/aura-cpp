#include "Utils.h"

string getLibraries(string gameDir) {
	string libDir = gameDir + string("\\libraries\\");
	string versionsDir = gameDir + string("\\versions\\");
	vector<string> libraries;

	libraries.push_back(libDir + (char*)"org\\objectweb\\asm\\asm-9.3.jar");
	libraries.push_back(libDir + (char*)"org\\objectweb\\asm\\asm-analysis-9.3.jar");
	libraries.push_back(libDir + (char*)"org\\objectweb\\asm\\asm-commons-9.3.jar");
	libraries.push_back(libDir + (char*)"org\\objectweb\\asm\\asm-tree-9.3.jar");
	libraries.push_back(libDir + (char*)"org\\objectweb\\asm\\asm-util-9.3.jar");
	libraries.push_back(libDir + (char*)"org\\objectweb\\asm\\javassist.jar");
	libraries.push_back(libDir + (char*)"com\\mojang\\netty\\1.8.8\\netty-1.8.8.jar");
	libraries.push_back(libDir + (char*)"oshi-project\\oshi-core\\1.1\\oshi-core-1.1.jar");
	libraries.push_back(libDir + (char*)"net\\java\\dev\\jna\\jna\\3.4.0\\jna-3.4.0.jar");
	libraries.push_back(libDir + (char*)"net\\java\\dev\\jna\\platform\\3.4.0\\platform-3.4.0.jar");
	libraries.push_back(libDir + (char*)"com\\ibm\\icu\\icu4j-core-mojang\\51.2\\icu4j-core-mojang-51.2.jar");
	libraries.push_back(libDir + (char*)"net\\sf\\jopt-simple\\jopt-simple\\4.6\\jopt-simple-4.6.jar");
	libraries.push_back(libDir + (char*)"com\\paulscode\\codecjorbis\\20101023\\codecjorbis-20101023.jar");
	libraries.push_back(libDir + (char*)"com\\paulscode\\codecwav\\20101023\\codecwav-20101023.jar");
	libraries.push_back(libDir + (char*)"com\\paulscode\\libraryjavasound\\20101123\\libraryjavasound-20101123.jar");
	libraries.push_back(libDir + (char*)"com\\paulscode\\librarylwjglopenal\\20100824\\librarylwjglopenal-20100824.jar");
	libraries.push_back(libDir + (char*)"com\\paulscode\\soundsystem\\20120107\\soundsystem-20120107.jar");
	libraries.push_back(libDir + (char*)"io\\netty\\netty-all\\4.0.23.Final\\netty-all-4.0.23.Final.jar");
	libraries.push_back(libDir + (char*)"com\\google\\guava\\guava\\17.0\\guava-17.0.jar");
	libraries.push_back(libDir + (char*)"org\\apache\\commons\\commons-lang3\\3.3.2\\commons-lang3-3.3.2.jar");
	libraries.push_back(libDir + (char*)"commons-io\\commons-io\\2.4\\commons-io-2.4.jar");
	libraries.push_back(libDir + (char*)"commons-codec\\commons-codec\\1.9\\commons-codec-1.9.jar");
	libraries.push_back(libDir + (char*)"net\\java\\jinput\\jinput\\2.0.5\\jinput-2.0.5.jar");
	libraries.push_back(libDir + (char*)"net\\java\\jutils\\jutils\\1.0.0\\jutils-1.0.0.jar");
	libraries.push_back(libDir + (char*)"com\\google\\code\\gson\\gson\\2.2.4\\gson-2.2.4.jar");
	libraries.push_back(libDir + (char*)"com\\mojang\\authlib\\1.5.21\\authlib-1.5.21.jar");
	libraries.push_back(libDir + (char*)"com\\mojang\\realms\\1.7.39\\realms-1.7.39.jar");
	libraries.push_back(libDir + (char*)"org\\apache\\commons\\commons-compress\\1.8.1\\commons-compress-1.8.1.jar");
	libraries.push_back(libDir + (char*)"org\\apache\\httpcomponents\\httpclient\\4.3.3\\httpclient-4.3.3.jar");
	libraries.push_back(libDir + (char*)"commons-logging\\commons-logging\\1.1.3\\commons-logging-1.1.3.jar");
	libraries.push_back(libDir + (char*)"org\\apache\\httpcomponents\\httpcore\\4.3.2\\httpcore-4.3.2.jar");
	libraries.push_back(libDir + (char*)"org\\apache\\logging\\log4j\\log4j-api\\2.0-beta9\\log4j-api-2.0-beta9.jar");
	libraries.push_back(libDir + (char*)"org\\apache\\logging\\log4j\\log4j-core\\2.0-beta9\\log4j-core-2.0-beta9.jar");
	libraries.push_back(libDir + (char*)"org\\lwjgl\\lwjgl\\lwjgl\\2.9.4-nightly-20150209\\lwjgl-2.9.4-nightly-20150209.jar");
	libraries.push_back(libDir + (char*)"org\\lwjgl\\lwjgl\\lwjgl_util\\2.9.4-nightly-20150209\\lwjgl_util-2.9.4-nightly-20150209.jar");
	libraries.push_back(libDir + (char*)"tv\\twitch\\twitch\\6.5\\twitch-6.5.jar");
	libraries.push_back(versionsDir + (char*)"blazingpack_1.8.8\\blazingpack_1.8.8.jar");

	std::stringstream out;

	for (auto& str : libraries) {
		out << ";" << str;
	}

	return out.str().substr(1, out.str().size());
}
