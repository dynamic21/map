#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::cout;
using std::endl;
using std::vector;

int main()
{

	map<int, map<int, vector<int>>> world;

	world.clear();

	world[-1][-1].push_back(0);
	world[-1][-1].push_back(9);
	world[-1][0].push_back(1);
	world[-1][1].push_back(2);
	world[0][-1].push_back(3);
	world[0][0].push_back(4);
	world[0][1].push_back(5);
	world[1][-1].push_back(6);
	world[1][0].push_back(7);
	world[1][1].push_back(8);

	for (map<int, map<int, vector<int>>>::iterator i = world.begin(); i != world.end(); i++)
		for (map<int, vector<int>>::iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << "(" << i->first << ", " << j->first << ") : ";

			for (int k = 0; k < j->second.size(); k++)
				cout << j->second[k] << " ";

			cout << endl;
		}
	cout << endl;

	map<int, map<int, vector<int>>>::iterator find1;
	map<int, vector<int>>::iterator find2;

	for (map<int, map<int, vector<int>>>::iterator i = world.begin(); i != world.end(); i++)
	{
		for (map<int, vector<int>>::iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			for (int k = 0; k < j->second.size(); k++)
			{
				for (int l = k + 1; l < j->second.size(); l++)
				{
					cout << j->second[k] << " vs " << j->second[l] << endl;
				}

				find1 = world.find(i->first);

				if (find1 != world.end())
				{
					find2 = find1->second.find(j->first + 1);

					if (find2 != find1->second.end())
					{
						for (int l = 0; l < find2->second.size(); l++)
						{
							cout << j->second[k] << " vs " << find2->second[l] << endl;
						}
					}
				}

				find1 = world.find(i->first + 1);

				if (find1 != world.end())
				{
					find2 = find1->second.find(j->first - 1);

					if (find2 != find1->second.end())
					{
						for (int l = 0; l < find2->second.size(); l++)
						{
							cout << j->second[k] << " vs " << find2->second[l] << endl;
						}
					}

					find2 = find1->second.find(j->first);

					if (find2 != find1->second.end())
					{
						for (int l = 0; l < find2->second.size(); l++)
						{
							cout << j->second[k] << " vs " << find2->second[l] << endl;
						}
					}

					find2 = find1->second.find(j->first + 1);

					if (find2 != find1->second.end())
					{
						for (int l = 0; l < find2->second.size(); l++)
						{
							cout << j->second[k] << " vs " << find2->second[l] << endl;
						}
					}
				}
			}
			cout << endl;
		}
	}
}