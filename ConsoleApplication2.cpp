#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include "studentMode.h"
#include "teacherMode.h"
#include "Teacher.h"
#include "Student.h"
#include "ManagerDb.h"


using namespace std;

void setcolor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


int main()
{
	auto* db = ManagerDb::GetInstance();
	db->launchDatabase();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setcolor(14, 0);
	cout << "Вас приветствует система тестирования по курсу 'Программирование'! Выберите режим!" << endl;
	setcolor(15, 0);
	cout << "1. Режим студента" << endl;
	cout << "2. Режим преподавателя" << endl;
	int mode;
	do
	{
		mode = _getch();
		if (mode != 49 && mode != 50)
		{
			setcolor(4, 0);
			cout << "Ошибка выбора режима! Попробуйте еще раз!" << endl;
			setcolor(15, 0);
		}
	} 	while (mode != 49 && mode != 50);
	switch (mode)
	{
	case 49:
	{
		cout << endl << "Загружается режим студента!" << endl;
		for (int i = 0; i <= 50; i++)
		{
			cout << "..";
			Sleep(50);
		}
		setcolor(2, 0);
		cout << endl << "Режим студента запущен!" << endl;
		setcolor(15, 0);
		Sleep(2000);
		system("cls");
		studentMode();
	}
	case 50:
	{
		cout << endl << "Загружается режим преподавателя!" << endl;
		for (int i = 0; i <= 50; i++)
		{
			cout << "..";
			Sleep(50);
		}
		setcolor(2, 0);
		cout << endl << "Режим преподавателя запущен!" << endl;
		setcolor(15, 0);
		Sleep(2000);
		system("cls");
		teacherMode();
	}
	}
}
