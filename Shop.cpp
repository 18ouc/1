#include "Shop.h"

Shop::Shop(vector<Medicine> medicine, vector<Skill> skill, string name, int medicineNumber, int skillNumber) : name(name), medicine(medicine), medicineNumber(medicineNumber), skill(skill), skillNumber(skillNumber) {
}

void Shop::buy(sorcerer * mysorcerer, int choice) {
	if (choice == 1) {
		cout << "请输入您要购买的药瓶编号：(按0退出）" << endl;
		int op;
		cin >> op;
		if (op == 0) {
			cout << "欢迎您的光临！" << endl;
		}
		else if (mysorcerer->getMoney() < medicine[op - 1].getPrice()) {
			cout << "你的金币不足！无法购买！" << endl;
		}
		else {
			vector<Medicine>::iterator it;
			it = medicine.begin() + op - 1;
			cout << "您购买了" << medicine[op - 1].getName() << ",花费了" << medicine[op - 1].getPrice() << endl;
			mysorcerer->decreaseMoney(medicine[op - 1].getPrice());
			mysorcerer->addMedicine(medicine[op - 1]);
			mysorcerer->changeMedicineNum();
			medicine.erase(it);
			medicineNumber--;
		}
	}
	else if (choice == 2) {
		cout << "请输入您要购买的技能编号：(按0退出）" << endl;
		int op;
		cin >> op;
		if (op == 0) {
			cout << "欢迎您的光临！" << endl;
		}
		else if (mysorcerer->getMoney() < skill[op - 1].getPrice()) {
			cout << "你的金币不足！无法购买！" << endl;
		}
		else {
			vector<Skill>::iterator it;
			it = skill.begin() + op - 1;
			cout << "您购买了" << skill[op - 1].getName() << ",花费了" << skill[op - 1].getPrice() << endl;
			mysorcerer->decreaseMoney(skill[op - 1].getPrice());
			mysorcerer->addSkill(skill[op - 1]);
			skill.erase(it);
			skillNumber--;
		}
	}
	else if(choice == 0){
		cout << "欢迎您的光临！" << endl;
	}
	else {
		cout << "输入错误！" << endl;
	}
}

void Shop::showShop(sorcerer * mysorcerer) {
	cout << "欢迎魔法师" << mysorcerer->getName() << "进入商店！！！" << endl;
	cout << "目前商店的存货情况:" << endl;
	cout << "药水：" << endl;
	for (int i = 0; i < medicine.size(); i++) {
		cout << i + 1 << ".名称：" << medicine[i].getName()  << " 价格：" << medicine[i].getPrice() << " 恢复值：" << medicine[i].getRecoverValue() << endl;
	}
	cout << "技能：" << endl;
	for (int i = 0; i < skill.size(); i++) {
		cout << i + 1 << ".名称：" << skill[i].getName() << " 价格：" << skill[i].getPrice() << " 伤害：" << skill[i].getDamage() << endl;
	}
	int op = 0;
	cout << "请输入你的选择：" << endl;
	cout << "1.购买药水		2.购买技能		0.退出店铺" << endl;
	cin >> op;
	buy(mysorcerer, op);
}

vector<Medicine> Shop::getMedicine() {
	return medicine;
}

vector<Skill> Shop::getSkill()
{
	return skill;
}

int Shop::getMedicineNum() {
	return medicineNumber;
}

int Shop::getSkillNum() {
	return skillNumber;
}

void Shop::setValue(vector<Medicine> medicine, vector<Skill> skill, string name, int medicineNumber, int skillNumber) {
	this->medicine = medicine;
	this->skill = skill;
	this->name = name;
	this->medicineNumber = medicineNumber;
	this->skillNumber = skillNumber;
}
