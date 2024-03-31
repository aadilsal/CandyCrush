#pragma once
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void myhrec(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	myLine(x1, y1, x2, y2, R, G, B);
	myLine(x1, y1, x1 + 42, y1, R, G, B);
	myLine(x2, y2, x2 + 42, y2, R, G, B);
	myLine(x2 + 42, y2, x1 + 42, y1, R, G, B);


}


// This function checks if any of the 4 cursor keys are pressed.
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey) //whichKey passed as reference....
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1; // 1 if left key is pressed
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2; // 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4; // 4 if down key is pressed
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myhRectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myFlame2(int x1, int y1, int x2, int y2)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(204, 25, 32));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0)); //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1 - 2, y1 - 2, x2 + 2, y2 - 2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myFlame1(int x1, int y1, int x2, int y2)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(204, 25, 32));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(143, 255, 0)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myFlame3(int x, int y)
{
	myLine(x, y, x + 20, y - 10, 204, 25, 32);
	myLine(x + 20, y - 10, x + 40, y, 204, 25, 32);
	myLine(x, y, x, y + 20, 204, 25, 32);
	myLine(x + 40, y, x + 40, y + 20, 204, 25, 32);
	myLine(x, y + 20, x + 20, y + 30, 204, 25, 32);
	myLine(x + 20, y + 30, x + 40, y + 20, 204, 25, 32);

}
void myFlame4(int x, int y)
{
	myLine(x, y, x + 20, y + 20, 204, 25, 32);
	myLine(x + 40, y, x + 20, y + 20, 204, 25, 32);
	myLine(x, y, x + 20, y - 20, 204, 25, 32);
	myLine(x + 40, y, x + 20, y - 20, 204, 25, 32);
}
void myFlame5(int x, int y)
{
	myLine(x, y, x + 40, y, 204, 25, 32);
	myLine(x, y, x + 20, y + 20, 204, 25, 32);
	myLine(x + 40, y, x + 20, y + 20, 204, 25, 32);
}
void Hexagon(int x, int y)
{

	myLine(x, y, x + 20, y - 10, 255, 0, 0);
	myLine(x + 20, y - 10, x + 40, y, 255, 0, 0);
	myLine(x, y, x, y + 20, 255, 0, 0);
	myLine(x + 40, y, x + 40, y + 20, 255, 0, 0);
	myLine(x, y + 20, x + 20, y + 30, 255, 0, 0);
	myLine(x + 20, y + 30, x + 40, y + 20, 255, 0, 0);
}
void Diamond(int x, int y)
{
	//int x = 300, y = 300;
	myLine(x, y, x + 20, y + 20, 255, 0, 0);
	myLine(x + 40, y, x + 20, y + 20, 255, 150, 0);
	myLine(x, y, x + 20, y - 20, 255, 150, 0);
	myLine(x + 40, y, x + 20, y - 20, 255, 150, 0);
}
void Triangle(int x, int y)
{
	//int x = 150, y = 150;
	myLine(x, y, x + 40, y, 0, 50, 240);
	myLine(x, y, x + 20, y + 20, 0, 60, 240);
	myLine(x + 40, y, x + 20, y + 20, 0, 60, 240);
}
void myds2(int x1, int y1, int x2, int y2)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0)); //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1 - 2, y1 - 2, x2 + 2, y2 - 2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myds1(int x1, int y1, int x2, int y2)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(143, 255, 0)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myds3(int x, int y)
{
	myLine(x, y, x + 20, y - 10, 255, 255, 255);
	myLine(x + 20, y - 10, x + 40, y, 255, 255, 255);
	myLine(x, y, x, y + 20, 255, 255, 255);
	myLine(x + 40, y, x + 40, y + 20, 255, 255, 255);
	myLine(x, y + 20, x + 20, y + 30, 255, 255, 255);
	myLine(x + 20, y + 30, x + 40, y + 20, 255, 255, 255);

}
void myds4(int x, int y)
{
	myLine(x, y, x + 20, y + 20, 255, 255, 255);
	myLine(x + 40, y, x + 20, y + 20, 255, 255, 255);
	myLine(x, y, x + 20, y - 20, 255, 255, 255);
	myLine(x + 40, y, x + 20, y - 20, 255, 255, 255);
}
void myds5(int x, int y)
{
	myLine(x, y, x + 40, y, 255, 255, 255);
	myLine(x, y, x + 20, y + 20, 255, 255, 255);
	myLine(x + 40, y, x + 20, y + 20, 255, 255, 255);
}