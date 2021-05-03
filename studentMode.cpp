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

using namespace std;

void setcolor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void studentMode()
{
	SetConsoleCP(1251);
 	SetConsoleOutputCP(1251);
 	setcolor(14,0);
	cout << "Вас приветствует система тестирования по курсу 'Программирование'! Выбран режим студента!" << endl;
	cout << "Для доступа авторизуйтесь в системе!" << endl;
	setcolor(15,0);
	string log, pas;
	bool check = false;
	while (log != "silkin" || pas != "silkin")
	{
		cout << endl << "Логин: ";
		cin >> log;
		cout << endl << "Пароль: ";
   		char inCh, temp[100] = "";
		int iNum = 0;
		while(true)
		{
			inCh = _getch();
			if (inCh != 8)
			{
				if(inCh!=13)
				{
					temp[iNum++] = inCh;
					cout << "*";
				}
				else
					break;
			}
		}
		pas = temp;
		if (log == "silkin" && pas == "silkin")
		{
			check = true;	
		}
		if (log != "silkin" || pas != "silkin")
		{
			setcolor(4,0);
			cout << endl << "Неверный логин или пароль!" << endl;
			setcolor(15,0);
		}
	}
	if (check)
	{
		system("cls");
		setcolor(2,0);
		cout << "Успешная авторизация!" << endl;
		Sleep(3000);
		system("cls");
		setcolor(15,0);
		int kl;
		do
		{
			bool ex = false;
			int flag;
			do
			{
				setcolor(14,0);
				cout << endl << "Выберите режим тестирования:"  << endl;
				setcolor(15,0);
				cout << "1. Тренинг по теме" << endl << "2. Тестирование по теме" << endl << "3. Итоговый тест" << endl << "Пробел - получение справки" << endl << "Esc - выход из программы" << endl;
				kl = _getch();
				if (kl == 49)
				{
					setcolor(14,0);
					cout << endl << "Вы выбрали режим: 'Тренинг по теме'" << endl;
					setcolor(2,0);
					cout << endl << "Нажмите 'Y' чтобы подтвердить выбор.";
					setcolor(4,0);
					cout << " Чтобы выбрать другой режим нажмите 'N'" << endl;
					setcolor(15,0);
					do
					{
						flag = _getch();
					}
					while (flag != 121 && flag != 110);
					if (flag == 121)
					{
						ex = true;
					}
					if (flag == 110)
					{
						ex = false;
					}
				}
				if (kl == 50)
				{
					setcolor(14,0);
					cout << "Вы выбрали режим: 'Тестирование по теме'" << endl;
					setcolor(2,0);
					cout << endl << "Нажмите 'Y' чтобы подтвердить выбор.";
					setcolor(4,0);
					cout << " Чтобы выбрать другой режим нажмите 'N'" << endl;
					setcolor(15,0);
					do
					{
						flag = _getch();
					}
					while (flag != 121 && flag != 110);
					if (flag == 121)
					{
						ex = true;
					}
					if (flag == 110)
					{
						ex = false;
					}
				}
				if (kl == 51)
				{
					setcolor(14,0);
					cout << endl << "Вы выбрали режим: 'Итоговый тест'" << endl;
					setcolor(2,0);
					cout << endl << "Нажмите 'Y' чтобы подтвердить выбор.";
					setcolor(4,0);
					cout << " Чтобы выбрать другой режим нажмите 'N'" << endl;
					setcolor(15,0);
					do
					{
						flag = _getch();
					}
					while (flag != 121 && flag != 110);
					if (flag == 121)
					{
						ex = true;
					}
					if (flag == 110)
					{
						ex = false;
					}
				}
				if (kl == 27 || kl == 32)
				{
					ex = true;
				}	
			}
			while (ex == false );
			if (kl != 49 && kl != 50 && kl != 51 && kl != 27 && kl != 32)
				{
					setcolor(4,0);
					cout << endl << "Ошибка выбора! Попробуйте снова!" << endl;
					setcolor(15,0);
				}
			if (kl == 32)
			{
					system("cls");
					string s;
					setcolor(14,0);
					cout << "Справка: " << endl;
					ifstream f;
					f.open("Spravka.txt");
				 	while (!f.eof())
					{
						getline(f,s);
						cout << s << endl;
					}
	                f.close();
	                cout << endl;
	                setcolor(15,0);
	                cout << "Для продолжения нажмите любую кнопку!" << endl;
	                _getch();
			}
		}
		while (kl != 49 && kl != 50 && kl != 51 && kl != 27);
		switch (kl)
		{
			case 27: //выход
			{
				setcolor(14,0);
				cout << endl << "Выполняется выход из системы тестирования! До свидания!" << endl;	
				setcolor(15,0);
				Sleep(2000);
				exit(0);
			}
			break;
			case 49: // 1 тема
			{
				int th = 0; //заглушка для запуска
				bool yn;
				system("cls");
				setcolor(14,0);
				cout << "Вы выбрали: 'Тренинг по теме'" << endl;
				setcolor(15,0);
				do
				{
					do
					{
						cout << endl << "Выберите тему: " << endl;
						th = _getch();
						if (th == 49)
						{
							cout << endl << "Вы выбрали 1 тему. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
							if (_getch() == 121);
							{
								yn = true;
							}
						}
						if (th == 50)
						{
							cout << endl << "Вы выбрали 2 тему. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th == 51)
						{
							cout << endl << "Вы выбрали 3 тему. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th != 49 && th != 50 && th != 51)
						{
							setcolor(4,0);
							cout << endl << "Ошибка выбора! Попробуйте снова!" << endl;
							setcolor(15,0);
						}
					}
					while (yn == false);
				}
				while (th != 49 && th != 50 && th != 51);
				cout << "Желаем удачи! Для начала тестирования нажмите на любую кнопку" << endl;
				_getch();
				system("cls");
			}
			break;
			case 50: 
			{
				int th; //заглушка для запуска
				bool yn;
				system("cls");
				setcolor(14,0);
				cout << "Вы выбрали: 'Тестирование по теме'" << endl;
				setcolor(15,0);
				do
				{
					do
					{
						cout << endl << "Выберите тему: " << endl;
						th = _getch();
						if (th == 49)
						{
							cout << endl << "Вы выбрали 1 тему. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
							if (_getch() == 121);
							{
								yn = true;
							}
						}
						if (th == 50)
						{
							cout << endl << "Вы выбрали 2 тему. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th == 51)
						{
							cout << endl << "Вы выбрали 3 тему. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th != 49 && th != 50 && th != 51)
						{
							setcolor(4,0);
							cout << endl << "Ошибка выбора! Попробуйте снова!" << endl;
							setcolor(15,0);
						}
					}
					while (yn == false);
				}
				while (th != 49 && th != 50 && th != 51);
				cout << "Желаем удачи! Для начала тестирования нажмите на любую кнопку" << endl;
				_getch();
				system("cls");	
			}
			break;
			case 51:
			{
				system("cls");
				setcolor(14,0);
				cout << "Вы выбрали: 'Итоговый тест'" << endl;
				setcolor(15,0);
				cout << "Желаем удачи! Для начала тестирования нажмите на любую кнопку" << endl;
				_getch();
				system("cls");
			}
			break;
		}
	}
}
