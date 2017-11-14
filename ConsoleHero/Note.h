#pragma once

#include <string>

using std::string;

class Note
{
public:
	string beat[3];
	
	Note();
	~Note();
	void setNoteXY(int, int);
	int getX();
	int getY();
private:
	int coords[2];
	int type;
	bool loadTime;
};
