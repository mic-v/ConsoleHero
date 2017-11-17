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
	void input();
	void move();
	void drawAll();
	void selDraw();
	void updateBuffer();
	void checkHit(vector<Note*> notes);
	float noteTimer;
	int timer;
	bool keyDown[5];
};