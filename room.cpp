#include "room.h"





string room::getName()
{
	return name;
}

void room::addGoodPerson(goodPerson temp)
{
	goodperson.push_back(temp);
}

void room::addBadPerson(badPerson temp)
{
	badperson.push_back(temp);
}

void room::inRoom()
{
	ifIn = 1;
}

bool room::getIfIn()
{
	return ifIn;
}



room::~room()
{
}
