#ifndef _SKILL_H
#define _SKILL_H
#include <iostream>
#include <string>
using namespace std;
class Skill {
public:
	Skill(string name = 0, int damage = 0, int price = 0);
	~Skill();
	string getName();
	int getDamage();
	void setValue(string name = 0, int damage = 0, int price = 0);
	int getPrice();
private:
	string name;
	int damage;
	int price;
};

#endif