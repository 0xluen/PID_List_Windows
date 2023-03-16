#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>

int main()
{
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cout << "Baþarýsýz";
        return 1;
    }

    BOOL hasNext = Process32First(hSnapshot, &processEntry);

    while (hasNext) {
        std::wstring processName(processEntry.szExeFile);
        std::wcout << "PID: " << processEntry.th32ProcessID << " - " << processName << std::endl;
        hasNext = Process32Next(hSnapshot, &processEntry);
    }

    CloseHandle(hSnapshot);
    return 0;
}
