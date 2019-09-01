#include "map.h"


map::~map()
{
}

void map::showMap()
{
	cout << shape << endl;
}

void map::addRoom(room temp)
{
	ROOM.push_back(temp);
}