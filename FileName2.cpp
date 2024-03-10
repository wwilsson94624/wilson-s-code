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
	cout << "請選擇模式(1-自訂義、2-簡單、3-普通、4-困難)";
	cin >> mode;
	if (mode == 1)
	{

		cout << "輸入X*Y場地大小，地雷數";
		cin >> X >> Y >> num;
		for (int i = 0; i < num; i++) {
			cout << "輸入第" << i + 1 << "個地雷座標(x,y)";
			cin >> x[i] >> y[i];
			xy[y[i]][x[i]] = 10;
		}//輸入地雷
	}
	else if (mode == 2)
	{
		X = 9;
		Y = 9;
		num = 10;
		for (int i = 0; i < num; i++) {
			x[i] = rand() % 9 + 1;
			y[i] = rand() % 9 + 1;//不能有(0,0)，最大(9,9)
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
			y[i] = rand() % 16 + 1;//不能有(0,0)，最大(16,16)
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
			y[i] = rand() % 16 + 1;//不能有(0,0)，最大(30,16)
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
	}//將地雷九宮格標記

	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			cout << " |";
		}
		cout << "\n";
	}//輸出空白地圖

	cout << "輸入動作:(1-pick, 2-hammer, 3-flag, 4-endgame)";
	while (cin >> command) {
		if (command == 1)
		{
			cout << "輸入座標:";
			cin >> b >> a;
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if ((i == a && j == b) && xy[i][j] < 20)//(a,b)那格
					{
						if (xy[i][j] >= 10) {
							cout << "*|";//地雷
							xy[i][j] = -xy[i][j];//標記已挖過
						}
						else if (xy[i][j] == 0) {
							cout << xy[i][j] << "|";
							xy[i][j] = 9;//標記已挖過的0，因為0沒有負數故用9作替代
						}
						else if (xy[i][j] == 9)
							cout << xy[i][j] - 9 << "|";//怕重複挖
						else if (xy[i][j] < 0)
							cout << -xy[i][j] << "|";//怕重複挖
						else {
							cout << xy[i][j] << "|";
							xy[i][j] = -xy[i][j];//標記已挖過
						}
					}
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//顯示已挖過
					else if (xy[i][j] <= -10)
						cout << "*|";//顯示已挖過的*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//顯示已挖過的0
					else if (xy[i][j] >= 20)
						cout << "F|";//旗子
					else
						cout << " |";
				}
				cout << "\n";
			}//輸出地圖
		}
		else if (command == 2)
		{
			cout << "輸入座標:";
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
							cout << "*|";//地雷
							xy[i][j] = -xy[i][j];//標記已挖過
						}
						else if (xy[i][j] == 0) {
							cout << xy[i][j] << "|";
							xy[i][j] = 9;//標記已挖過的0，因為0沒有負數故用9作替代
						}
						else if (xy[i][j] == 9)
							cout << xy[i][j] - 9 << "|";//怕重複挖
						else if (xy[i][j] < 0)
							cout << -xy[i][j] << "|";//怕重複挖
						else {
							cout << xy[i][j] << "|";
							xy[i][j] = -xy[i][j];//標記已挖過
						}
					}
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//顯示已挖過
					else if (xy[i][j] <= -10)
						cout << "*|";//顯示已挖過的*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//顯示已挖過的0
					else if (xy[i][j] >= 20)
						cout << "F|";//旗子
					else
						cout << " |";
				}
				cout << "\n";
			}//輸出地圖
		}
		else if (command == 3)
		{
			cout << "輸入座標:";
			cin >> b >> a;
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if (i == a && j == b)//(a,b)那格
					{
						if (xy[i][j] >= 20)
						{
							cout << " |";
							xy[i][j] -= 20;//拔旗子
						}
						else
						{
							cout << "F|";
							xy[i][j] += 20;//下旗子
						}
					}
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//顯示已挖過
					else if (xy[i][j] <= -10)
						cout << "*|";//顯示已挖過的*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//顯示已挖過的0
					else if (xy[i][j] >= 20)
						cout << "F|";//旗子
					else
						cout << " |";
				}
				cout << "\n";
			}//輸出地圖
		}
		else if (command == 4) {
			for (int i = 1; i <= X; i++)
			{
				for (int j = 1; j <= Y; j++)
				{
					if ((xy[i][j] >= 10 && (xy[i][j] < 20)) || xy[i][j] == -10 || xy[i][j] >= 30)
						cout << "*|";//地雷
					else if ((xy[i][j] < 0) && (xy[i][j] > -10))
						cout << -xy[i][j] << "|";//顯示已挖過
					else if (xy[i][j] <= -10)
						cout << "*|";//顯示已挖過的*
					else if (xy[i][j] == 9)
						cout << xy[i][j] - 9 << "|";//顯示已挖過的0
					else if (xy[i][j] >= 20)
						cout << "F|";//旗子
					else if (xy[i][j] == 0)
						cout << " |";
					else
						cout << xy[i][j] << "|";
				}
				cout << "\n";
			}//輸出終局地圖
			return 0;
		}
		cout << "輸入動作:(1-pick, 2-hammer, 3-flag, 4-endgame)";
	}
}