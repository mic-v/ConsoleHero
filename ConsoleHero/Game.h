#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Track.h"

#define EASY 50
#define MEDIUM 40
#define HARD 20

#define GOODHIT 30
#define BADHIT 10


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
	HANDLE wHnd;
	HANDLE rHnd;
private:
	void input();
	void nextLine();
	void move();
	void drawAll();
	void selDraw();
	void updateBuffer();
	void checkHit(vector<Note*> & notes);
	float noteTimer;
	int timer;
	bool keyDown[5];
};