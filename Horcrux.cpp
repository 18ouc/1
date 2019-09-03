#include "Horcrux.h"






Horcrux::Horcrux(string name, int id) : name(name), id(id)
{
}

Horcrux::~Horcrux()
{
}

string Horcrux::getName()
{
	return name;
}

int Horcrux::getId()
{
	return id;
}
