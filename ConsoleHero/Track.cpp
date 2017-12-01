#include "Track.h"

Track::Track()
{
	trackLength = 0;
	trackRatio = 15.0f / 30.0f;
	notes.push_back(A);
	notes.push_back(S);
	notes.push_back(D);
	notes.push_back(F);
	trackNumber = 0;
	trackFile = "Tracks/Track3.txt";

	string line;
	ifstream stream("Tracks/TrackList.txt");
	if (stream.is_open())
	{
		while (getline(stream, line))
		{
			string line2 = line.substr(1);
			int tmp = line[0] - '0';
			listDifficulty.push_back(tmp);
			list.push_back(line2);
		}
	}
	listCopy = list;

	for (int i = 0; i < list.size(); i++)
	{
		string tmp = listCopy[i];
		replace(tmp.begin(), tmp.end(), '_', ' ');
		string tmp1 = tmp.substr(0, tmp.find("-"));
		string tmp2 = tmp.substr(tmp.find("-") + 1);
		song.push_back(tmp1);
		artist.push_back(tmp2);
		listCopy[i] = tmp;
		//string filename = "Tracks/";
		//filename += list[0];
		//filename += "_E.txt";
		//cout << filename << endl;
		//system("pause");
	}
}

Track::~Track()
{
}

void Track::readTrack()
{
	ifstream myfile(trackFile);
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
		for (int i = 0; i <= track.size(); i++)
		{
			if (i % 15 == 0)
			{
				track.erase(track.begin() + i);
			}
		}
		trackLength = track.size();
	}
	myfile.close();

}

void Track::loadNextSection()
{

}

void Track::setTrack()
{
	trackFile = "Tracks/";
	trackFile += list[trackNumber];
	trackFile += ".txt";

}

void Track::setTrackNumber(int number)
{
	trackNumber = number;
}

string Track::getTrackFile()
{
	return trackFile;
}

int Track::getTrackNumber()
{
	return trackNumber;
}

int Track::getTrackLength()
{
	return trackLength;
}
