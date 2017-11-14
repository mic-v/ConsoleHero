#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <algorithm> 
#include <iostream>

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
	vector<vector<int>> board, buffer, nextBoard;
private:
	int trackLength;
	int songStart;
};
