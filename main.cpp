#include <iostream>
#include "sorcerer.h"
#include "Plot.h"
#include "File.h"
#include "Magicitem.h"
#include <vector>
#include <fstream>
using namespace std;
int main() {
	int disguiseValue = 0;
	int forceValue = 0;
	int defenceValue = 0;
	int magicValue = 0;
	int bloodValue = 0;
	int money = 0;
	string myName = " ";
	vector<Magicitem>magicitem;
	vector<Horcrux>horcrux;
	vector<Skill>skill;
	vector<Medicine>medicine;

	Magicitem tempMagicitem(" ", 0);
	string tempMagicitemName = " ";
	int tempMagicitemId = 0;

	Horcrux tempHorcrux(" ", 0);
	string tempHorcruxName = " ";
	int tempHorcruxId = 0;
	

	Skill tempSkill(" ", 0);
	string tempSkillName = " ";
	double tempSkillDamage = 0;

	Medicine tempMedicine(" ", 0, 0);
	string tempMedicineName = " ";
	int tempRecoverValue = 0;
	int tempMedicinePrice = 0;
	
	int skillNum = 0;
	int equipmentNum = 0;
	int horcruxNum = 0;
	int magicitemNum = 0;
	int medicineNum = 0;
	int myCheckpoint = 0;
	int op_file = 0;
	int ifEnd = 0;
	sorcerer *mySorcerer = new sorcerer;
	vector<string> myFiles;
	fstream file("myFiles.txt");
	fstream infile;
	//streampos fp = file.tellg(); //fpΪ�ļ�ָ���ƫ����
	string temp_file;
	Plot myPlot;
	bool ifNew = 0;
	while (1) {
		mySorcerer->setMyCheckPoint(0);
		cout << "Harry		Potter" << endl;
		cout << "1.�µ���;			2.��ȡ�浵			3.�˳�" << endl;
		int choice;
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			myPlot.init_new(mySorcerer);
			ifEnd = myPlot.init1(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			mySorcerer->setMyCheckPoint(2);
			ifEnd = myPlot.init2(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			mySorcerer->setMyCheckPoint(3);
			ifEnd = myPlot.init3(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			mySorcerer->setMyCheckPoint(4);
			ifEnd = myPlot.init4(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			mySorcerer->setMyCheckPoint(5);
			ifEnd = myPlot.init5(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			mySorcerer->setMyCheckPoint(6);
			ifEnd = myPlot.init6(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			mySorcerer->setMyCheckPoint(7);
			ifEnd = myPlot.initFinal(mySorcerer);
			if (ifEnd == -1) {
				break;
			}
			break;
		case 2:
			//file.seekg(0, ios::end); //���ļ�ָ��ָ���ļ�ĩ��
			if (!file) {// ƫ����Ϊ0��֤���ļ�Ϊ�գ�Ϊ�״ν���ϵͳ
				cout << "��Ŀǰû���κδ浵" << endl;
				system("pause");
				system("cls");
				break;
			}
			while (!file.eof()) //�� if ( ch==EOF )  //һ���ַ���δ��������ʾ�ļ�Ϊ��
			{
				file >> temp_file;
				myFiles.push_back(temp_file);
			}
			myFiles.pop_back();
			cout << "��Ŀǰӵ�еĴ浵Ϊ��" << endl;
			for (int i = 0; i < myFiles.size(); ++i) {
				cout << i + 1 << "." << myFiles[i] << endl;
			}
			cout << "����������Ҫ��ȡ�Ĵ浵��" << endl;
			cin >> op_file;

			infile.open(myFiles[op_file - 1]);
			infile >> disguiseValue >> forceValue >> defenceValue >> magicValue >> bloodValue >> money >> myName;
			mySorcerer->setValue(disguiseValue, forceValue, defenceValue, magicValue, bloodValue, myName, money);

			infile >> magicitemNum;
			for (int i = 0; i < magicitemNum; i++) {
				infile >> tempMagicitemName >> tempMagicitemId;
				tempMagicitem.setValue(tempMagicitemName, tempMagicitemId);
				mySorcerer->addMagicitem(tempMagicitem);
			}

			infile >> horcruxNum;
			for (int i = 0; i < horcruxNum; i++) {
				infile >> tempHorcruxName >> tempHorcruxId;
				tempHorcrux.setValue(tempHorcruxName, tempHorcruxId);
				mySorcerer->addHorcrux(tempHorcrux);
			}

			infile >> skillNum;
			for (int i = 0; i < skillNum; i++) {
				infile >> tempSkillName >> tempSkillDamage;
				tempSkill.setValue(tempSkillName, tempSkillDamage);
				mySorcerer->addSkill(tempSkill);
			}

			infile >> medicineNum;
			for (int i = 0; i < medicineNum; i++) {
				infile >> tempMedicineName >> tempRecoverValue >> tempMedicinePrice;
				tempMagicitem.setValue(tempMagicitemName, tempMagicitemId);
				mySorcerer->addMedicine(tempMedicine);
			}
			mySorcerer->setMyCheckPoint(myCheckpoint);	//����Ŀǰ���ĸ��ؿ�
			tempMedicine.setInformation(tempMedicineName, tempRecoverValue, tempMedicinePrice);
			infile >> myCheckpoint;
			cout << "����״̬��ʼ����ϣ�" << endl;
			file.close();
			infile.close();
			system("pause");
			system("cls");
			ifNew = 1;
			switch (myCheckpoint) {
			case 1:
				ifEnd = 0;
				ifEnd = myPlot.init1(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
				ifNew = 0;
				mySorcerer->setMyCheckPoint(2);
			case 2:
				ifEnd = 0;
				ifEnd = myPlot.init2(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
				ifNew = 0;
				mySorcerer->setMyCheckPoint(3);
			case 3:
				ifEnd = 0;
				ifEnd = myPlot.init3(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
				ifNew = 0;
				mySorcerer->setMyCheckPoint(4);
			case 4:
				ifEnd = 0;
				ifEnd = myPlot.init4(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
				ifNew = 0;
				mySorcerer->setMyCheckPoint(5);
			case 5:
				ifEnd = 0;
				ifEnd = myPlot.init5(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
				ifNew = 0;
				mySorcerer->setMyCheckPoint(6);
			case 6:
				ifEnd = 0;
				ifEnd = myPlot.init6(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
				ifNew = 0;
				mySorcerer->setMyCheckPoint(7);
			case 7:
				ifEnd = 0;
				ifEnd = myPlot.initFinal(mySorcerer, myCheckpoint, ifNew);
				if (ifEnd == -1) {
					break;
				}
			default:
				cout << "���ִ���" << endl;
				break;
			}
			break;
		case 3:
			cout << "���Ѿ��ɹ��˳���Ϸ��" << endl;
			return 0;
		default:
			cout << "����������������룡" << endl;
		}
	}
	delete mySorcerer;
}