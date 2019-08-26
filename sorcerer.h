#ifndef _SORCERER_H
#define _SORCERER_H
#include <vector>
#include <string>
#include "Equipment.h"
#include "Horcrux.h"
using namespace std;

class sorcerer
{
public:
	sorcerer();
	~sorcerer();
	void attack(sorcerer s);
	void attack(string name);
	void showInformation();
	void increase(string name);
	void decrease(string name);
	void showMap(int num);
private:
	double disguiseValue;
	double forceValue;
	double defenceValuie;
	double magicValue;
	double bloodValue;
	vector<Equipment>equipment;
	vector<Horcrux>horcrux;
};
#endif
