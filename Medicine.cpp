#include "Medicine.h"


string Medicine::getName()
{
	return name;
}

int Medicine::getRecoverValue()
{
	return recoverValue;
}

int Medicine::getPrice()
{
	return price;
}

void Medicine::setInformation(string name, int recoverValue, double price)
{
	this->name = name;
	this->recoverValue = recoverValue;
	this->price = price;
}
