#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main() {
	int X, Y, num, a, b;
	int x[100], y[100];
	int xy[100][100] = { 0 };
	int command, mode;
	srand(time(NULL));
	cout << "�п�ܼҦ�(1-�ۭq�q�B2-²��B3-���q�B4-�x��)";
	cin >> mode;
	if (mode == 1)
	{

		cout << "��JX*Y���a�j�p�A�a�p��";
		cin >> X >> Y >> num;
		for (int i = 0; i < num; i++) {
			cout << "��J��" << i + 1 << "�Ӧa�p�y��(x,y)";
			cin >> x[i] >> y[i];
			xy[y[i]][x[i]] = 10;
		}//��J�a�p
	}
	else if (mode == 2)
	{
		X = 9;
		Y = 9;
		num = 10;
		for (int i = 0; i < num; i++) {
			x[i] = rand() % 9 + 1;
			y[i] = rand() % 9 + 1;//���঳(0,0)�A�̤j(9,9)
			xy[y[i]][x[i]] = 10;
		}
	}
	else if (mode == 3)
	{
		X = 16;
		Y = 16;
		num = 40;
		for (int i = 0; i < num; i++) {
			x[i] = rand() % 16 + 1;
			y[i] = rand() % 16 + 1;//���঳(0,0)�A�̤j(16,16)
			xy[y[i]][x[i]] = 10;
		}
	}
	else if (mode == 4)
	{
		X = 16;
		Y = 30;
		num = 99;
		for (int i = 0; i < num; i++) {
			x[i] = rand() % 30 + 1;
			y[i] = rand() % 16 + 1;//���঳(0,0)�A�̤j(30,16)
			xy[y[i]][x[i]] = 10;
		}
	}

	for (int i = 0; i < num; i++)
	{
		xy[y[i] - 1][x[i] - 1]++;
		xy[y[i] - 1][x[i]]++;
		xy[y[i] - 1][x[i] + 1]++;
		xy[y[i]][x[i] - 1]++;
		xy[y[i]][x[i] + 1]++;
		xy[y[i] + 1][x[i] - 1]++;
		xy[y[i] + 1][x[i]]++;
		xy[y[i] + 1][x[i] + 1]++;
	}//�N�a�p�E�c��аO

	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			cout << " |";
		}
		cout << "\n";
	}//��X�ťզa��

	cout << "��J�ʧ@:(1-pick, 2-hammer, 3-flag, 4-endgame)";
	while (cin >> command) {
		if (command == 1)
		{
			cout << "��J�y��:";
			cin >> b >> a;
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if ((i == a && j == b) && xy[i][j] < 20)//(a,b)����
					{
						if (xy[i][j] >= 10) {
							cout << "*|";//�a�p
							xy[i][j] = -xy[i][j];//�аO�w���L
						}
						else if (xy[i][j] == 0) {
							cout << xy[i][j] << "|";
							xy[i][j] = 9;//�аO�w���L��0�A�]��0�S���t�ƬG��9�@���N
						}
						else if (xy[i][j] == 9)
							cout << xy[i][j] - 9 << "|";//�ȭ��ƫ�
						else if (xy[i][j] < 0)
							cout << -xy[i][j] << "|";//�ȭ��ƫ�
						else {
							cout << xy[i][j] << "|";
							xy[i][j] = -xy[i][j];//�аO�w���L
						}
					}
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//��ܤw���L
					else if (xy[i][j] <= -10)
						cout << "*|";//��ܤw���L��*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//��ܤw���L��0
					else if (xy[i][j] >= 20)
						cout << "F|";//�X�l
					else
						cout << " |";
				}
				cout << "\n";
			}//��X�a��
		}
		else if (command == 2)
		{
			cout << "��J�y��:";
			cin >> b >> a;
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if (((i == a - 1 && j == b - 1) || (i == a && j == b - 1) || (i == a + 1 && j == b - 1) ||
						(i == a - 1 && j == b) || (i == a && j == b) || (i == a + 1 && j == b) ||
						(i == a - 1 && j == b + 1) || (i == a && j == b + 1) || (i == a + 1 && j == b + 1)) && xy[i][j] < 20)
					{
						if (xy[i][j] >= 10) {
							cout << "*|";//�a�p
							xy[i][j] = -xy[i][j];//�аO�w���L
						}
						else if (xy[i][j] == 0) {
							cout << xy[i][j] << "|";
							xy[i][j] = 9;//�аO�w���L��0�A�]��0�S���t�ƬG��9�@���N
						}
						else if (xy[i][j] == 9)
							cout << xy[i][j] - 9 << "|";//�ȭ��ƫ�
						else if (xy[i][j] < 0)
							cout << -xy[i][j] << "|";//�ȭ��ƫ�
						else {
							cout << xy[i][j] << "|";
							xy[i][j] = -xy[i][j];//�аO�w���L
						}
					}
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//��ܤw���L
					else if (xy[i][j] <= -10)
						cout << "*|";//��ܤw���L��*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//��ܤw���L��0
					else if (xy[i][j] >= 20)
						cout << "F|";//�X�l
					else
						cout << " |";
				}
				cout << "\n";
			}//��X�a��
		}
		else if (command == 3)
		{
			cout << "��J�y��:";
			cin >> b >> a;
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if (i == a && j == b)//(a,b)����
					{
						if (xy[i][j] >= 20)
						{
							cout << " |";
							xy[i][j] -= 20;//�޺X�l
						}
						else
						{
							cout << "F|";
							xy[i][j] += 20;//�U�X�l
						}
					}
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//��ܤw���L
					else if (xy[i][j] <= -10)
						cout << "*|";//��ܤw���L��*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//��ܤw���L��0
					else if (xy[i][j] >= 20)
						cout << "F|";//�X�l
					else
						cout << " |";
				}
				cout << "\n";
			}//��X�a��
		}
		else if (command == 4) {
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if ((xy[i][j] >= 10 && (xy[i][j] < 20)) || xy[i][j] == -10 || xy[i][j] >= 30)
						cout << "*|";//�a�p
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//��ܤw���L
					else if (xy[i][j] <= -10)
						cout << "*|";//��ܤw���L��*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//��ܤw���L��0
					else if (xy[i][j] >= 20)
						cout << "F|";//�X�l
					else if (xy[i][j] == 0)
						cout << " |";
					else
						cout << xy[i][j] << "|";
				}
				cout << "\n";
			}//��X�ק��a��
			return 0;
		}
		cout << "��J�ʧ@:(1-pick, 2-hammer, 3-flag, 4-endgame)";
	}
}