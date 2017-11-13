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

void Note::setNoteXY(int x, int y)
{
	coords[0] = x;
	coords[1] = y;
}

int Note::getX()
{
	return coords[0];
}

int Note::getY()
{
	return coords[1];
}
