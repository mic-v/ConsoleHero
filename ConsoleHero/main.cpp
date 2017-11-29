#include "Game.h"
#include "Menu.h"
#include <iostream>
#include <Windows.h>

#define WIDTH 50
#define HEIGHT 33

using std::cout; using std::endl;

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0,0, WIDTH - 1, HEIGHT - 1 };
	COORD bufferSize = { WIDTH, HEIGHT };
	SetConsoleTitle("Console Rhythm!");
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	GetConsoleCursorInfo(hStdout, &cursorInfo);
	SetConsoleCursorInfo(hStdout, &cursorInfo);

	Menu menu;
	while (menu.menu == true)
	{
		menu.loadMenu();
		if (menu.arrow == 0)
		{
			menu.gotoxy(10, 15);
			printf("->");
			menu.game = true;
			menu.credit = false;
			menu.exit = false;
			menu.tutorial = false;
		}
		else if(menu.arrow == 1)
		{
			menu.gotoxy(15, 15);
			printf("->");
			menu.game = false;
			menu.credit = false;
			menu.exit = false;
			menu.tutorial = true;
		}
		else if (menu.arrow == 2)
		{
			menu.gotoxy(20, 15);
			printf("->");
			menu.game = false;
			menu.credit = true;
			menu.exit = false;
			menu.tutorial = false;
		}
		else if (menu.arrow == 3)
		{
			menu.gotoxy(25, 15);
			printf("->");
			menu.game = false;
			menu.credit = false;
			menu.exit = true;
			menu.tutorial = false;
		}

		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (menu.arrow < 3)
				{
					menu.arrow++;
				}
			}
			else if (GetAsyncKeyState(VK_UP))
			{
				if (menu.arrow > 0)
				{
					menu.arrow--;
				}
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				if (menu.game)
				{

				}
				else if (menu.tutorial)
				{
					system("cls");
					while (menu.tutorial)
					{

					}
				}
				else if (menu.credit)
				{
					system("cls");
					while (menu.credit)
					{

					}
				}
				else if (menu.exit)
				{
					menu.credit = false;
				}
			}
		}
		system("cls");
	}
}