
// 1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

typedef struct books
{
	char* title;
} my_books, *p_mybooks;

int main()
{
	int i, n;

	system("mode con cols=70 lines=10");
	system("title String");
	setlocale(LC_ALL, "RUS");
	system("cls");
	SetConsoleTextAttribute(H, 11);

	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	p_mybooks p_mystruct = new my_books[n];

	if (!p_mystruct)                              //проверка факта выделения памяти
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
		p_mystruct[i].title = (char*)malloc((sizeof(buf) + 1) * sizeof(char));
		buf.push_back('\0');
		buf.copy(p_mystruct[i].title, buf.size());
	}

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
	{
		cout << " Struct number" << i << endl;
		cout << ' ' << p_mystruct[i].title << endl << endl;       //вывод массива
	}

	free(p_mystruct);
	_getch();
	return 0;
}
