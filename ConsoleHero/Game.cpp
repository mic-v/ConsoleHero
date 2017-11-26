#include "Game.h"
#include "Track.h"
#include <mmsystem.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int selection = 1;
bool menuRunning = true;
string beatNote1 = " +-----+ ";
string beatNote2 = " |     | ";
string beatNote3 = " +-----+ ";
char part[] = { 'T','T' };
char partMid[] = { '|','|' };
char partBot[] = { 193,193 };


void menu()
{
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	if (selection == 1)
	{
		SetConsoleTextAttribute(text, 11);
		printf("Guitar Hero\n");
		SetConsoleTextAttribute(text, 15);
	}
	else
	{
		printf("Guitar Hero\n");
		
	}

	if (selection == 2)
	{
		SetConsoleTextAttribute(text, 11);
		printf("Exit\n");
		SetConsoleTextAttribute(text, 15);
	}
	else
	{
		printf("Exit");
	}
}

void gotoxy(int x, int y)
{
	COORD Position;

	//X is horizontal, Y is vertical
	Position.X = y;
	Position.Y = x;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

int main() 
{

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, 250, 20, 950, 1000, TRUE); // 800 width, 100 height
	CONSOLE_CURSOR_INFO ci;
	ci.dwSize = 25;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
	//while (menuRunning)
	//{
	//	menu();
	//	Sleep(10);
	//	char a = _getch();
	//	if (a == 72 && selection > 1)//up
	//		selection--;
	//	else if (a == 80 && selection < 2)//down
	//		selection++;
	//	else if (a == 13)
	//	{
	//		if (selection == 1)
	//		{
	//			cout << "xd" << endl;
	//		}
	//		else if (selection == 2)
	//		{
	//			menuRunning = false;
	//			continue;
	//		}
	//	}
	//}

	Game g;
	g.init();
	g.mainL();
	
	system("pause");
}

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	string line;
	
	ifstream myfile("Game2.txt");
	if (myfile.is_open())
	{
		for (int i = 0; getline(myfile, line); i++)
		{
			vector<char> column(line.size());
			boar.push_back(column);
			for (int j = 0; j < line.size(); j++)
			{
				if (line[j] == '~')
					boar[i][j] = ' ';
				else
					boar[i][j] = line[j];
			}
		}
	}
	buffe = boar;
	t.readTrack();
}

void Game::mainL()
{
	//PlaySound(TEXT("Clannad_Ending.wav"), NULL, SND_ASYNC);
	bool loop = true;
	drawAll();
	while (loop == true)
	{
		updateBuffer();
		move();
		//input();
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		selDraw();

	}
}

void Game::input()
{
	if (_kbhit())
	{
		if (GetAsyncKeyState(0x41))
		{
			gotoxy(29, 26);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			//checkHit(t.notes[0]);
			checkHit(t.notes[0]);
		}
		else
		{
			gotoxy(29, 26);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			printf(" ");
		}
		if (GetAsyncKeyState(0x53))
		{
			gotoxy(29, 31);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x99);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			checkHit(t.notes[1]);
		}
		else
		{
			gotoxy(29, 31);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			printf(" ");

		}
		if (GetAsyncKeyState(0x44))
		{
			gotoxy(29, 37);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			checkHit(t.notes[2]);
		}
		else
		{
			gotoxy(29, 37);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			printf(" ");
		}
		if (GetAsyncKeyState(0x46))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xEE);
			gotoxy(29, 42);
			printf(" ");
			gotoxy(29, 43);
			printf(" ");
			gotoxy(30, 42);
			printf(" ");
			gotoxy(30, 43);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			checkHit(t.notes[3]);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			gotoxy(29, 42);
			gotoxy(29, 42);
			printf(" ");
			gotoxy(29, 43);
			printf(" ");
			gotoxy(30, 42);
			printf(" ");
			gotoxy(30, 43);
			printf(" ");
		}
	}
}

void Game::move()
{
	if (timer != t.track.size())
	{
		if (noteTimer == 0.0f)
		{
			noteTimer += t.trackRatio;
			for (int i = 0; i < 4; i++)
			{
				if (t.track[timer][i] != 0)
				{
					if (i == 0)
					{
						Note * a;
						if (t.track[timer][i] != 1)
						{
							a = new Note(t.track[timer][i]);
						}
						else
						{
							a = new Note();
							a->setXY(1, 27);
						}
						t.A.push_back(a);
						t.notes[0].push_back(a);
					}
					if (i == 1)
					{
						Note * s = new Note();
						s->setXY(1, 32);
						t.S.push_back(s);
						t.notes[1].push_back(s);
					}
					if (i == 2)
					{
						Note * d = new Note();
						d->setXY(1, 37);
						t.D.push_back(d);
						t.notes[2].push_back(d);
					}
					if (i == 3)
					{
						Note * f = new Note();
						f->setXY(1, 42);
						t.notes[3].push_back(f);
					}
				}
			}
		}
		else
			noteTimer += t.trackRatio;
	}

	for (int i = 0; i < t.notes.size(); i++)
	{
		auto it = t.notes[i].begin();
		//	for (int j = 0; j < t.notes[i].size(); j++)
		//	{
		//		if (t.notes[i][j]->getX() == 1)
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x + 3][y + i] = topBottom[i];
		//			}
		//			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		//		}
		//		else if (t.notes[i][j]->getX() == 2)
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x][y] = ' ';
		//				boar[x + 2][y + i] = middle[i];
		//				boar[x + 3][y + i] = topBottom[i];
		//			}
		//			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		//		}
		//		else if (t.notes[i][j]->getX() == 3)
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x + 1][y + i] = topBottom[i];
		//				boar[x + 2][y + i] = middle[i];
		//				boar[x + 3][y + i] = topBottom[i];
		//				boar[x + 1][y] = ' ';
		//				boar[x + 2][y] = ' ';
		//			}
		//			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		//		}
		//		else if (t.notes[i][j]->getX() == 55)
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x][y + i] = ' ';
		//				boar[x + 1][y + i] = topBottom[i];
		//				boar[x + 2][y + i] = middle[i];
		//				//boar[x + 2][y + i] = middle[i];
		//				//boar[x + 1][y] = ' ';
		//			}
		//			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		//		}
		//		else if (t.notes[i][j]->getX() == 56)
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x][y + i] = ' ';
		//				boar[x + 1][y + i] = topBottom[i];
		//			}
		//			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		//		}
		//		else if (t.notes[i][j]->getX() == 57)
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x][y + i] = ' ';
		//			}
		//			//t.notes[i].erase(t.notes[i].begin() + j);
		//			delete t.notes[i][j];
		//			t.notes[i].erase(t.notes[i].begin() + j);
		//		}
		//		else
		//		{
		//			int x = t.notes[i][j]->getX();
		//			int y = t.notes[i][j]->getY();
		//			for (int i = 0; i < 9; i++)
		//			{
		//				boar[x + 1][y + i] = topBottom[i];
		//				boar[x + 2][y + i] = middle[i];
		//				boar[x + 3][y + i] = topBottom[i];
		//				boar[x][y + i] = ' ';
		//			}
		//			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		//		}
		//	}
		//}

		while (it != t.notes[i].end())
		{
			if ((*it)->getX() == 1)
			{
				int x = (*it)->getX();
				int y = (*it)->getY();
				for (int i = 0; i < 2; i++)
				{
					boar[x + 1][y + i] = partBot[i];
				}
				(*it)->setXY((*it)->getX() + 1, (*it)->getY());
				it++;
			}
			else if ((*it)->getX() == 2)
			{
				int x = (*it)->getX();
				int y = (*it)->getY();
				for (int i = 0; i < 2; i++)
				{
					boar[x][y + i] = ' ';
					boar[x + 1][y + i] = part[i];
					boar[x + 2][y + i] = partBot[i];
				}
				(*it)->setXY((*it)->getX() + 1, (*it)->getY());
				it++;
			}
			//else if ((*it)->getX() == 3)
			//{
			//	int x = (*it)->getX();
			//	int y = (*it)->getY();
			//	for (int i = 0; i < 9; i++)
			//	{
			//		boar[x + 1][y + i] = topBottom[i];
			//		//boar[x + 2][y + i] = middle[i];
			//		//boar[x + 3][y + i] = topBottom[i];
			//		//boar[x + 1][y] = ' ';
			//		boar[x + 2][y] = ' ';
			//	}
			//	(*it)->setXY((*it)->getX() + 1, (*it)->getY());
			//	it++;
			//}
			else if ((*it)->getX() == 30)
			{
				int x = (*it)->getX();
				int y = (*it)->getY();
				for (int i = 0; i < 2; i++)
				{
					boar[x][y + i] = ' ';
					boar[x + 1][y + i] = part[i];
				}
				(*it)->setXY((*it)->getX() + 1, (*it)->getY());
				it++;
			}
			else if ((*it)->getX() == 31)
			{
				int x = (*it)->getX();
				int y = (*it)->getY();
				for (int i = 0; i < 2; i++)
				{
					boar[x][y + i] = ' ';
				}
				delete (*it);
				it = t.notes[i].erase(it);
			}
			else
			{
				int x = (*it)->getX();
				int y = (*it)->getY();
				for (int i = 0; i < 2; i++)
				{
					boar[x][y + i] = ' ';
					boar[x + 1][y + i] = part[i];
					boar[x + 2][y + i] = partBot[i];
				}
				(*it)->setXY((*it)->getX() + 1, (*it)->getY());
				it++;
			}
		}
	}

	if (timer != t.track.size())
	{
		if (noteTimer >= 1.0f)
		{
			noteTimer = 0.0f;
			timer++;
		}
	}
}

void Game::drawAll()
{
	for (int i = 0; i < boar.size(); i++)
	{
		for (int j = 0; j < boar[i].size(); j++)
		{
			printf("%c", boar[i][j]);
		}
		printf("\n");
	}

	/*for (int i = 0; i < t.track.size(); i++)
	{
		for (int j = 0; j < t.track[i].size(); j++)
		{
			if (t.track[i][j] == 0)
				continue;
			else
			{
				if (j == 0)
				{
					gotoxy(i * 3 + 4, j * 10 + 8);
					printf("%s", beatNote1.c_str());
					gotoxy(i * 3 + 5,j * 10 + 8);
					printf("%s", beatNote2.c_str());
					gotoxy(i * 3 + 6,j * 10 + 8);
					printf("%s", beatNote3.c_str());
				}
				if (j == 1)
				{
					gotoxy(i * 3 + 4, j * 10 + 8);
					printf("%s", beatNote1.c_str());
					gotoxy(i * 3 + 5, j * 10 + 8);
					printf("%s", beatNote2.c_str());
					gotoxy(i * 3 + 6, j * 10 + 8);
					printf("%s", beatNote3.c_str());
				}
				if (j == 2)
				{
					gotoxy(i * 3 + 4, j * 10 + 8);
					printf("%s", beatNote1.c_str());
					gotoxy(i * 3 + 5, j * 10 + 8);
					printf("%s", beatNote2.c_str());
					gotoxy(i * 3 + 6, j * 10 + 8);
					printf("%s", beatNote3.c_str());
				}
				if (j == 3)
				{
					gotoxy(i * 3 + 4, j * 10 + 8);
					printf("%s", beatNote1.c_str());
					gotoxy(i * 3 + 5, j * 10 + 8);
					printf("%s", beatNote2.c_str());
					gotoxy(i * 3 + 6, j * 10 + 8);
					printf("%s", beatNote3.c_str());
				}
				if (j == 4)
				{
					gotoxy(i * 3 + 4, j * 10 + 8);
					printf("%s", beatNote1.c_str());
					gotoxy(i * 3 + 5, j * 10 + 8);
					printf("%s", beatNote2.c_str());
					gotoxy(i * 3 + 6, j * 10 + 8);
					printf("%s", beatNote3.c_str());
				}
			}
		}
	}*/
}

void Game::selDraw()
{
	for (int i = 0; i < boar.size(); i++)
	{
		for (int j = 0; j < boar[i].size(); j++)
		{
			if (boar[i][j] != buffe[i][j])
			{
				HANDLE hOut;
				COORD Position;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);

				//Position x is Column
				Position.X = j;
				//Position y is Row
				Position.Y = i;

				SetConsoleCursorPosition(hOut, Position);
				printf("%c", boar[i][j]);
			}
		}
	}
}

void Game::updateBuffer()
{
	//for (int i = 0; i < boar.size(); i++)
	//{
	//	for (int j = 0; j < boar[i].size(); j++)
	//	{
	//		buffe[i][j] = boar[i][j];
	//	}
	//}
	buffe = boar;
}

void Game::checkHit(vector<Note*> & notes)
{
	auto it = notes.begin();
	//for (int i = 0; i < notes.size(); i++)
	//{
	//	if (notes[i]->getX() >= 49 && notes[i]->getX() <= 53)
	//	{
	//		int x = notes[i]->getX();
	//		int y = notes[i]->getY();
	//		for (int i = 0; i < 9; i++)
	//		{
	//			boar[x][y + i] = ' ';
	//			boar[x + 1][y + i] = ' ';
	//			boar[x + 2][y + i] = ' ';
	//		}
	//		//delete notes[i];
	//		notes.erase(notes.begin() + i);
	//		notes.resize(notes.size() - 1);
	//		break;
	//	}
	//}
	size_t vec_size = 0;
	while (it != notes.end())
	{
		
		if ((*it)->getX() >= 49 && (*it)->getX() <= 53)
		{
			int x = (*it)->getX();
			int y = (*it)->getY();
			for (int i = 0; i < 9; i++)
			{
				boar[x][y + i] = ' ';
				boar[x + 1][y + i] = ' ';
				boar[x + 2][y + i] = ' ';
			}
			delete (*it);
			it = notes.erase(it);
		}
		else
		{
			++it;
			++vec_size;
		}
	}
}