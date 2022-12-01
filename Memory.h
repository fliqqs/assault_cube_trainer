#pragma once
#include <Windows.h>
#include <stdint.h>

class Memory
{
private:
    static DWORD proccessID;
    static HANDLE proccessHandle;

public:
    static void openProccess(LPCSTR processName);
    static DWORD getPID(LPCSTR processName);
    static HANDLE getHandle(DWORD pid);
    static HANDLE current_handle();

	template <class T>
	static T Read(uintptr_t address)
	{
		T buffer;
		ReadProcessMemory(current_handle(), (LPCVOID)address, &buffer, sizeof(T), NULL);
		return buffer;
	}
};

