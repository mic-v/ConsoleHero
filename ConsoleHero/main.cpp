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
	SetConsoleTitle("Console Rhythm!");
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, 250, 20, 475, 590, TRUE);
	CONSOLE_CURSOR_INFO ci;
	ci.dwSize = 25;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);

	Menu menu;
	menu.loadMenu();
	//menu.gotoxy(20, 0);
	//printf("%10", 1);
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
				Sleep(200);
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
					menu.gotoxy(32, 34);
					printf("ESC to go Back");
					int place = 0;
					int start = 0;
					int end = 7;
					Game g;
					bool moved = false;
					string tmp = "SongPreview/";
					tmp += g.t.list[0];
					tmp += ".wav";
					menu.setSong(tmp);
					while (menu.game)
					{
						if (moved == true)
						{
							string tmp = "SongPreview/";
							tmp += g.t.list[place];
							tmp += ".wav";
							menu.setSong(tmp);
							moved = false;
						}
						for (int i = 0; i < 8; i++)
						{
							menu.gotoxy(6 + 3 * i, 2);
							cout << "                     " << endl;
							cout << "                     "  << endl;
							if (place - start  == i)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
							}
							menu.gotoxy(6 + 3 * i, 2);
							cout << g.t.artist[i + start] << "          " << endl;
							cout << "     " <<g.t.song[i + start] << "         " << endl;
							menu.gotoxy(6 + 3 * i, 22);
							cout << "      " << endl;
							menu.gotoxy(6 + 3 * i, 22);
							if (g.t.listDifficulty[i + start] == 1)
								cout << "EASY" << endl;
							else if(g.t.listDifficulty[i + start] == 2)
								cout << "MEDIUM" << endl;
							else if (g.t.listDifficulty[i + start] == 3)
								cout << "HARD" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
						}
						if (_kbhit())
						{
							if (GetAsyncKeyState(VK_DOWN))
							{
								if (place < 14)
								{
									place++;
									moved = true;
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
							else if (GetAsyncKeyState(VK_ESCAPE))
							{
								menu.game = false;
								system("cls");
								menu.loadMenu();
							}
							else if (GetAsyncKeyState(VK_RETURN))
							{
								PlaySound(NULL, NULL, SND_ASYNC);
								g.t.setTrackNumber(place);
								g.t.setTrack();
								Sleep(500);
								menu.gotoxy(0, 0);
								system("cls");
								g.init();
								g.mainL();
							}
						}
						Sleep(150);
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