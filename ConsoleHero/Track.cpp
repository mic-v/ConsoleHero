#include "Track.h"

Track::Track()
{
	trackLength = 0;
	trackRatio = 18.0f / 54.0f;
	notes.push_back(A);
	notes.push_back(S);
	notes.push_back(D);
	notes.push_back(F);
	notes.push_back(G);
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
			vector<int> column(line.size());
			track.push_back(column);
			for (int j = 0; j < line.size(); j++)
			{
				int tmp = line[j] - '0';
				track[i][j] = tmp;
			}
		}

		int j = 0;
		for (int i = 0; i < track.size(); i++)
		{
			if (i % 19 == 0)
			{
				track.erase(track.begin() + i - j);
				j++;
			}
		}
		trackLength = track.size();
	}
	myfile.close();
	std::reverse(track.begin(), track.end());

	//if (myfile.is_open())
	//{
	//	for (int i = 0; getline(myfile, line); i++)
	//	{
	//		if (i != 0 && i % 16 == 0)
	//		{
	//			trackLength++;
	//		}
	//		vector<int> column(line.size());
	//		track.push_back(column);
	//		for (int j = 0; j < line.size(); j++)
	//		{
	//			
	//			int tmp = line[j] - '0';
	//			track[i][j] = tmp;
	//		}
	//	}
	//}
	//std::reverse(track.begin(), track.end());

	//std::vector< std::vector<int> >::const_iterator row;
	//std::vector<int>::const_iterator col;

	//for (row = track.begin(); row != track.begin() + 17; ++row)
	//{
	//	for (col = row->begin(); col != row->end(); ++col)
	//	{
	//	}
	//}
	//for (int k = 0; k < 17; k++)
	//{
	//	for (int i = k * 3 + 1; i % 3 != 0 || i == 0; i++)
	//	{
	//		vector<int>::const_iterator first = test[i].begin();
	//		vector<int>::const_iterator last = test[i].end();
	//		vector<int> tmp(first, last);
	//		track.push_back(tmp);
	//	}
	//	for (int i = k * 2; i < track.size(); i++)
	//	{
	//		for (int j = 0; j < track[i].size(); j++)
	//		{
	//			cout << track[i][j];
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

	
}

void Track::loadNextSection()
{

}

int Track::getTrackLength()
{
	return trackLength;
}
