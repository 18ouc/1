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
	void setValue(string name = 0, int id = 0);
private:
	string name;
	int id;
};

