#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <algorithm> 
#include <iostream>
#include "Note.h"
#include "Track.h"

#define EASY 50
#define MEDIUM 40
#define HARD 20

using std::vector; using std::ifstream;
using std::string; using std::cout;
using std::stoi;

class Track
{
public:
	Track();
	~Track();
	void readTrack();
	void loadNextSection();
	void setTrack();
	void setTrackNumber(int);
	string getTrackFile();
	int getTrackNumber();


	int getTrackLength();
	
	vector<string> list;
	vector<int> listDifficulty;
	vector<string> listCopy;
	vector<string> artist;
	vector<string> song;

	vector<vector<int>> track;
	vector<Note*> A;
	vector<Note*> S;
	vector<Note*> D;
	vector<Note*> F;
	vector<vector<Note*>> notes;
	vector<vector<int>> board, buffer, nextBoard;
	float trackRatio;
private:
	int trackLength;
	int trackNumber;
	string trackFile;
};
