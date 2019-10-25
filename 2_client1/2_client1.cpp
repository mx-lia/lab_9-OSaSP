// 2_client1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	hslot = CreateFile(slotname, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT WRITING FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	std::cout << "SLOT IS WAITING" << std::endl;
	string n;
	DWORD dwBytesWrite;
	std::cout << "ENTER MESSAGE:" << std::endl;
	cin >> n;
	if (!WriteFile(hslot, &n, sizeof(n), &dwBytesWrite, NULL))
	{
		std::cout << "WRITE FAILED" << std::endl;
		CloseHandle(hslot);
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;
	}

	std::cout << "Data WRITTEN TO BOX: " << n << std::endl;
	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;
}

