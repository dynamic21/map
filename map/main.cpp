#include <iostream>
#include <vector>
#include <chrono>
#include <map>

using std::map;
using std::cout;
using std::endl;
using std::vector;

using std::chrono::seconds;
using std::chrono::microseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

uint32_t m_z = (uint32_t)duration_cast<seconds>(high_resolution_clock::now().time_since_epoch()).count();
uint32_t m_w = (uint32_t)duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();

unsigned int intRand()
{
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);

	return (m_z << 16) + m_w;
}

int main()
{

	map<uint64_t, vector<int>> world;

	uint32_t x = intRand();
	uint32_t y = intRand();

	world[uint64_t(x) << 32 | y].push_back(10);
	world[uint64_t(x) << 32 | y].push_back(100);

	world[uint64_t(y) << 32 | x].push_back(-10);
	world[uint64_t(y) << 32 | x].push_back(-100);

	//world[uint64_t(x) << 32 | y];

	for (map<uint64_t, vector<int>>::iterator i = world.begin(); i != world.end(); i++) {
		cout << i->first << ": ";
		for (int j = 0; j < i->second.size(); j++)
		{
			cout << i->second[j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << world.size() << endl;

	for (map<uint64_t, vector<int>>::iterator i = world.begin(); i != world.end(); true) {
		i = world.erase(i);
	}

	cout << world.size() << endl;

	for (map<uint64_t, vector<int>>::iterator i = world.begin(); i != world.end(); i++) {
		cout << i->first << ": ";
		for (int j = 0; j < i->second.size(); j++)
		{
			cout << i->second[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}