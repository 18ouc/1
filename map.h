#ifndef _MAP_H
#define _MAP_H
#include <iostream>
#include <string>
#include <vector>
#include "room.h"
using namespace std;
class map
{
public:
	map(string shape = 0) : shape(shape) {}
	~map();
	void showMap();
	void addRoom(room temp);
private:
	string shape;
	vector<room> ROOM;
};
#endif

