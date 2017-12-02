#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Track.h"


#define GOODHIT 30
#define BADHIT 10


using namespace std;

class Game
{
public:
	Game();
	~Game();
	void init();
	void mainL();
	void getTracks();
	vector<string> track;
	HANDLE wHnd;
	HANDLE rHnd;
	Track t;
private:
	void input();
	void nextLine();
	void move();
	void drawAll();
	void selDraw();
	void updateBuffer();
	void updateScore();
	void checkHit(vector<Note*> & notes);
	vector<vector<char>> boar, buffe;
	char Player;
	float noteTimer;
	int timer;
	bool keyDown[5];
	int playerScore;
	int multiplier[4];
	int multiplierPlace;
	int hitTotal;
	int noteTotal;
	int noteStreak;
	int noHit = 0;
	bool loop;
	int endTimer;
	bool gameOver = false;
};