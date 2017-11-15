#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Track.h"

#define EASY 35
#define MEDIUM 30
#define HARD 20


using namespace std;

class Game
{
	char board[55][52], buffer[55][52];
	vector<vector<char>> boar, buffe;
	char Player;
	int plX, plY;
	Track t;
public:
	Game();
	~Game();
	void init();
	void mainL();
private:
	void move();
	void drawAll();
	void selDraw();
	void updateBuffer();
	float noteTimer;
	int timer;
};