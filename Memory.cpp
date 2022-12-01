#include "Memory.h"
#include <iostream>

DWORD Memory::proccessID;
HANDLE Memory::proccessHandle;


void Memory::openProccess(LPCSTR proccessName)
{
    proccessID = Memory::getPID(proccessName);
    proccessHandle = Memory::getHandle(proccessID);
}

DWORD Memory::getPID(LPCSTR proccessName)
{
    DWORD proccessID;
    HWND windowHandle = FindWindowA(NULL, proccessName);
    std::cout << windowHandle << std::endl;
    GetWindowThreadProcessId(windowHandle, &proccessID);
    return proccessID;
}

HANDLE Memory::getHandle(DWORD pid)
{
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

HANDLE Memory::current_handle()
{
    return proccessHandle;
}