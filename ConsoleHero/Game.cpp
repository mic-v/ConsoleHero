#include "Game.h"
#include "Track.h"


int selection = 1;
bool menuRunning = true;
string beatNote1 = " +-----+ ";
string beatNote2 = " |     | ";
string beatNote3 = " +-----+ ";
char topBottom[] = {' ', '+', '-','-', '-', '-', '-', '+', ' ' };
char middle[] = { ' ', '|', ' ',' ', ' ', ' ', ' ', '|', ' ' };

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
	MoveWindow(console, 250, 20, 1400, 1000, TRUE); // 800 width, 100 height
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

	////Track t;
	////t.readTrack();

	//for (int i = 0; i < t.getTrackLength(); i++)
	//{
	//	cout << i << endl;
	//}

	//Track t;
	//t.readTrack();
	//vector<vector<char>> test;
	//for (int i = 0; i < t.track.size(); i++)
	//{
	//	for (int j = 0; j < t.track[i].size(); j++)
	//	{
	//		cout << t.track[i][j];
	//	}
	//	cout << endl;
	//}

	//string line;
	//ifstream myfile("Game.txt");
	//if (myfile.is_open())
	//{
	//	for (int i = 0; getline(myfile, line); i++)
	//	{
	//		//cout << line << endl;
	//		vector<char> test2(line.size());
	//		test.push_back(test2);
	//		for (int j = 0; j < line.size(); j++)
	//		{
	//			if (line[j] == '~')
	//				test[i][j] = ' ';
	//			else
	//				test[i][j] = line[j];
	//		}
	//	}
	//}
	//myfile.close();


	//for (int i = 0; i < t.track.size(); i++)
	//{
	//	for (int j = 0; j < t.track[i].size(); j++)
	//	{
	//		cout << t.track[i][j];
	//	}
	//	cout << endl;
	//}

	//for (int i = 0; i < t.track.size(); i++)
	//{
	//	for (int j = 0; j < t.track[i].size(); j++)
	//	{
	//		if (t.track[i][j] == 0)
	//			continue;
	//		else
	//		{
	//			if (j == 0)
	//			{
	//				gotoxy((i * 3) + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy((i * 3) + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy((i * 3) + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 1)
	//			{
	//				gotoxy((i * 3) + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy((i * 3) + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy((i * 3) + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 2)
	//			{
	//				gotoxy((i * 3) + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy((i * 3) + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy((i * 3) + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 3)
	//			{
	//				gotoxy((i * 3) + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy((i * 3) + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy((i * 3) + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 4)
	//			{
	//				gotoxy((i * 3) + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy((i * 3) + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy((i * 3) + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//		}
	//	}
	//}

	//while (true)
	//{
	//	if (_kbhit())
	//	{
	//		if (GetAsyncKeyState(0x41))
	//		{
	//			HANDLE hOut;
	//			COORD Position;
	//			hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//			Position.X = 12;
	//			Position.Y = 51;
	//			SetConsoleCursorPosition(hOut, Position);
	//			SetConsoleTextAttribute(hOut, 17);
	//			printf("%c", ' ');
	//		}

	//		if (GetAsyncKeyState(0x53))
	//		{
	//			HANDLE hOut;
	//			COORD Position;
	//			hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//			Position.X = 22;
	//			Position.Y = 51;
	//			SetConsoleCursorPosition(hOut, Position);
	//			printf("%c", ' ');
	//		}

	//		if (GetAsyncKeyState(0x44))
	//		{
	//			HANDLE hOut;
	//			COORD Position;
	//			hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//			Position.X = 32;
	//			Position.Y = 51;
	//			SetConsoleCursorPosition(hOut, Position);
	//			printf("%c", ' ');
	//		}

	//		if (GetAsyncKeyState(0x46))
	//		{
	//			HANDLE hOut;
	//			COORD Position;
	//			hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//			Position.X = 42;
	//			Position.Y = 51;
	//			SetConsoleCursorPosition(hOut, Position);
	//			printf("%c", ' ');
	//		}

	//		if (GetAsyncKeyState(0x47))
	//		{
	//			HANDLE hOut;
	//			COORD Position;
	//			hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//			Position.X = 52;
	//			Position.Y = 51;
	//			SetConsoleCursorPosition(hOut, Position);
	//			printf("%c", ' ');
	//		}

	//	}
	//}

	//std::vector< std::vector<int> >::const_iterator row;
	//std::vector<int>::const_iterator col;
	//int it = 0;

	//int length = 0;

	//vector<vector<int>> test(10, vector<int>(10));
	//vector<vector<int>> track;
	//for (int i = 0; i < test.size(); i++)
	//{
	//	for (int j = 0; j < test[i].size(); j++)
	//	{
	//		if (i % 3 == 0)
	//		{
	//			test[i][j] = 12;
	//		}
	//		else
	//			test[i][j] = i;
	//		cout << test[i][j];
	//	}
	//	if (i % 3 == 0 && i != 0)
	//	{
	//		length++;
	//	}
	//	cout << endl;
	//}

	//cout << length << endl << endl;

	//for (int k = 0; k < 2; k++)
	//{
	//	for (int i = k * 3 + 1; i % 3 != 0 || i == 0; i++)
	//	{
	//		vector<int>::const_iterator first = test[i].begin();
	//		vector<int>::const_iterator last = test[i].end();
	//		vector<int> tmp(first, last);
	//		track.push_back(tmp);
	//	}
	//	for (int i = k * 2; i < track.size(); i++)
	//	{
	//		for (int j = 0; j < track[i].size(); j++)
	//		{
	//			cout << track[i][j];
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	
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
	
	ifstream myfile("Game.txt");
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
	bool loop = true;
	drawAll();
	while (loop == true)
	{
		updateBuffer();
		move();
		Sleep(60);
		selDraw();
	}
}

void Game::move()
{

	if (noteTimer == 0.0f)
	{
		noteTimer += t.trackRatio;
		for (int i = 0; i < 5; i++)
		{
			if (t.track[timer][i] == 1)
			{
				if (i == 0)
				{
					Note * a = new Note();
					a->setXY(1, 8);
					t.A.push_back(a);
					t.notes[3].push_back(a);
				}
				if (i == 1)
				{
					Note * s = new Note();
					s->setXY(1, 18);
					t.S.push_back(s);
					t.notes[3].push_back(s);
				}
				if (i == 2)
				{
					Note * d = new Note();
					d->setXY(1, 28);
					t.D.push_back(d);
					t.notes[3].push_back(d);
				}
				if (i == 3)
				{
					Note * f = new Note();
					f->setXY(1, 38);
					t.notes[3].push_back(f);
				}
				if (i == 4)
				{
					Note * g = new Note();
					g->setXY(1, 48);
					t.notes[4].push_back(g);
				}
			}
		}
	}
	else
		noteTimer += t.trackRatio;

	for (int i = 0; i < t.notes.size(); i++)
	{
		for (int j = 0; j < t.notes[i].size(); j++)
		{
			if (t.notes[i][j]->getX() == 1)
			{
				int x = t.notes[i][j]->getX();
				int y = t.notes[i][j]->getY();
				for (int i = 0; i < 9; i++)
				{
					boar[x+3][y + i] = topBottom[i];
				}
			}
			else if (t.notes[i][j]->getX() == 2)
			{
				int x = t.notes[i][j]->getX();
				int y = t.notes[i][j]->getY();
				for (int i = 0; i < 9; i++)
				{
					boar[x][y] = ' ';
					boar[x + 2][y + i] = middle[i];
					boar[x + 3][y + i] = topBottom[i];
				}
			}
			else if (t.notes[i][j]->getX() == 3)
			{
				int x = t.notes[i][j]->getX();
				int y = t.notes[i][j]->getY();
				for (int i = 0; i < 9; i++)
				{
					boar[x + 1][y + i] = topBottom[i];
					boar[x + 2][y + i] = middle[i];
					boar[x + 3][y + i] = topBottom[i];
					boar[x + 1][y] = ' ';
					boar[x + 2][y] = ' ';
				}
			}
			else
			{
				int x = t.notes[i][j]->getX();
				int y = t.notes[i][j]->getY();
				for (int i = 0; i < 9; i++)
				{
					boar[x + 1][y + i] = topBottom[i];
					boar[x + 2][y + i] = middle[i];
					boar[x + 3][y + i] = topBottom[i];
					boar[x][y + i] = ' ';

				}
			}
			t.notes[i][j]->setXY(t.notes[i][j]->getX() + 1, t.notes[i][j]->getY());
		}
	}

	if (noteTimer >= 1.0f)
	{
		noteTimer = 0.0f;
		timer++;
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
	for (int i = 0; i < boar.size(); i++)
	{
		for (int j = 0; j < boar[i].size(); j++)
		{
			buffe[i][j] = boar[i][j];
		}
	}
}