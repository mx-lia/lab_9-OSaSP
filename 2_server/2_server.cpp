// 2_server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <string.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hslot;
	LPTSTR slotname = (LPTSTR)TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	std::cout << "SLOT IS WAITING" << std::endl;
	string nData;
	DWORD dwBytesRead;
	if (!ReadFile(hslot, &nData, sizeof(nData), &dwBytesRead, (LPOVERLAPPED)NULL))
	{
		std::cout << "READING SLOT FAILED" << std::endl;
		CloseHandle(hslot);
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;
	}

	std::cout << "Data Read :" << nData << std::endl;
	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;
}

