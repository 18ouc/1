#ifndef _SKILL_H
#define _SKILL_H
#include <iostream>
#include <string>
using namespace std;
class Skill
{
public:
	Skill(string name = 0, double damage = 0) : name(name), damage(damage) {};
	~Skill();
	string getName();
	double getDamage();
private:
	string name;
	double damage;
};

#endif