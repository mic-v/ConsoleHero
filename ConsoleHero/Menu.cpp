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
	cout << " ___|)___________________________________________" << endl
		<< "|___/____________________________________________" << endl
		<< "|__/|___________CONSOLE__________________________" << endl
		<< "|_/(|,\\____________________RHYTHM________________" << endl
		<< "|_\\_|_/____________by: Iatneh____________________" << endl
		<< "|   |" << endl
		<< "| (_|" << endl;

	gotoxy(10, 18);
	printf("Play");

	gotoxy(15, 18);
	printf("Tutorial");

	gotoxy(20, 18);
	printf("Exit");
	gotoxy(30, 0);
}


void Menu::loadTracks()
{
}

void Menu::gotoxy(int x, int y)
{
	COORD Position;

	//X is horizontal, Y is vertical
	Position.X = y;
	Position.Y = x;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}
