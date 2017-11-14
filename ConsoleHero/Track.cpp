#include "Track.h"

Track::Track()
{
	trackLength = 0;
	songStart = 0;
}

Track::~Track()
{
}

void Track::readTrack()
{
	ifstream myfile("Tracks/TrackOne.txt");
	string line;
	if (myfile.is_open())
	{
		for (int i = 0; getline(myfile, line); i++)
		{
			if (i != 0 && i % 16 == 0)
			{
				trackLength++;
			}
			vector<int> column(line.size());
			track.push_back(column);
			for (int j = 0; j < line.size(); j++)
			{
				
				int tmp = line[j] - '0';
				track[i][j] = tmp;
			}
		}
	}
	std::reverse(track.begin(), track.end());

	std::vector< std::vector<int> >::const_iterator row;
	std::vector<int>::const_iterator col;

	for (row = track.begin(); row != track.begin() + 16; ++row)
	{
		for (col = row->begin(); col != row->end(); ++col)
		{
		}
	}
	myfile.close();

	
}

void Track::loadNextSection()
{

}

int Track::getTrackLength()
{
	return trackLength;
}
