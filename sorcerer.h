#ifndef _SORCERER_H
#define _SORCERER_H
#include <vector>
#include <string>
#include "Equipment.h"
#include "Horcrux.h"
#include <iostream>
#include "Skill.h"
#include "Person.h"
#include "badPerson.h"
#include <cstdlib>
#include <ctime>
#include "room.h"
#include "Medicine.h"
#include "Magicitem.h"
using namespace std;

class sorcerer :
	public Person
{
public:
	sorcerer();
	~sorcerer();
	void setValue(double disguiseValue = 0, double forceValue = 0, double defenceValue = 0, double magicValue = 0, double bloodValue = 0, string name = 0, double money = 0);
	bool isSkillEmpty();
	void increaseBlood(int blood);
	void decreaseBlood(int blood);
	void setBlood(int blood);
	void addSkill(Skill s);
	void increaseSkillNum();
	void showInformation();
	bool battle(sorcerer *mySorcerer, badPerson badperson);
	void inRoom(room *myroom);
	void increaseMoney(int money);
	void decreaseMoney(int money);
	void addMedicine(Medicine temp);
	void showMedicine();
	void addMagicitem(Magicitem temp);
	void showMagicItem();
	bool isHasTheMagicitem(int id);
	void useMedicine(int op = 0);
	void setMyCheckPoint(int temp = 0);
	int getDisguiseValue();
	int getBloodValue();
	int getForceValue();
	int getDefenceValue();
	int getMagicValue();
	int getMoney();
	room *getRoom();
	string getName();
	vector<Magicitem> getMagicitem();
	vector<Skill> getSkill();
	vector<Horcrux> getHorcrux();
	vector<Medicine> getMedicine();
	int getSkillNum();
	int getEquipmentNum();
	int getHorcruxNum();
	int getMyCheckpoint();
private:
	int disguiseValue;	
	int forceValue;
	int defenceValue;
	int magicValue;
	int bloodValue;
	int money;
	string name;
	vector<Magicitem>magicitem;
	vector<Horcrux>horcrux;
	vector<Skill>skill;
	vector<Medicine>medicine;
	int skillNum;
	int equipmentNum;
	int horcruxNum;
	room *myroom;
	int myCheckpoint;
};
#endif