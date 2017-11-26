#pragma once

#include <string>
#include <vector>

using std::string; using std::vector;

class Note
{
public:
	Note();
	Note(int l);
	~Note();
	void setXY(int, int);
	int getX();
	int getY();
private:
	vector<vector<int>> coords;
	string beat[3];
	int type;
	int length;
	int nX, nY;
	bool loadTime;
};

//class Note {
//public:
//	vector<vector<int>> coords;
//	Note()
//	{
//	}
//
//	Note(int x, int y)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			vector<int> tmp(2);
//			coords.push_back(tmp);
//			coords[i][0] = x + i;
//			coords[i][1] = y;
//		}
//	}
//	~Note()
//	{
//
//	}
//
//	void setCoords(int x, int y)
//	{
//		nX = x;
//		nY = y;
//		for (int i = 0; i < 3; i++)
//		{
//			vector<int> tmp(2);
//			coords.push_back(tmp);
//			coords[i][0] = x + i;
//			coords[i][1] = y;
//		}
//	}
//
//	int nX, nY;
//};
