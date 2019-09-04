#include "badPerson.h"

badPerson::~badPerson() {
}

double badPerson::getblood() {
	return blood;
}

double badPerson::getDown() {
	return down;
}

double badPerson::getUp() {
	return up;
}

string badPerson::getName() {
	return name;
}

void badPerson::setValue(double blood, double down, double up, string name) {
	this->blood = blood;
	this->down = down;
	this->up = up;
	this->name = name;
}
