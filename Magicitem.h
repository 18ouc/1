#pragma once
#include "Equipment.h"
class Magicitem :
	public Equipment
{
public:
	Magicitem(string name = 0, int id = 0);
	~Magicitem();
	string getName();
	int getId();
private:
	string name;
	int id;
};

