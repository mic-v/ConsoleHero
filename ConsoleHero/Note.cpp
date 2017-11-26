#include "Note.h"

Note::Note()
{
	type = 1; //single beat
	length = 1;
}

Note::Note(int l)
{
	type = 2; //long beat
	length = l; //beat length
}

Note::~Note()
{
}

void Note::setXY(int x, int y)
{
	nX = x;
	nY = y;
}

int Note::getX()
{
	return nX;
}

int Note::getY()
{
	return nY;
}
