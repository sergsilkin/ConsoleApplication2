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
	cout << "��� ������������ ������� ������������ �� ����� '����������������'. ������ ����� ������������� " << endl;
	cout << "��� ������� ������������� � �������!" << endl;
	setcolor(15, 0);
	string log, pas;
	bool check = false;
	while (log != "teacher" || pas != "teacher")
	{
		cout << endl << "�����: ";
		cin >> log;
		cout << endl << "������: ";
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
			cout << endl << "�������� ����� ��� ������" << endl;
			setcolor(15, 0);
		}
	}
	if (check)
	{
		system("cls");
		setcolor(2,0);
		cout << "�������� �����������!" << endl;
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
			cout << endl << "�������� ��������" << endl;
			setcolor(15,0);
			cout << "1. ������������� ������." << endl << "2. ������������� ������ ���������." << endl <<  "������ - ��������� �������" << endl << "Esc - ����� �� ���������" << endl;
			kl = _getch();
			if (kl == 49)
				{
					setcolor(14,0);
					cout << endl << "�� ������� �����: '�������������� �������'" << endl;
					setcolor(2,0);
					cout << endl << "������� 'Y' ����� ����������� �����.";
					setcolor(4,0);
					cout << " ����� ������� ������ ����� ������� 'N'" << endl;
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
					cout << "�� ������� �����: '�������������� ������ ���������'" << endl;
					setcolor(2,0);
					cout << endl << "������� 'Y' ����� ����������� �����.";
					setcolor(4,0);
					cout << " ����� ������� ������ ����� ������� 'N'" << endl;
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
				cout << endl << "������ ������! ���������� �����!" << endl;
				setcolor(15,0);
			}
			if (kl == 32)
			{
				setcolor(14,0);
				cout << endl << "�������� ����� ��� ��������� �������!" << endl;
				setcolor(15,0);
				cout << "1. ������������� ������." << endl;
				cout << "2. ������������� ������ ���������." << endl;
				int tl;
				do 
				{
					tl = _getch();
					if (tl == 49)
					{
						system("cls");
						string s;
						setcolor(14, 0);
						cout << "�������: " << endl;
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
						cout << "��� ����������� ������� ����� ������!" << endl;
						_getch();
					}
					if (tl == 50)
					{
						system("cls");
						string s;
						setcolor(14, 0);
						cout << "�������: " << endl;
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
						cout << "��� ����������� ������� ����� ������!" << endl;
						_getch();
					}
					if (tl != 49 && tl != 50)
					{
						cout << "������ �����!" << endl;
					}
				} 
				while (tl != 49 && tl != 50);
			}
		} 
		while (kl != 49 && kl != 50 && kl != 51 && kl != 27);
		switch (kl)
		{
		case 27: //�����
		{
			setcolor(14, 0);
			cout << endl << "����������� ����� �� ������� ������������! �� ��������!" << endl;
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
			cout << "�� �������: '����� �������������� �������'" << endl;
			setcolor(15, 0);
			do
			{
				do
				{
					cout << endl << "1. ��������! " << endl << "2. ����������!" << endl << "3. ���������!" << endl;
					
					th = _getch();
					if (th == 49)
					{
				
						cout << endl << "�� ������� ��������. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
						if (_getch() == 121)
						{
							yn = true;
						}
					}
					if (th == 50)
					{
						cout << endl << "�� ������� ����������. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
						if (_getch() == 121)
						{
							yn = true;
						}
					}
					if (th == 51)
					{
						cout << endl << "�� ������� ���������. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
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
			cout << "�� �������: '������ �� �������� ���������'" << endl;
			setcolor(15, 0);
			do
			{
				do
				{
					setcolor(14, 0);
					cout << endl << "�������� ��������: " << endl;
					setcolor(15, 0);
					cout << "1. �������� � ����������� ���������!" << endl << "2. ��������� ��������� ���������!" << endl << "3. ����� ������ � ��������: " <<endl<< "-�� ���� �����" << endl << "-�� ���������� ����" << endl << "-������ �������� ����" << endl << "-������ ������� ����" << endl << "4. ����������(�� ���������� �������)!" << endl << "5. ���������� �� �������:" << endl << "-�� ������������ ����" << endl << "-�� ��������� �����" << endl << "-�� �������� �����" << endl;
					th = _getch();
					if (th == 49)
					{
						
							cout << endl << "�� ������� �������� � ����������� ���������! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
					
						if (_getch() == 121)
						{
							y = true;
						}
					
					}
					if (th ==50)
					{
						cout << endl << " �� ������� ��������� ��������� ���������! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
						if (_getch() == 121)
						{
							y = true;
						}
					}
					if (th == 51)
					{
						cout << endl << "�� ������� ����� ������ ��������� � ��������! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
						if (_getch() == 121)
						{
							int temp;
							do 
							{
								cout <<endl<< "1. �� ���� �����" << endl << "2. �� ���������� ����" << endl << "3. ������ �������� ����" << endl << "4. ������ ������� ����" << endl;
								
								
								temp = _getch();
								if (temp == 49) 
								{
									cout << endl << "�� ������� ����� ������ ��������� � �������� �� ���� �����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp == 50)
								{
									cout << endl << "�� ������� ����� ������ ��������� � �������� �� ���������� ����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp == 51)
								{
									cout << endl << "�� ������� ����� ������ ��������� � �������� �� ��������� �����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp == 52)
								{
									cout << endl << "�� ������� ����� �������� �����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
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
						cout << endl << "�� ������� ���������� �� ���������� �������! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
						if (_getch() == 121)
						{
							y = true;
						}
					}
					if (th == 53)
					{
						cout << endl << "�� ������� ���������� �� �������! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
						if (_getch() == 121)
						{
							int temp1;
							do 
							{
								cout << "1. �� ������������ ����!" << endl << "2. �� ��������� �����" << endl << "3. �� �������� �����!" << endl;


							 temp1 = _getch();
								if (temp1 == 49)
								{
									cout << endl << "�� ������� ����� ������ ��������� � �������� �� ���� �����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp1 == 50)
								{
									cout << endl << "�� ������� ����� ������ ��������� � �������� �� ���������� ����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
									if (_getch() == 121)
									{
										y = true;
									}
								}
								if (temp1 == 51)
								{
									cout << endl << "�� ������� ����� ������ ��������� � �������� �� ��������� �����! ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
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
