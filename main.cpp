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
	//streampos fp = file.tellg(); //fp为文件指针的偏移量
	string temp_file;
	Plot myPlot;
	bool ifNew = 0;
	while (1) {
		mySorcerer->setMyCheckPoint(0);
		cout << "Harry		Potter" << endl;
		cout << "1.新的旅途			2.读取存档			3.退出" << endl;
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
			//file.seekg(0, ios::end); //将文件指针指向文件末端
			if (!file) {// 偏移量为0，证明文件为空，为首次进入系统
				cout << "你目前没有任何存档" << endl;
				system("pause");
				system("cls");
				break;
			}
			while (!file.eof()) //或 if ( ch==EOF )  //一个字符都未读到，表示文件为空
			{
				file >> temp_file;
				myFiles.push_back(temp_file);
			}
			myFiles.pop_back();
			cout << "你目前拥有的存档为：" << endl;
			for (int i = 0; i < myFiles.size(); ++i) {
				cout << i + 1 << "." << myFiles[i] << endl;
			}
			cout << "请输入你想要读取的存档：" << endl;
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
			mySorcerer->setMyCheckPoint(myCheckpoint);	//设置目前在哪个关卡
			tempMedicine.setInformation(tempMedicineName, tempRecoverValue, tempMedicinePrice);
			infile >> myCheckpoint;
			cout << "人物状态初始化完毕！" << endl;
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
				cout << "出现错误！" << endl;
				break;
			}
			break;
		case 3:
			cout << "你已经成功退出游戏。" << endl;
			return 0;
		default:
			cout << "输入错误请重新输入！" << endl;
		}
	}
	delete mySorcerer;
}