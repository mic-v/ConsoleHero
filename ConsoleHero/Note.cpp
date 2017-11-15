#include "Note.h"

Note::Note()
{
	beat[0] = " +-----+ ";
	beat[1] = " |     | ";
	beat[2] = " +-----+ ";
}

Note::~Note()
{
}

void Note::setXY(int x, int y)
{
	nX = x;
	nY = y;
	for (int i = 0; i < 3; i++)
	{
		vector<int> tmp(2);
		coords.push_back(tmp);
		coords[i][0] = x + i;
		coords[i][1] = y;
	}
}

int Note::getX()
{
	return nX;
}

int Note::getY()
{
	return nY;
}
