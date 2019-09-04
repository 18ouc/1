#ifndef _PLOT_H
#define _PLOT_H
#include <iostream>
#include <string>
#include "sorcerer.h"
#include "map.h"
#include "Skill.h"
#include "badPerson.h"
#include "room.h"
#include "goodPerson.h"
#include "Medicine.h"
#include "Shop.h"
#include "Magicitem.h"
using namespace std;
class Plot
{
public:
	Plot();
	int init1(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);	//代表剧情1即第一关
	int init2(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init3(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init4(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init5(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init6(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int initFinal(sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	void init_new(sorcerer *mySorcerer);
	~Plot();
private:
	int id;
};
#endif

