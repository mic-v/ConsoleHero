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
		//for (int i = 0; getline(myfile, line); i++)
		//{
		//	if (i != 0 && i % 18 == 0)
		//	{
		//		trackLength++;
		//		continue;
		//	}
		//	vector<int> column(line.size());
		//	if (i < 1)
		//	{
		//	}
		//	else
		//	{
		//		vector<int> column(line.size());
		//		track.push_back(column);
		//		for (int j = 0; j < line.size(); j++)
		//		{
		//			int tmp = line[j] - '0';
		//			track[i][j] = tmp;
		//		}
		//	}

		//}
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
		track.erase(track.begin());
		//for (int i = 0; i < track.size(); i++)
		//{
		//	if (i != 0 && i % 18 == 0)
		//	{
		//	
		//	}
		//}
	}
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
	myfile.close();

	
}

void Track::loadNextSection()
{

}

int Track::getTrackLength()
{
	return trackLength;
}
