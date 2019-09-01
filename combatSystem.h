#ifndef _COMBATSYSTEM
#define _COMBATSYSTEM
#include <iostream>
#include <string>
#include "sorcerer.h"
#include <cstdlib>
#include <ctime>
#include "badPerson.h"
using namespace std;

//己方获胜返回1，敌方获胜返回2
bool battle(sorcerer *mySorcerer, badPerson &badperson) {
	double otherBloodNum = badperson.getblood();
	int otherDamageNum_Down = badperson.getDown();
	int otherDamageNum_Up = badperson.getUp();
	string otherName = badperson.getName();
	if (mySorcerer->isSkillEmpty())
		cout << "您目前没有任何技能" << endl;
	else
	{
		cout << "您目前拥有的技能：" << endl;
		for (int i = 1; i <= mySorcerer->getSkillNum(); i++) {
			cout << i << "." << mySorcerer->getSkill()[i - 1].getName() << endl;
		}
	}
	double mySorcererDamage = 0;
	double otherSorcererDamage = 0;
	double mySorcererBlood = mySorcerer->getBloodValue();
	int ii = 1;//代表战斗的轮次数
	srand(time(NULL));
	while (1) {
		if (mySorcererBlood == 0) {
			if (otherBloodNum == 0) {
				cout << "双方同归于尽。" << endl;
			}
			cout << "很遗憾，您的本场战斗失败。。。" << endl;
			return 0;
		}
		else if (otherSorcererDamage >= otherBloodNum) {
			mySorcerer->setBlood(mySorcererBlood);
			cout << "恭喜你，您成功打败了" << otherName << "!!!" << endl;
			return 1;
		}
		system("pause");
		system("cls");
		if (mySorcerer->isSkillEmpty())
			cout << "您目前没有任何技能" << endl;
		else
		{
			cout << "您目前拥有的技能：" << endl;
			for (int i = 1; i <= mySorcerer->getSkillNum(); i++) {
				cout << i << "." << mySorcerer->getSkill()[i - 1].getName() << endl;
			}
		}
		if (mySorcerer->isSkillEmpty())
			cout << "您目前没有任何技能" << endl;
		else
		{
			cout << "您目前拥有的技能：" << endl;
			for (int i = 1; i <= mySorcerer->getSkillNum(); i++) {
				cout << i << "." << mySorcerer->getSkill()[i - 1].getName() << endl;
			}
		}
		cout << "第" << ii << "轮战斗" << endl;
		cout << "请输入数字使用技能，输入0代表使用普通攻击" << endl;
		int op = 0;
		double damage = 0;
		cin >> op;
		if (op) {
			double skillDamage = mySorcerer->getSkill()[op - 1].getDamage();
			cout << "您在第" << ii << "轮战斗中使用了" << mySorcerer->getSkill()[op - 1].getName() << ",";
			damage = mySorcerer->getForceValue() + skillDamage - 100 + rand() % 5;
		}	
		else if (!op) {
			cout << "您在第" << ii << "轮战斗中使用了普通攻击" << ",";
			damage = mySorcerer->getForceValue() - 100 + rand() % 5;
		}
		cout << "对对手造成了" << damage << "伤害。" << endl;
		double damage_other = (rand() % (otherDamageNum_Up - otherDamageNum_Down + 1)) + otherDamageNum_Down;
		cout << otherName << "在第" << ii << "轮战斗中对您造成" << damage_other << "伤害" << endl;
		mySorcererBlood -= damage_other;
		otherBloodNum -= damage;
		if (mySorcererBlood < 0)
			mySorcererBlood = 0;
		if (otherBloodNum < 0)
			otherBloodNum = 0;
		cout << "第" << ii << "轮战斗结束\n" << 
			"您的血量为" << mySorcererBlood << endl;
		cout << otherName << "的血量为" << otherBloodNum << endl;
		ii++;
	}
}
#endif
