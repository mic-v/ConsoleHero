#include "Menu.h"
#include "Game.h"

Menu::Menu()
{
	menu = true;
	game = false;
	exit = false;
	tutorial = false;
	arrow = 0;


}

Menu::~Menu()
{
}

void Menu::loadMenu()
{
	printf("\n");
	cout << " ___|)_______________________________________________" << endl
		<< "|___/________________________________________________" << endl
		<< "|__/|_______________CONSOLE__________________________" << endl
		<< "|_/(|,\\________________________RHYTHM________________" << endl
		<< "|_\\_|_/________________by: Iatneh____________________" << endl
		<< "|   |" << endl
		<< "| (_|" << endl;

	gotoxy(10, 22);
	printf("Play");

	gotoxy(15, 22);
	printf("Tutorial");

	gotoxy(20, 22);
	printf("Exit");
	gotoxy(30, 0);
}


void Menu::loadTracks()
{
}

void Menu::setSong(string txt)
{
	//std::wstring stemp = std::wstring(txt.begin(), txt.end());
	//LPCSTR sw = stemp.c_str();
	PlaySound(txt.c_str() , NULL, SND_ASYNC);
}

void Menu::gotoxy(int x, int y)
{
	COORD Position;

	//X is horizontal, Y is vertical
	Position.X = y;
	Position.Y = x;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}
