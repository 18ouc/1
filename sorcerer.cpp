#include "sorcerer.h"

sorcerer::sorcerer(){
	cout << "人物创建成功！" << endl;
	skillNum = 0;
	equipmentNum = 0;
	horcruxNum = 0;
	magicitemNum = 0;
	horcruxNum = 0;
	myCheckpoint = 0;
}

sorcerer::~sorcerer() {
}

void sorcerer::setValue(double disguiseValue, double forceValue, double defenceValue, double magicValue, double bloodValue, string name, double money) {
	this->disguiseValue = disguiseValue;
	this->forceValue = forceValue;
	this->defenceValue = defenceValue;
	this->magicValue = magicValue;
	this->bloodValue = bloodValue;
	this->name = name;
	this->money = money;
	cout << "人物" << name << "设置成功！" << endl;
	cout << "你所选择的人物初始属性如下：" << endl;
	cout << "伪装值 = " << disguiseValue << endl;
	cout << "武力值 = " << forceValue << endl;
	cout << "防御值 = " << defenceValue << endl;
	cout << "魔法值 = " << disguiseValue << endl;
	cout << "伪装值 = " << magicValue << endl;
	cout << "血量   = " << bloodValue << endl;
	cout << "金币   = " << money << endl;
}

bool sorcerer::isSkillEmpty() {
	if (skill.empty())
		return 1;
	else return 0;
}

int sorcerer::getSkillNum() {
	return skillNum;
}

int sorcerer::getEquipmentNum() {
	return equipmentNum;
}

int sorcerer::getHorcruxNum() {
	return horcruxNum;
}

int sorcerer::getMyCheckpoint() {
	return myCheckpoint;
}

int sorcerer::getMedicineNum() {
	return medicineNum;
}

void sorcerer::changeMedicineNum() {
	medicineNum = medicine.size();
}

void sorcerer::setMyCheckpoint(int temp) {
	myCheckpoint = temp;
}

vector<Skill> sorcerer::getSkill() {
	return skill;
}

vector<Horcrux> sorcerer::getHorcrux() {
	return horcrux;
}

vector<Medicine> sorcerer::getMedicine() {
	return medicine;
}

int sorcerer::getMagicitemNum() {
	return magicitemNum;
}

int sorcerer::getBloodValue() {
	return bloodValue;
}

int sorcerer::getForceValue() {
	return forceValue;
}

int sorcerer::getDefenceValue() {
	return defenceValue;
}

int sorcerer::getMagicValue() {
	return magicValue;
}

int sorcerer::getMoney() {
	return money;
}

void sorcerer::increaseBlood(int blood) {
	bloodValue += blood;
	cout << "你的血量增加了" << blood << endl;
}

void sorcerer::decreaseBlood(int blood) {
	bloodValue -= blood;
	cout << "你的血量减少了" << blood << endl;
}

void sorcerer::setBlood(int blood) {
	this->bloodValue = blood;
}

void sorcerer::addSkill(Skill mySkill) {
	cout << "恭喜您获得技能：" << mySkill.getName() << endl;
	skill.push_back(mySkill);
	this->increaseSkillNum();
}

void sorcerer::increaseSkillNum() {
	skillNum++;
}

void sorcerer::showInformation() {
	cout << "当前您的属性情况如下：" << endl;
	cout << "伪装值 = " << disguiseValue << endl;
	cout << "武力值 = " << forceValue << endl;
	cout << "防御值 = " << defenceValue << endl;
	cout << "魔法值 = " << disguiseValue << endl;
	cout << "伪装值 = " << magicValue << endl;
	cout << "血量   = " << bloodValue << endl;
	cout << "金币   = " << money << endl;
}

bool sorcerer::battle(sorcerer * mySorcerer, badPerson badperson) {
	double otherBloodNum = badperson.getblood();
	int otherDamageNum_Down = badperson.getDown();
	int otherDamageNum_Up = badperson.getUp();
	string otherName = badperson.getName();
	double mySorcererDamage = 0;
	double otherSorcererDamage = 0;
	double mySorcererBlood = mySorcerer->getBloodValue();
	int ii = 1;//代表战斗的轮次数
	srand(time(NULL));
	while (1) {
		system("pause");
		system("cls");
		if (mySorcerer->isSkillEmpty())
			cout << "您目前没有任何技能" << endl;
		else {
			cout << "您目前拥有的技能：" << endl;
			for (int i = 1; i <= mySorcerer->getSkillNum(); i++) {
				cout << i << "." << mySorcerer->getSkill()[i - 1].getName() << endl;
			}
		}
		cout << "第" << ii << "轮战斗" << endl;
		cout << "此时您的血量为" << mySorcererBlood << endl;
		cout << otherName << "的血量为" << otherBloodNum << endl;
		cout << "请输入数字使用技能，输入0代表使用普通攻击" << endl;
		int op = 0;
		double damage = 0;
		cin >> op;
		system("cls");
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
	}
}

void sorcerer::inRoom(room * myroom) {
	this->myroom = myroom;
}

void sorcerer::increaseMoney(int money) {
	this->money += money;
	cout << "你的金币增加" << money << endl;
}

void sorcerer::decreaseMoney(int money) {
	this->money -= money;
	cout << "你的金币减少" << money << endl;
}

void sorcerer::addMedicine(Medicine temp) {
	medicine.push_back(temp);
	cout << "恭喜你获得了：" << temp.getName() << endl;
}

void sorcerer::showMedicine() {
	if (medicine.empty()) {
		cout << "你目前没有任何药水" << endl;
	}
	else {
		cout << "你目前拥有的药水：" << endl;
		for (int i = 0; i < medicine.size(); i++) {
			cout << i + 1 << ".名称:" << medicine[i].getName() << " 价格:" << medicine[i].getPrice() << " 恢复值：" << medicine[i].getRecoverValue() << endl;
		}
	}
	int op = 0;
	cout << "请输入你想要使用药品的编号（按0退出）" << endl;
	cin >> op;
	if (op == 0) {
		cout << "查看结束" << endl;
	}
	else {
		useMedicine(op);
	}
}

void sorcerer::addMagicitem(Magicitem temp) {
	magicitem.push_back(temp);
	cout << "恭喜你获得了：" << temp.getName() << endl;
	magicitemNum = magicitem.size();
}

void sorcerer::addHorcrux(Horcrux temp) {
	horcrux.push_back(temp);
	cout << "恭喜你获得了：" << temp.getName() << endl;
}

void sorcerer::showMagicItem() {
	if (magicitem.empty()) {
		cout << "你目前没有任何魔法道具" << endl;
	}
	else {
		cout << "你目前拥有的道具：" << endl;
		for (int i = 0; i < magicitem.size(); i++) {
			cout << i + 1 << ".名称:" << magicitem[i].getName() << endl;
		}
	}
}

bool sorcerer::isHasTheMagicitem(int id) {
	bool temp = 0;
	for (int i = 0; i < magicitem.size(); ++i) {
		if (id == magicitem[i].getId())
			temp = 1;
	}
	return temp;
}

void sorcerer::useMedicine(int op) {
	vector<Medicine>::iterator it;
	it = medicine.begin() + op - 1;
	cout << "您使用了" << medicine[op - 1].getName() << ",血量增加了" << medicine[op - 1].getRecoverValue() << endl;
	this->increaseBlood(medicine[op - 1].getRecoverValue());
	medicine.erase(it);
	this->changeMedicineNum();
}

void sorcerer::setMyCheckPoint(int temp) {
	myCheckpoint = temp;
}

void sorcerer::afterDead() {
	cout << "由于你的游戏中死亡，系统给了你一些关怀，请拿着他们继续战斗吧！" << endl;
	this->setBlood(1);
	cout << "系统给了你一点血量" << endl;
	Medicine temp("关怀药水", 25, 0);
	this->addMedicine(temp);
	this->increaseMoney(1500);
}

int sorcerer::getDisguiseValue() {
	return disguiseValue;
}

room * sorcerer::getRoom() {
	return myroom;
}

string sorcerer::getName() {
	return name;
}

vector<Magicitem> sorcerer::getMagicitem() {
	return magicitem;
}