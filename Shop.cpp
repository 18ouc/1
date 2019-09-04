#include "Shop.h"

Shop::Shop(vector<Medicine> medicine, vector<Skill> skill, string name, int medicineNumber, int skillNumber) : name(name), medicine(medicine), medicineNumber(medicineNumber), skill(skill), skillNumber(skillNumber) {
}

void Shop::buy(sorcerer * mysorcerer, int choice) {
	if (choice == 1) {
		cout << "��������Ҫ�����ҩƿ��ţ�(��0�˳���" << endl;
		int op;
		cin >> op;
		if (op == 0) {
			cout << "��ӭ���Ĺ��٣�" << endl;
		}
		else if (mysorcerer->getMoney() < medicine[op - 1].getPrice()) {
			cout << "��Ľ�Ҳ��㣡�޷�����" << endl;
		}
		else {
			vector<Medicine>::iterator it;
			it = medicine.begin() + op - 1;
			cout << "��������" << medicine[op - 1].getName() << ",������" << medicine[op - 1].getPrice() << endl;
			mysorcerer->decreaseMoney(medicine[op - 1].getPrice());
			mysorcerer->addMedicine(medicine[op - 1]);
			mysorcerer->changeMedicineNum();
			medicine.erase(it);
			medicineNumber--;
		}
	}
	else if (choice == 2) {
		cout << "��������Ҫ����ļ��ܱ�ţ�(��0�˳���" << endl;
		int op;
		cin >> op;
		if (op == 0) {
			cout << "��ӭ���Ĺ��٣�" << endl;
		}
		else if (mysorcerer->getMoney() < skill[op - 1].getPrice()) {
			cout << "��Ľ�Ҳ��㣡�޷�����" << endl;
		}
		else {
			vector<Skill>::iterator it;
			it = skill.begin() + op - 1;
			cout << "��������" << skill[op - 1].getName() << ",������" << skill[op - 1].getPrice() << endl;
			mysorcerer->decreaseMoney(skill[op - 1].getPrice());
			mysorcerer->addSkill(skill[op - 1]);
			skill.erase(it);
			skillNumber--;
		}
	}
	else if(choice == 0){
		cout << "��ӭ���Ĺ��٣�" << endl;
	}
	else {
		cout << "�������" << endl;
	}
}

void Shop::showShop(sorcerer * mysorcerer) {
	cout << "��ӭħ��ʦ" << mysorcerer->getName() << "�����̵꣡����" << endl;
	cout << "Ŀǰ�̵�Ĵ�����:" << endl;
	cout << "ҩˮ��" << endl;
	for (int i = 0; i < medicine.size(); i++) {
		cout << i + 1 << ".���ƣ�" << medicine[i].getName()  << " �۸�" << medicine[i].getPrice() << " �ָ�ֵ��" << medicine[i].getRecoverValue() << endl;
	}
	cout << "���ܣ�" << endl;
	for (int i = 0; i < skill.size(); i++) {
		cout << i + 1 << ".���ƣ�" << skill[i].getName() << " �۸�" << skill[i].getPrice() << " �˺���" << skill[i].getDamage() << endl;
	}
	int op = 0;
	cout << "���������ѡ��" << endl;
	cout << "1.����ҩˮ		2.������		0.�˳�����" << endl;
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
