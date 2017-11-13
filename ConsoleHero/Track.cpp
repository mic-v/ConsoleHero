#include "Track.h"

Track::Track()
{
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
			//cout << line << endl;
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

	myfile.close();
}
