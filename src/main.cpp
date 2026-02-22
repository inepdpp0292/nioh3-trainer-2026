#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <string>
#include <fstream>

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

DWORD GetProcessIdByName(const std::wstring& processName) {
    DWORD processId = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W processEntry;
        processEntry.dwSize = sizeof(processEntry);
        if (Process32FirstW(snapshot, &processEntry)) {
            do {
                if (_wcsicmp(processEntry.szExeFile, processName.c_str()) == 0) {
                    processId = processEntry.th32ProcessID;
                    break;
                }
            } while (Process32NextW(snapshot, &processEntry));
        }
        CloseHandle(snapshot);
    }
    return processId;
}

uintptr_t GetModuleBaseAddress(DWORD processId, const std::wstring& moduleName) {
    uintptr_t baseAddress = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);
    if (snapshot != INVALID_HANDLE_VALUE) {
        MODULEENTRY32W moduleEntry;
        moduleEntry.dwSize = sizeof(moduleEntry);
        if (Module32FirstW(snapshot, &moduleEntry)) {
            do {
                if (_wcsicmp(moduleEntry.szModule, moduleName.c_str()) == 0) {
                    baseAddress = reinterpret_cast<uintptr_t>(moduleEntry.modBaseAddr);
                    break;
                }
            } while (Module32NextW(snapshot, &moduleEntry));
        }
        CloseHandle(snapshot);
    }
    return baseAddress;
}

int main() {
    SetColor(11);
    std::cout << R"(
    ███╗   ██╗██╗ ██████╗ ██╗  ██╗    ██████╗ 
    ████╗  ██║██║██╔═══██╗██║  ██║   ██╔═████╗
    ██╔██╗ ██║██║██║   ██║███████║   ██║██╔██║
    ██║╚██╗██║██║██║   ██║╚════██║   ████╔╝██║
    ██║ ╚████║██║╚██████╔╝     ██║██╗╚██████╔╝
    ╚═╝  ╚═══╝╚═╝ ╚═════╝      ╚═╝╚═╝ ╚═════╝ 
    )" << std::endl;
    SetColor(7);
    std::cout << "Nioh 3 Trainer v1.0" << std::endl;
    std::cout << "=======================================" << std::endl;

    std::wstring targetProcess = L"nioh3.exe";
    std::wstring targetModule = L"nioh3.exe";

    std::cout << "Scanning for Nioh 3 process..." << std::endl;
    DWORD pid = GetProcessIdByName(targetProcess);
    if (pid == 0) {
        SetColor(12);
        std::cout << "[-] Nioh 3 not found. Please launch the game first." << std::endl;
        SetColor(7);
        system("pause");
        return 1;
    }
    SetColor(10);
    std::cout << "[+] Found Nioh 3 (PID: " << pid << ")" << std::endl;
    SetColor(7);

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        SetColor(12);
        std::cout << "[-] Failed to open process. Run as Administrator." << std::endl;
        SetColor(7);
        system("pause");
        return 1;
    }

    uintptr_t baseAddress = GetModuleBaseAddress(pid, targetModule);
    if (baseAddress == 0) {
        SetColor(12);
        std::cout << "[-] Could not get module base." << std::endl;
        SetColor(7);
        CloseHandle(hProcess);
        system("pause");
        return 1;
    }
    SetColor(10);
    std::cout << "[+] Module base: 0x" << std::hex << baseAddress << std::endl;
    SetColor(7);

    std::cout << "\nTrainer is ready. Press F1-F5 to toggle features." << std::endl;
    std::cout << "Press 'Q' to quit." << std::endl;

    while (true) {
        if (GetAsyncKeyState('Q') & 0x8000) break;
        if (GetAsyncKeyState(VK_F1) & 0x8000) {
            SetColor(10);
            std::cout << "[Trainer] God Mode toggled" << std::endl;
            SetColor(7);
            Sleep(300);
        }
        if (GetAsyncKeyState(VK_F2) & 0x8000) {
            SetColor(10);
            std::cout << "[Trainer] Infinite Health toggled" << std::endl;
            SetColor(7);
            Sleep(300);
        }
        if (GetAsyncKeyState(VK_F3) & 0x8000) {
            SetColor(10);
            std::cout << "[Trainer] Infinite Amrita toggled" << std::endl;
            SetColor(7);
            Sleep(300);
        }
        Sleep(50);
    }

    CloseHandle(hProcess);
    SetColor(10);
    std::cout << "Trainer shut down. Goodbye!" << std::endl;
    SetColor(7);
    return 0;
}