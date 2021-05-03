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
	cout << "��� ������������ ������� ������������ �� ����� '����������������'! ������ ����� ��������!" << endl;
	cout << "��� ������� ������������� � �������!" << endl;
	setcolor(15,0);
	string log, pas;
	bool check = false;
	while (log != "silkin" || pas != "silkin")
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
		if (log == "silkin" && pas == "silkin")
		{
			check = true;	
		}
		if (log != "silkin" || pas != "silkin")
		{
			setcolor(4,0);
			cout << endl << "�������� ����� ��� ������!" << endl;
			setcolor(15,0);
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
				cout << endl << "�������� ����� ������������:"  << endl;
				setcolor(15,0);
				cout << "1. ������� �� ����" << endl << "2. ������������ �� ����" << endl << "3. �������� ����" << endl << "������ - ��������� �������" << endl << "Esc - ����� �� ���������" << endl;
				kl = _getch();
				if (kl == 49)
				{
					setcolor(14,0);
					cout << endl << "�� ������� �����: '������� �� ����'" << endl;
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
					cout << "�� ������� �����: '������������ �� ����'" << endl;
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
				if (kl == 51)
				{
					setcolor(14,0);
					cout << endl << "�� ������� �����: '�������� ����'" << endl;
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
			while (ex == false );
			if (kl != 49 && kl != 50 && kl != 51 && kl != 27 && kl != 32)
				{
					setcolor(4,0);
					cout << endl << "������ ������! ���������� �����!" << endl;
					setcolor(15,0);
				}
			if (kl == 32)
			{
					system("cls");
					string s;
					setcolor(14,0);
					cout << "�������: " << endl;
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
	                cout << "��� ����������� ������� ����� ������!" << endl;
	                _getch();
			}
		}
		while (kl != 49 && kl != 50 && kl != 51 && kl != 27);
		switch (kl)
		{
			case 27: //�����
			{
				setcolor(14,0);
				cout << endl << "����������� ����� �� ������� ������������! �� ��������!" << endl;	
				setcolor(15,0);
				Sleep(2000);
				exit(0);
			}
			break;
			case 49: // 1 ����
			{
				int th = 0; //�������� ��� �������
				bool yn;
				system("cls");
				setcolor(14,0);
				cout << "�� �������: '������� �� ����'" << endl;
				setcolor(15,0);
				do
				{
					do
					{
						cout << endl << "�������� ����: " << endl;
						th = _getch();
						if (th == 49)
						{
							cout << endl << "�� ������� 1 ����. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
							if (_getch() == 121);
							{
								yn = true;
							}
						}
						if (th == 50)
						{
							cout << endl << "�� ������� 2 ����. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th == 51)
						{
							cout << endl << "�� ������� 3 ����. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th != 49 && th != 50 && th != 51)
						{
							setcolor(4,0);
							cout << endl << "������ ������! ���������� �����!" << endl;
							setcolor(15,0);
						}
					}
					while (yn == false);
				}
				while (th != 49 && th != 50 && th != 51);
				cout << "������ �����! ��� ������ ������������ ������� �� ����� ������" << endl;
				_getch();
				system("cls");
			}
			break;
			case 50: 
			{
				int th; //�������� ��� �������
				bool yn;
				system("cls");
				setcolor(14,0);
				cout << "�� �������: '������������ �� ����'" << endl;
				setcolor(15,0);
				do
				{
					do
					{
						cout << endl << "�������� ����: " << endl;
						th = _getch();
						if (th == 49)
						{
							cout << endl << "�� ������� 1 ����. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;
							if (_getch() == 121);
							{
								yn = true;
							}
						}
						if (th == 50)
						{
							cout << endl << "�� ������� 2 ����. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th == 51)
						{
							cout << endl << "�� ������� 3 ����. ����� ����������� ����� ������� 'Y', ��� ������ ������ ���� ������� ����� ������?" << endl;;
							if (_getch() == 121)
							{
								yn = true;
							}
						}
						if (th != 49 && th != 50 && th != 51)
						{
							setcolor(4,0);
							cout << endl << "������ ������! ���������� �����!" << endl;
							setcolor(15,0);
						}
					}
					while (yn == false);
				}
				while (th != 49 && th != 50 && th != 51);
				cout << "������ �����! ��� ������ ������������ ������� �� ����� ������" << endl;
				_getch();
				system("cls");	
			}
			break;
			case 51:
			{
				system("cls");
				setcolor(14,0);
				cout << "�� �������: '�������� ����'" << endl;
				setcolor(15,0);
				cout << "������ �����! ��� ������ ������������ ������� �� ����� ������" << endl;
				_getch();
				system("cls");
			}
			break;
		}
	}
}
