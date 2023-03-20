#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <iostream>

using namespace std;

char* strtolower(char* s);

char* lwcToCharArray(LPCWSTR value);

string getLibraries(string gameDir);

