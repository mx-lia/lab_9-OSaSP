// 1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	int i, n;
	char** massiv;

	system("mode con cols=70 lines=10");
	system("title String");
	setlocale(LC_ALL, "RUS");
	system("cls");
	SetConsoleTextAttribute(H, 11);

	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	massiv = (char**)malloc(n * sizeof(char*));       //выделение динам.памяти

	if (!massiv)                              //проверка факта выделения памяти
	{
		cout << "\nНедостаточно памяти";

		cout << "\nНажмите любую клавишу для завершения программы ...\n";
		_getch();

		return 0;
	}

	cout << "Введите массив из строк, нажимая ENTER после каждого элемента\n";

	string buf;
	for (i = 0; i < n; i++)
	{
		cin >> buf;       //ввод массива
		massiv[i] = (char*)malloc((sizeof(buf) + 1) * sizeof(char));
		buf.push_back('\0');
		buf.copy(massiv[i], buf.size());
	}

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
		cout << ' ' << massiv[i];       //вывод массива

	free(massiv);
	_getch();
	return 0;
}
