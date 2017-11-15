#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <algorithm> 
#include <iostream>
#include "Note.h"

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
	int getTrackLength();
	
	vector<vector<int>> track;
	vector<Note*> A;
	vector<Note*> S;
	vector<Note*> D;
	vector<Note*> F;
	vector<Note*> G;
	vector<vector<Note*>> notes;
	vector<vector<int>> board, buffer, nextBoard;
	float trackRatio;
private:
	int trackLength;
};
