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

void room::showBadPerson()
{
	cout << "该房间中坏人的情况为：" << endl;
	if (badperson.size() == 0) {
		cout << "该房间的无坏人" << endl;
	}
	else {
		for (int i = 0; i < badperson.size(); i++) {
			cout << i + 1 << ".名称:" << badperson[i].getName() << " 难度值:" << badperson[i].getDown() + badperson[i].getUp() << " 生命值：" << badperson[i].getblood() << endl;
		}
	}
}

void room::eraseBadPerson(int id)
{
	vector<badPerson>::iterator it;
	it = badperson.begin() + id - 1;
	cout << "您击败了" << badperson[id - 1].getName()  << endl;
	badperson.erase(it);
}

badPerson room::getBadPerson(int id)
{
	return badperson[id - 1];
}

int room::getBadPersonSize()
{
	return badperson.size();
}



room::~room()
{
}
