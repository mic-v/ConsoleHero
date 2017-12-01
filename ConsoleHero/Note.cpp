#include "Note.h"

Note::Note()
{
	type = 1; //single beat
	length = 1;
	hit = false;
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

int Note::getLength()
{
	return length;
}

int Note::getType()
{
	return type;
}

void Note::setLength(int l)
{
	length = l;
	type = 2;
}
