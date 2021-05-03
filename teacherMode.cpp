#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include "teacherMode.h"


using namespace std;

void setcolor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void teacherMode()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setcolor(14, 0);
	cout << "Вас приветствует система тестирования по курсу 'Программирование'. Выбран режим преподавателя " << endl;
	cout << "Для доступа авторизуйтесь в системе!" << endl;
	setcolor(15, 0);
	string log, pas;
	bool check = false;
	while (log != "teacher" || pas != "teacher")
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
		if (log == "teacher" && pas == "teacher")
		{
			check = true;
		}
		if (log != "teacher" || pas != "teacher")
		{
			setcolor(4, 0);
			cout << endl << "Неверный логин или пароль" << endl;
			setcolor(15, 0);
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
			cout << endl << "Выберите действие" << endl;
			setcolor(15,0);
			cout << "1. Редактировать вопрос." << endl << "2. Редактировать список студентов." << endl <<  "Пробел - получение справки" << endl << "Esc - выход из программы" << endl;
			kl = _getch();
			if (kl == 49)
				{
					setcolor(14,0);
					cout << endl << "Вы выбрали режим: 'Редактирования вопроса'" << endl;
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
					cout << "Вы выбрали режим: 'Редактирование списка студентов'" << endl;
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
			while (ex == false);
			if (kl != 49 && kl != 50 && kl != 51 && kl != 27 && kl != 32)
			{
				setcolor(4,0);
				cout << endl << "Ошибка выбора! Попробуйте снова!" << endl;
				setcolor(15,0);
			}
			if (kl == 32)
			{
				setcolor(14,0);
				cout << endl << "Выберите режим для получения справки!" << endl;
				setcolor(15,0);
				cout << "1. Редактировать вопрос." << endl;
				cout << "2. Редактировать список студентов." << endl;
				int tl;
				do 
				{
					tl = _getch();
					if (tl == 49)
					{
						system("cls");
						string s;
						setcolor(14, 0);
						cout << "Справка: " << endl;
						ifstream f;
						f.open("Spravka_RQ.txt");
						while (!f.eof())
						{
							getline(f, s);
							cout << s << endl;
						}
						f.close();
						cout << endl;
						setcolor(15, 0);
						cout << "Для продолжения нажмите любую кнопку!" << endl;
						_getch();
					}
					if (tl == 50)
					{
						system("cls");
						string s;
						setcolor(14, 0);
						cout << "Справка: " << endl;
						ifstream f;
						f.open("Spravka_RS.txt");
						while (!f.eof())
						{
							getline(f, s);
							cout << s << endl;
						}
						f.close();
						cout << endl;
						setcolor(15, 0);
						cout << "Для продолжения нажмите любую кнопку!" << endl;
						_getch();
					}
					if (tl != 49 && tl != 50)
					{
						cout << "Ошибка ввода!" << endl;
					}
				} 
				while (tl != 49 && tl != 50);
			}
		} 
		while (kl != 49 && kl != 50 && kl != 51 && kl != 27);
		switch (kl)
		{
		case 27: //выход
		{
			setcolor(14, 0);
			cout << endl << "Выполняется выход из системы тестирования! До свидания!" << endl;
			setcolor(15, 0);
			Sleep(2000);
			exit(0);
		}
		break;
		case 49: 
		{
			bool yn=false;
			int th;
			system("cls");
			setcolor(14, 0);
			cout << "Вы выбрали: 'Режим редактирования вопроса'" << endl;
			setcolor(15, 0);
			do
			{
				do
				{
					cout << endl << "1. Удаление! " << endl << "2. Добавление!" << endl << "3. Изменение!" << endl;
					
					th = _getch();
					if (th == 49)
					{
				
						cout << endl << "Вы выбрали удаление. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
						if (_getch() == 121)
						{
							yn = true;
						}
					}
					if (th == 50)
					{
						cout << endl << "Вы выбрали добавление. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
						if (_getch() == 121)
						{
							yn = true;
						}
					}
					if (th == 51)
					{
						cout << endl << "Вы выбрали изменение. Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
						if (_getch() == 121)
						{
							yn = true;
						}
					}
				} while (yn == false);

			} while (th != 49 && th != 50 && th != 51);
		
			Sleep(5000);
			system("cls");
		}
		break;
		case 50:
		{
			int th;
			bool y=false;
			system("cls");
			setcolor(14, 0);
			cout << "Вы выбрали: 'Работа со списками студентов'" << endl;
			setcolor(15, 0);
			do
			{
				do
				{
					setcolor(14, 0);
					cout << endl << "Выберите действие: " << endl;
					setcolor(15, 0);
					cout << "1. Удаление и регистрация студентов!" << endl << "2. Изменение прогресса студентов!" << endl << "3. Вывод списка с оценками: " <<endl<< "-по всем темам" << endl << "-по конкретной теме" << endl << "-только итоговый тест" << endl << "-только средний балл" << endl << "4. Фильтрация(по конкретным оценкам)!" << endl << "5. Сортировка по оценкам:" << endl << "-по определенной теме" << endl << "-по итоговому тесту" << endl << "-по среднему баллу" << endl;
					th = _getch();
					if (th == 49)
					{
						
							cout << endl << "Вы выбрали удаление и регистрацию студентов! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
					
						if (_getch() == 121)
						{
							y = true;
						}
					
					}
					if (th ==50)
					{
						cout << endl << " Вы выбрали изменение прогресса студентов! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
						if (_getch() == 121)
						{
							y = true;
						}
					}
					if (th == 51)
					{
						cout << endl << "Вы выбрали вывод списка студентов с оценками! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
						if (_getch() == 121)
						{
							int temp;
							do 
							{
								cout <<endl<< "1. По всем темам" << endl << "2. По конкретной теме" << endl << "3. Только итоговый тест" << endl << "4. Только средний балл" << endl;
								
								
								temp = _getch();
								if (temp == 49) 
								{
									cout << endl << "Вы выбрали вывод списка студентов с оценками по всем темам! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp == 50)
								{
									cout << endl << "Вы выбрали вывод списка студентов с оценками по конкретной теме! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp == 51)
								{
									cout << endl << "Вы выбрали вывод списка студентов с оценками по итоговому тесту! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp == 52)
								{
									cout << endl << "Вы выбрали вывод среднего балла! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
							} while (temp != 49 && temp != 50 && temp != 51 && temp != 52);
						}
					}
					if (th == 52)
					{
						cout << endl << "Вы выбрали фильтрацию по конкреиным оценкам! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
						if (_getch() == 121)
						{
							y = true;
						}
					}
					if (th == 53)
					{
						cout << endl << "Вы выбрали сортировку по оценкам! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;;
						if (_getch() == 121)
						{
							int temp1;
							do 
							{
								cout << "1. По определенной теме!" << endl << "2. По итоговому тесту" << endl << "3. По среднему баллу!" << endl;


							 temp1 = _getch();
								if (temp1 == 49)
								{
									cout << endl << "Вы выбрали вывод списка студентов с оценками по всем темам! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp1 == 50)
								{
									cout << endl << "Вы выбрали вывод списка студентов с оценками по конкретной теме! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp1 == 51)
								{
									cout << endl << "Вы выбрали вывод списка студентов с оценками по итоговому тесту! Чтобы подтвердить выбор нажмите 'Y', для выбора другой темы нажмите любую кнопку?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}

							} 
							while (temp1 != 49 && temp1 != 50 && temp1 != 51);
						}
					}
					
				} 
				while (y == false);
			} 
			while (th != 49 && th != 50 && th != 51 && th != 52 && th != 53);
			_getch();
			system("cls");
		}
		break;
		
		}
	}
}
