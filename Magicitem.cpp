#include "Magicitem.h"




Magicitem::Magicitem(string name,int id) : name(name), id(id)
{
}


Magicitem::~Magicitem()
{
}

string Magicitem::getName()
{
	return name;
}

int Magicitem::getId()
{
	return id;
}
