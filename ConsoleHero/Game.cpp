﻿#include "Game.h"
#include "Track.h"

//class Game {
//	char board[55][52], buffer[55][52];
//	char Player;
//	int plX, plY;
//public:
//	Game()
//	{
//	}
//	void Init() {
//		Player = 'A';
//		plX = 5; plY = 0;
//		for (int i = 0; i < 55; i++) {
//			for (int j = 0; j < 52; j++) {
//				if (j % 10 == 0)
//				{
//					board[i][j] = buffer[i][j] = '|';
//				}
//				else
//					board[i][j] = buffer[i][j] = ' ';
//
//			}
//		}
//		board[plX][plY] = Player;
//	}
//	void MainL() {
//		bool loop = true;
//		DrawAll();
//		while (loop == true) {
//			UpdateBuffer();
//			Move();
//			Sleep(30);
//			SelDraw();
//		}
//	}
//private:
//	void Move() {
//		char keyPressed = ' ';
//		if (_kbhit()) {
//			keyPressed = _getch();
//		}
//		else {
//			keyPressed = ' ';
//		}
//
//	}
//	void DrawAll() 
//	{
//		for (int i = 0; i < 55; i++) 
//		{
//			for (int j = 0; j < 52; j++) 
//			{
//				printf("%c", board[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	void SelDraw() {
//		for (int i = 0; i < 55; i++) 
//		{
//			for (int j = 0; j < 52; j++) 
//			{
//				if (board[i][j] != buffer[i][j]) 
//				{
//					HANDLE hOut;
//					COORD Position;
//					hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//					Position.X = i;
//					Position.Y = j;
//
//					SetConsoleCursorPosition(hOut, Position);
//					printf("%c", board[i][j]);
//				}
//			}
//		}
//	}
//	void UpdateBuffer() {
//		for (int i = 0; i < 55; i++) 
//		{
//			for (int j = 0; j < 52; j++) 
//			{
//				buffer[i][j] = board[i][j];
//			}
//		}
//	}
//};

int selection = 1;
bool menuRunning = true;
string beatNote1 = " +-----+ ";
string beatNote2 = " |     | ";
string beatNote3 = " +-----+ ";

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



	//while (true)
	//{
	//	if (_kbhit())
	//	{
	//		if (GetAsyncKeyState(0x41))
	//		{
	//			cout << "A" << endl;
	//		}
	//		if (GetAsyncKeyState(0x53))
	//		{
	//			cout << "S" << endl;
	//		}
	//		if (GetAsyncKeyState(VK_RETURN))
	//		{
	//			cout << "strum" << endl;
	//		}

	//	}
	//	Sleep(20);
	//}

	//Track t;
	//t.readTrack();
	//vector<vector<char>> test;

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


	//for (int i = 0; i < test.size(); i++)
	//{
	//	for (int j = 0; j < test[i].size(); j++)
	//	{
	//		cout << test[i][j];
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
	//				gotoxy(i * 3 + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy(i * 3 + 5,j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy(i * 3 + 6,j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 1)
	//			{
	//				gotoxy(i * 3 + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy(i * 3 + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy(i * 3 + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 2)
	//			{
	//				gotoxy(i * 3 + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy(i * 3 + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy(i * 3 + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 3)
	//			{
	//				gotoxy(i * 3 + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy(i * 3 + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy(i * 3 + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//			if (j == 4)
	//			{
	//				gotoxy(i * 3 + 4, j * 10 + 8);
	//				printf("%s", beatNote1.c_str());
	//				gotoxy(i * 3 + 5, j * 10 + 8);
	//				printf("%s", beatNote2.c_str());
	//				gotoxy(i * 3 + 6, j * 10 + 8);
	//				printf("%s", beatNote3.c_str());
	//			}
	//		}
	//	}
	//}


	//					HANDLE hOut;
	//					COORD Position;
	//					hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//					Position.X = i;
	//					Position.Y = j;
	//
	//					SetConsoleCursorPosition(hOut, Position);
	//					printf("%c", board[i][j]);

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
	//for (int i = 0; i < 55; i++) 
	//{
	//	for (int j = 0; j < 52; j++) 
	//	{
	//		if (j % 10 == 0)
	//		{
	//			board[i][j] = buffer[i][j] = '|';
	//		}
	//		else
	//			board[i][j] = buffer[i][j] = ' ';
	//	}
	//}
	Player = 'A';
	plX = 4; plY = 169;
	ifstream myfile("Game.txt");
	if (myfile.is_open())
	{
		for (int i = 0; getline(myfile, line); i++)
		{
			//cout << line << endl;
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
	//boar[plX][plY] = Player;
}

void Game::mainL()
{
	bool loop = true;
	drawAll();
	while (loop == true)
	{
		updateBuffer();
		move();
		Sleep(20);
		selDraw();
	}
}

void Game::move()
{
	char keyPressed = ' ';
	if (_kbhit()) 
	{
		keyPressed = _getch();
	}
	else {
		keyPressed = ' ';
	}

	if (keyPressed != ' ')
	{
		for (int i = 0; i < t.track.size(); i++)
		{
			for (int j = 0; j < t.track[i].size(); j++)
			{
				if (t.track[i][j] == 0)
					continue;
				else
				{
					if (j == 0)
					{
						gotoxy(i * 3 + 5, j * 10 + 8);
						printf("%s", beatNote1.c_str());
						gotoxy(i * 3 + 6, j * 10 + 8);
						printf("%s", beatNote2.c_str());
						gotoxy(i * 3 + 7, j * 10 + 8);
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
		}
	}
	//if (keyPressed != ' ')
	//{
	//	boar[plX][plY+1] = Player;
	//	boar[plX][plY] = ' ';
	//	plY++;
	//}
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

	for (int i = 0; i < t.track.size(); i++)
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
	}
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