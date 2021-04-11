#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::cout;
using std::endl;
using std::vector;

long long intToLongLong(int x, int y)
{
	return long long(x) << 32 | (long long(y) & 0x00000000ffffffff);
}

int main()
{
	map<long long, vector<int>> world;

	world.clear();

	world[intToLongLong(-1, -1)].push_back(0);
	world[intToLongLong(-1, 0)].push_back(1);
	world[intToLongLong(-1, 1)].push_back(2);
	world[intToLongLong(0, -1)].push_back(3);
	world[intToLongLong(0, 0)].push_back(4);
	world[intToLongLong(0, 1)].push_back(5);
	world[intToLongLong(1, -1)].push_back(6);
	world[intToLongLong(1, 0)].push_back(7);
	world[intToLongLong(1, 1)].push_back(8);

	for (map<long long, vector<int>>::iterator i = world.begin(); i != world.end(); i++)
	{
		cout << "(" << int(i->first >> 32) << ", " << int(i->first) << ") : ";

		for (int j = 0; j < i->second.size(); j++)
			cout << i->second[j] << " ";

		cout << endl;
	}

	cout << endl;

	map<long long, vector<int>>::iterator find;

	for (map<long long, vector<int>>::iterator i = world.begin(); i != world.end(); i++)
	{
		for (int j = 0; j < i->second.size(); j++)
		{
			for (int k = j + 1; k < i->second.size(); k++)
				cout << i->second[j] << " vs " << i->second[k] << endl;

			find = world.find(intToLongLong(int(i->first >> 32), int(i->first) + 1));

			if (find != world.end())
				for (int k = 0; k < find->second.size(); k++)
					cout << i->second[j] << " vs " << find->second[k] << endl;

			find = world.find(intToLongLong(int(i->first >> 32) + 1, int(i->first) + 1));

			if (find != world.end())
				for (int k = 0; k < find->second.size(); k++)
					cout << i->second[j] << " vs " << find->second[k] << endl;

			find = world.find(intToLongLong(int(i->first >> 32) + 1, int(i->first)));

			if (find != world.end())
				for (int k = 0; k < find->second.size(); k++)
					cout << i->second[j] << " vs " << find->second[k] << endl;

			find = world.find(intToLongLong(int(i->first >> 32) + 1, int(i->first) - 1));

			if (find != world.end())
				for (int k = 0; k < find->second.size(); k++)
					cout << i->second[j] << " vs " << find->second[k] << endl;
		}

		cout << endl;
	}
}