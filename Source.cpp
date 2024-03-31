//Roll Numbers: 22L-6580, 22L_6967
#include <iostream>
#include <windows.h>
#include <conio.h>
#include<thread>
#include "Header.h";
#include <time.h>
using namespace std;
bool tri(int a)
{
	if (a == 4 || a == 9 || a == 14)
		return true;
	return false;
}
bool rec(int a)
{
	if (a == 0 || a == 5 || a == 10)
		return true;
	return false;
}
bool circ(int a)
{
	if (a == 1 || a == 6 || a == 11)
		return true;
	return false;
}
bool dia(int a)
{
	if (a == 2 || a == 7 || a == 12)
		return true;
	return false;
}
bool hex(int a)
{
	if (a == 3 || a == 8 || a == 13)
		return true;
	return false;
}
void create(int a[8][8])
{
	myRectangle(0, 0, 1000, 1000, 0, 0, 0);
	int x = 50, y = 50, x2 = 90, y2 = 90;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 0)
				myRectangle(x, y, x2, y2, 143, 255, 0);
			else if (a[i][j] == 1)
				myEllipse(x, y, x2, y2, 0, 255, 255);
			else if (a[i][j] == 2)
				Diamond(x, y + 20);
			else if (a[i][j] == 3)
				Hexagon(x - 1, y + 10);
			else if (a[i][j] == 4)
				Triangle(x, y + 10);
			else if (a[i][j] == 5)
				myFlame1(x, y, x2, y2);
			else if (a[i][j] == 6)
				myFlame2(x, y, x2, y2);
			else if (a[i][j] == 7)
				myFlame4(x, y + 20);
			else if (a[i][j] == 8)
				myFlame3(x - 1, y + 10);
			else if (a[i][j] == 9)
				myFlame5(x, y + 10);
			else if (a[i][j] == 10)
				myds1(x, y, x2, y2);
			else if (a[i][j] == 11)
				myds2(x, y, x2, y2);
			else if (a[i][j] == 12)
				myds4(x, y + 20);
			else if (a[i][j] == 13)
				myds3(x - 1, y + 10);
			else if (a[i][j] == 14)
				myds5(x, y + 10);
			x += 50; x2 += 50;
		}
		x = 50; x2 = 90;
		y += 50; y2 += 50;
	}
}
void explodeflame(int a[8][8], int& points, int i, int j);
void explodedestroyer(int a[8][8], int& points, int i, int j);
void elbow(int a[8][8], int& points)
{
	bool tr, he, di, re, ci, totcheck1, totcheck2, totcheck3, totcheck4;
	tr = tri(a[0][0]) && tri(a[0][1]) && tri(a[0][2]) && tri(a[1][0]) && tri(a[2][0]);
	he = hex(a[0][0]) && hex(a[0][1]) && hex(a[0][2]) && hex(a[1][0]) && hex(a[2][0]);
	di = dia(a[0][0]) && dia(a[0][1]) && dia(a[0][2]) && dia(a[1][0]) && dia(a[2][0]);
	re = rec(a[0][0]) && rec(a[0][1]) && rec(a[0][2]) && rec(a[1][0]) && rec(a[2][0]);
	ci = circ(a[0][0]) && circ(a[0][1]) && circ(a[0][2]) && circ(a[1][0]) && circ(a[2][0]);
	totcheck1 = tr || he || di || re || ci;
	if (totcheck1)
	{

		if (a[2][0] > 4 && a[2][0] < 10)
			a[2][0] += 5;
		else if (a[2][0] > 9)
			a[2][0] += 0;
		else
			a[2][7] += 10;
		a[0][1] = rand() % 5;
		a[0][2] = rand() % 5;
		a[0][0] = rand() % 5;
		a[1][0] = rand() % 5;
		points += 250;
		system("cls");
		create(a);
	}
	tr = tri(a[2][7]) && tri(a[0][7]) && tri(a[0][5]) && tri(a[0][6]) && tri(a[1][7]);
	he = hex(a[2][7]) && hex(a[0][7]) && hex(a[0][5]) && hex(a[0][6]) && hex(a[1][7]);
	di = dia(a[2][7]) && dia(a[0][7]) && dia(a[0][5]) && dia(a[0][6]) && dia(a[1][7]);
	re = rec(a[2][7]) && rec(a[0][7]) && rec(a[0][5]) && rec(a[0][6]) && rec(a[1][7]);
	ci = circ(a[2][7]) && circ(a[0][7]) && circ(a[0][5]) && circ(a[0][6]) && circ(a[1][7]);
	totcheck2 = tr || he || di || re || ci;
	if (totcheck2)
	{

		if (a[2][7] > 4 && a[2][7] < 10)
			a[2][7] += 5;
		else if (a[2][7] > 9)
			a[2][7] += 0;
		else
			a[2][7] += 10;
		a[0][7] = rand() % 5;
		a[0][5] = rand() % 5;
		a[0][6] = rand() % 5;
		a[1][7] = rand() % 5;
		points += 250;
		system("cls");
		create(a);
	}
	tr = tri(a[7][0]) && tri(a[5][0]) && tri(a[6][0]) && tri(a[7][1]) && tri(a[7][2]);
	he = hex(a[7][0]) && hex(a[5][0]) && hex(a[6][0]) && hex(a[7][1]) && hex(a[7][2]);
	di = dia(a[7][0]) && dia(a[5][0]) && dia(a[6][0]) && dia(a[7][1]) && dia(a[7][2]);
	re = rec(a[7][0]) && rec(a[5][0]) && rec(a[6][0]) && rec(a[7][1]) && rec(a[7][2]);
	ci = circ(a[7][0]) && circ(a[5][0]) && circ(a[6][0]) && circ(a[7][1]) && circ(a[7][2]);
	totcheck3 = tr || he || di || re || ci;
	if (totcheck3)
	{

		for (int i = 7; i > 2; i--)
		{
			a[i][0] = a[i - 3][0];
		}
		for (int i = 7; i > 0; i--)
		{
			a[i][1] = a[i - 1][1];
		}
		for (int i = 7; i > 0; i--)
		{
			a[i][2] = a[i - 1][2];
		}
		if (a[7][0] > 4 && a[7][0] < 10)
			a[7][0] += 5;
		else if (a[7][0] > 9)
			a[7][0] += 0;
		else
			a[7][0] += 10;

		points += 250;
		system("cls");
		create(a);
	}
	tr = tri(a[7][7]) && tri(a[7][6]) && tri(a[7][5]) && tri(a[6][7]) && tri(a[5][7]);
	he = hex(a[7][7]) && hex(a[7][6]) && hex(a[7][5]) && hex(a[6][7]) && hex(a[5][7]);
	di = dia(a[7][7]) && dia(a[7][6]) && dia(a[7][5]) && dia(a[6][7]) && dia(a[5][7]);
	re = rec(a[7][7]) && rec(a[7][6]) && rec(a[7][5]) && rec(a[6][7]) && rec(a[5][7]);
	ci = circ(a[7][7]) && circ(a[7][6]) && circ(a[7][5]) && circ(a[6][7]) && circ(a[5][7]);
	totcheck4 = tr || he || di || re || ci;
	if (totcheck4)
	{
		for (int i = 7; i > 2; i--)
		{
			a[i][7] = a[i - 3][7];
		}
		for (int i = 7; i > 0; i--)
		{
			a[i][6] = a[i - 1][6];
		}
		for (int i = 7; i > 0; i--)
		{
			a[i][5] = a[i - 1][5];
		}
		if (a[7][7] > 4 && a[7][7] < 10)
			a[7][7] += 5;
		else if (a[7][0] > 9)
			a[7][7] += 0;
		else
			a[7][7] += 10;
		points += 250;
		system("cls");
		create(a);
	}

	gotoxy(0, 0);
	cout << "Points : " << points;
}
void explodedestroyer(int a[8][8], int& points, int i, int j)
{
	a[i][j] = rand() % 5;
	points += 800;
	for (int k = i; k > 0; k--)
	{
		for (int l = 0; l < 8; l++)
		{
			if (a[k][l] > 4 && a[k][l] < 10)
				explodeflame(a, points, k, l);
			else if (a[k][l] > 9)
				explodedestroyer(a, points, k, l);
			else
				a[k][l] = a[k - 1][l];
		}
	}
	for (int k = 0; k < 8; k++)
	{
		a[0][k] = rand() % 5;
	}
	for (int k = 0; k < 8; k++)
	{
		if (a[k][j] > 4 && a[k][j] < 10)
			explodeflame(a, points, k, j);
		else if (a[k][j] > 9)
			explodedestroyer(a, points, k, j);
		else
			a[k][j] = rand() % 5;
	}
	system("cls");
	create(a);
	gotoxy(0, 0);
	cout << "Points : " << points;
}
void explodeflame(int a[8][8], int& points, int i, int j)
{
	a[i][j] = rand() % 5;
	points += 450;
	for (int k = i + 1; k > 2; k--)
	{
		for (int l = j - 1; l < (j + 2); l++)
		{
			if (a[k][l] > 4 && a[k][l] < 10)
				explodeflame(a, points, k, l);
			else if (a[k][l] > 9)
				explodedestroyer(a, points, k, l);
			a[k][l] = a[k - 3][l];
		}
	}
	for (int c = 0; c < 3; c++)
	{
		for (int l = (j - 1); l < (j + 2); l++)
		{
			a[c][l] = rand() % 5;
		}
	}
	system("cls");
	create(a);
	gotoxy(0, 0);
	cout << "Points : " << points;
}
void check43(int a[8][8], int& points)
{
	bool totcheck, tr, di, re, ci, he;
	int check = points, b = 1, c = 1, flagh = 0, flagv = 0;
	while ((b == 1) || (c == 1))
	{
		b = 0; c = 0; flagh = 0; flagv = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				tr = tri(a[i][j]) && tri(a[i][j + 1]) && tri(a[i][j + 2]);
				di = dia(a[i][j]) && dia(a[i][j + 1]) && dia(a[i][j + 2]);
				re = rec(a[i][j]) && rec(a[i][j + 1]) && rec(a[i][j + 2]);
				ci = circ(a[i][j]) && circ(a[i][j + 1]) && circ(a[i][j + 2]);
				he = hex(a[i][j]) && hex(a[i][j + 1]) && hex(a[i][j + 2]);
				totcheck = tr || di || re || ci || he;
				if (totcheck)
				{
					c = 1;
					for (int k = j; k < (j + 3); k++)
					{
						if (a[i][k] > 9)
						{
							flagv = 1;
							explodedestroyer(a, points, i, k);
						}
					}//check for destroyer
					if (flagv == 0)
					{
						for (int k = j; k < (j + 3); k++)
						{
							if (a[i][k] > 4 && a[i][k] < 9)
							{
								flagv = 1;
								explodeflame(a, points, i, k);
							}
						}
					}//check for flame
					if (flagv == 0)
					{
						for (int k = i; k > 0; k--)
						{
							for (int l = j; l < (j + 3); l++)
								a[k][l] = a[k - 1][l];
						}
						a[0][j] = rand() % 5;
						a[0][j + 1] = rand() % 5;
						a[0][j + 2] = rand() % 5;
						system("cls");
						create(a);
						points += 150;
						gotoxy(0, 0);
						cout << "Points : " << points;
					}
				}// if three horizontal consecutive
			}
		}//end of horizontal check

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				tr = tri(a[i][j]) && tri(a[i + 1][j]) && tri(a[i + 2][j]);
				di = dia(a[i][j]) && dia(a[i + 1][j]) && dia(a[i + 2][j]);
				re = rec(a[i][j]) && rec(a[i + 1][j]) && rec(a[i + 2][j]);
				ci = circ(a[i][j]) && circ(a[i + 1][j]) && circ(a[i + 2][j]);
				he = hex(a[i][j]) && hex(a[i + 1][j]) && hex(a[i + 2][j]);
				totcheck = tr || di || re || ci || he;
				if (totcheck)
				{
					b = 1;
					for (int k = i; k < (i + 3); k++)
					{
						if (a[k][j] > 9)
						{
							flagh = 1;
							explodedestroyer(a, points, k, j);
						}
					}//check destroyer
					if (flagh == 0)
					{
						for (int k = i; k < (i + 3); k++)
						{
							if (a[k][j] > 4 && a[k][j] < 9)
							{
								flagh = 1;
								explodeflame(a, points, k, j);
							}
						}
					}//check flame
					if (flagh == 0)
					{
						for (int k = i; k > 0; k--)
						{
							a[k + 2][j] = a[k - 1][j];
						}
						a[0][j] = rand() % 5;
						a[1][j] = rand() % 5;
						a[2][j] = rand() % 5;
						system("cls");
						create(a);
						points += 150;
						gotoxy(0, 0);
						cout << "Points : " << points;
					}
				}
			}
		}//end of vertical check
	}//end of check again check
}
void check44(int a[8][8], int& points)
{
	bool totcheck, tr, di, re, ci, he;
	int check = points, b = 1, c = 1, flagh = 0, flagv = 0;
	while ((b == 1) || (c == 1))
	{
		b = 0; c = 0; flagh = 0; flagv = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				tr = tri(a[i][j]) && tri(a[i][j + 1]) && tri(a[i][j + 2]) && tri(a[i][j + 3]);
				di = dia(a[i][j]) && dia(a[i][j + 1]) && dia(a[i][j + 2]) && dia(a[i][j + 3]);
				re = rec(a[i][j]) && rec(a[i][j + 1]) && rec(a[i][j + 2]) && rec(a[i][j + 3]);
				ci = circ(a[i][j]) && circ(a[i][j + 1]) && circ(a[i][j + 2]) && circ(a[i][j + 3]);
				he = hex(a[i][j]) && hex(a[i][j + 1]) && hex(a[i][j + 2]) && hex(a[i][j + 3]);
				totcheck = tr || di || re || ci || he;
				if (totcheck)
				{
					c = 1;
					for (int k = j; k <= (j + 3); k++)
					{
						if (a[i][k] > 9)
						{
							flagv = 1;
							explodedestroyer(a, points, i, k);
						}
					}//check for destroyer
					if (flagv == 0)
					{
						for (int k = j; k <= (j + 3); k++)
						{
							if (a[i][k] > 4 && a[i][k] < 10)
							{
								flagv = 1;
								explodeflame(a, points, i, k);
							}
						}
					}//check for flame
					if (flagv == 0)
					{
						for (int k = i; k > 0; k--)
						{
							for (int l = j; l <= (j + 3); l++)
							{
								if (l != (j + 2))
									a[k][l] = a[k - 1][l];
							}
						}
						a[i][j + 2] = a[i][j + 2] + 5;
						cout << a[i][j + 2];
						Sleep(50);
						a[0][j] = rand() % 5;
						a[0][j + 1] = rand() % 5;
						a[0][j + 3] = rand() % 5;
						system("cls");
						create(a);
						points += 200;
						gotoxy(0, 0);
						cout << "Points : " << points;
					}
				}// if three horizontal consecutive
			}
		}//end of horizontal check

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				tr = tri(a[i][j]) && tri(a[i + 1][j]) && tri(a[i + 2][j]) && tri(a[i + 3][j]);
				di = dia(a[i][j]) && dia(a[i + 1][j]) && dia(a[i + 2][j]) && dia(a[i + 3][j]);
				re = rec(a[i][j]) && rec(a[i + 1][j]) && rec(a[i + 2][j]) && rec(a[i + 3][j]);
				ci = circ(a[i][j]) && circ(a[i + 1][j]) && circ(a[i + 2][j]) && circ(a[i + 3][j]);
				he = hex(a[i][j]) && hex(a[i + 1][j]) && hex(a[i + 2][j]) && hex(a[i + 3][j]);
				totcheck = tr || di || re || ci || he;
				if (totcheck)
				{
					b = 1;
					for (int k = i; k <= (i + 3); k++)
					{
						if (a[k][j] > 9)
						{
							flagh = 1;
							explodedestroyer(a, points, k, j);
						}
					}//check destroyer
					if (flagh == 0)
					{
						for (int k = i; k <= (i + 3); k++)
						{
							if (a[k][j] > 4 && a[k][j] < 10)
							{
								flagh = 1;
								explodeflame(a, points, k, j);
							}
						}
					}//check flame
					if (flagh == 0)
					{
						for (int k = i; k > 0; k--)
						{
							a[k + 2][j] = a[k - 1][j];
						}
						a[i + 3][j] = a[i + 3][j] + 5;
						cout << a[i + 3][j];
						Sleep(50);
						a[0][j] = rand() % 5;
						a[1][j] = rand() % 5;
						a[2][j] = rand() % 5;
						system("cls");
						create(a);
						points += 200;
						gotoxy(0, 0);
						cout << "Points : " << points;
					}
				}
			}
		}//end of vertical check
	}//end of check again check
}
void swapi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void populate(int a[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = rand() % 5;
		}
	}
}
void usercontrol(int a[8][8], int& points)
{
	int b = 0, check = 0, row = 0, col = 0, cx = 50, cy = 50, x = 48, x2
		= 92, y = 48, y2 = 92;
	int c = points;
	while (check == 0) {
		check = 0;
		Sleep(50);
		myhrec(x, y, x2 - 44, y2 - 1, 255, 0, 0);
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (x2 + 50 - 44 <= 398) {
				myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
				x += 50; x2 += 50;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			if (x - 50 >= 48) {
				myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
				x -= 50; x2 -= 50;
			}
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			if (y - 50 >= 48) {
				myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
				y -= 50; y2 -= 50;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (y2 - 1 + 50 <= 442) {
				myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
				y += 50; y2 += 50;
			}
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			while (check == 0) {
				b = 0;
				myhrec(x, y, x2 - 44, y2 - 1, 0, 255, 0);
				for (int i = 0; (i < 8) && b < 1; i++)
				{
					if (x == cx - 2)
					{
						b = 1;
					}
					else {
						cx = cx + 50;
						col++;
					}
				}
				b = 0;
				for (int i = 0; (i < 8) && b < 1; i++)
				{
					if (y == cy - 2) {
						b = 1;
					}
					else {
						cy += 50;
						row++;
					}
				}
				if (GetAsyncKeyState(VK_RIGHT))
				{
					swapi(a[row][col], a[row][col + 1]);
					elbow(a, points);
					check44(a, points);
					check43(a, points);
					if (c == points)
					{
						swapi(a[row][col], a[row][col + 1]);
					}
					myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
					check = 1;
					Sleep(500);
				}
				else if (GetAsyncKeyState(VK_LEFT))
				{
					swapi(a[row][col], a[row][col - 1]);
					elbow(a, points);
					check44(a, points);
					check43(a, points);
					if (c == points)
					{
						swapi(a[row][col], a[row][col - 1]);
					}
					myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
					check = 1;
					Sleep(500);
				}
				else if (GetAsyncKeyState(VK_UP))
				{
					swapi(a[row][col], a[row - 1][col]);
					elbow(a, points);
					check44(a, points);
					check43(a, points);
					if (c == points)
					{
						swapi(a[row][col], a[row - 1][col]);
					}
					myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
					check = 1;
					Sleep(500);
				}
				else if (GetAsyncKeyState(VK_DOWN))
				{
					swapi(a[row][col], a[row + 1][col]);
					elbow(a, points);
					check44(a, points);
					check43(a, points);
					if (c == points)
					{
						swapi(a[row][col], a[row + 1][col]);
					}
					myhrec(x, y, x2 - 44, y2 - 1, 0, 0, 0);
					check = 1;
					Sleep(500);
				}
			}
		}
	}
}
int main()
{
	int a[8][8], points = 0;
	populate(a);
	create(a);
	elbow(a, points);
	check44(a, points);
	check43(a, points);
	time_t oldTime = time(0);
	while (time(0) - oldTime <= 60)
	{
		usercontrol(a, points);
	}
	system("cls");
	cout << "GAME OVER!\nYour points : " << points << endl;
	system("pause");
}