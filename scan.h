#include <basetsd.h>
#include <wtypes.h>
char* ScanBasic(const char* pattern, const char* mask, char* begin, intptr_t size)
{
    intptr_t patternLen = strlen(mask);

    for (int i = 0; i < size; i++)
    {
        bool found = true;
        for (int j = 0; j < patternLen; j++)
        {
            if (mask[j] != '?' && pattern[j] != *(char*)((intptr_t)begin + i + j))
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return (begin + i);
        }
    }
    return nullptr;
}

void* ScanEx(const char* pattern, const char* mask, char* begin, intptr_t size, HANDLE hProc) {
    char* match{ nullptr };
    SIZE_T bytesRead;
    DWORD oldprotect;
    char* buffer{ nullptr };
    MEMORY_BASIC_INFORMATION mbi;
    mbi.RegionSize = 0x1000;

    VirtualQueryEx(hProc, (LPCVOID)begin, &mbi, sizeof(mbi));

    for (char* curr = begin; curr < begin + size; curr += mbi.RegionSize)
    {
        if (!VirtualQueryEx(hProc, curr, &mbi, sizeof(mbi))) continue;
        if (mbi.State != MEM_COMMIT || mbi.Protect == PAGE_NOACCESS || mbi.Protect != PAGE_EXECUTE_READWRITE) continue;

        delete[] buffer;
        buffer = new char[mbi.RegionSize];

        if (VirtualProtectEx(hProc, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
        {
            ReadProcessMemory(hProc, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
            VirtualProtectEx(hProc, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

            char* internalAddr = ScanBasic(pattern, mask, buffer, (intptr_t)bytesRead);

            if (internalAddr != nullptr) {
                match = curr + (internalAddr - buffer);
                break;
            }
        }
    }
    delete[] buffer;
    return match;
}