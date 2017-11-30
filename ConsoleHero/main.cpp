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
	CONSOLE_CURSOR_INFO ci;
	ci.dwSize = 25;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);

	Menu menu;
	menu.loadMenu();
	while (menu.menu == true)
	{
		if (menu.arrow == 0)
		{
			menu.gotoxy(10, 15);
			printf("->");
			menu.gotoxy(20, 15);
			printf("  ");
			menu.gotoxy(15, 15);
			printf("  ");
			menu.game = true;
			menu.exit = false;
			menu.tutorial = false;
		}
		else if(menu.arrow == 1)
		{
			menu.gotoxy(15, 15);
			printf("->");
			menu.gotoxy(10, 15);
			printf("  ");
			menu.gotoxy(20, 15);
			printf("  ");
			menu.game = false;
			menu.exit = false;
			menu.tutorial = true;
		}
		else if (menu.arrow == 2)
		{
			menu.gotoxy(20, 15);
			printf("->");

			menu.gotoxy(10, 15);
			printf("  ");
			menu.gotoxy(15, 15);
			printf("  ");
			menu.game = false;
			menu.exit = true;
			menu.tutorial = false;
		}

		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (menu.arrow < 2)
					menu.arrow++;
			}
			else if (GetAsyncKeyState(VK_UP))
			{
				if (menu.arrow > 0)
					menu.arrow--;
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				system("cls");
				if (menu.game)
				{
					printf("\n%13s%18s%16s", "Track List", "Difficulty", "Top Score");
					for (int i = 0; i < 33; i++)
					{
						menu.gotoxy( i, 33);
						printf("|");
					}
					for (int i = 0; i < 8; i++)
					{
						menu.gotoxy(6 + i * 3 , 34);
						//printf("%i%c",i + 1,'.');
					}
					int place = 0;
					int start = 0;
					int end = 7;
					Game g;
					while (menu.game)
					{
						for (int i = 0; i < 8; i++)
						{
							menu.gotoxy(6 + 3 * i, 2);
							if (place - start  == i)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
							}
							cout << g.t.artist[i + start] << "          " << endl;
							cout << "     " <<g.t.song[i + start] << "         " << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
						}
						if (_kbhit())
						{
							if (GetAsyncKeyState(VK_DOWN))
							{
								if (place < 14)
								{
									place++;
								}
								if (place > end)
								{
									end++;
									start++;
								}
							}
							else if (GetAsyncKeyState(VK_UP))
							{
								if (place > 0)
								{
									place--;
								}
								if (place < start)
								{
									end--;
									start--;
								}
							}
						}
						Sleep(70);
					}
				}
				else if (menu.tutorial)
				{
					system("cls");
					while (menu.tutorial)
					{

					}
				}
				else if (menu.exit == true)
				{
					menu.menu = false;
				}
			}
		}
		Sleep(100);
	}
}