#pragma once

#include<iostream>
#include<Windows.h>

using std::cout;
using std::endl;

class Menu
{
public:
	Menu();
	~Menu();
	void loadMenu();
	void gotoxy(int x, int y);
	bool menu;
	bool game;
	bool tutorial;
	bool exit;
	bool credit;
	int arrow;
private:
};