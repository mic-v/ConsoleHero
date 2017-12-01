#pragma once

#include<iostream>
#include<Windows.h>
#include <mmsystem.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Menu
{
public:
	Menu();
	~Menu();
	void loadMenu();
	void loadTracks();
	void setSong(string txt);
	void gotoxy(int x, int y);
	bool menu;
	bool game;
	bool tutorial;
	bool exit;
	bool credit;
	int arrow;
private:
};