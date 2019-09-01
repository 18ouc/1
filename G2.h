#ifndef _G2
#define _G2
#include <iostream>
#include <string>
#include "sorcerer.h"
#include "map.h"
#include "combatSystem.h"
#include "Skill.h"
#include "badPerson.h"
#include "room.h"
#include "goodPerson.h"
#include "shop.h"
using namespace std;

int init2(sorcerer *mySorcerer) {
	vector<Medicine> medicine_G2;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G2.push_back(medicineTempSmall);
	medicine_G2.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G2.push_back(medicineTempMiddle);
	medicine_G2.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G2.push_back(medicineTempLarge);
	Shop shop_G2(medicine_G2, "奇幻空间魔术用品店", 5);
	bool check = 1;
	room Crypt("地穴");
	room bathroom("洗手间");
	room chamber("密室");
	room hathouse("帽子屋");
	Magicitem phoenix("凤凰", 2);
	map map2("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*地穴\t*\t < --------------->\t*1.洗手间\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t\t\t\t\t\t / \\\n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t   \\ / \n\t\t\t\t\t\t*********\n\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t*2.密室\t*\n\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t*********");
	cout << "学校发生了一系列“恐怖”事件—学生莫名其妙被石化\n墙上出现了恐怖的血字...\n人们怀疑是蛇怪所为\n传说中的密室被斯莱特林的继承人打开\n哈利因为会蛇佬腔被所有人怀疑。。。。。。。" << endl;
	system("pause");
	system("cls");
	cout << "欢迎进入第二关~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom() << endl;
	cout << "据说与洗手间的桃金娘对话可以获得神秘的东西..." << endl;
	goodPerson Moaning_Myrtle("桃金娘", "盥洗池里有神奇的东西...当时我就是因为看到它的眼睛而...\n");
	bathroom.addGoodPerson(Moaning_Myrtle);
	badPerson Basilisk(100, 10, 35, "蛇怪");
	//badPerson Kerberos(20, 0, 5, "三头狗");
	chamber.addBadPerson(Basilisk);
	while (check) {
		system("pause");
		system("cls");
		cout << "输入100可以查看当前自己的属性" << endl;
		cout << "输入101可以查看或使用自己拥有的药品" << endl;
		cout << "输入102可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入103可以进入关卡的店铺" << endl;
		cout << "输入110可以保存当前进度" << endl;
		cout << "输入111可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图左上角的数字可以进入该地图" << endl;
		cout << "此关卡的地图：" << endl;
		map2.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		cin >> op;
		switch (op)
		{
		case 100:
			system("cls");
			mySorcerer->showInformation();
			break;
		case 101:
			system("cls");
			mySorcerer->showMedicine();
			break;
		case 102:
			system("cls");
			mySorcerer->showMagicItem();
			break;
		case 103:
			system("cls");
			shop_G2.showShop(mySorcerer);
			break;
		case 110:
			cout << "还未设置" << endl;
			break;
		case 111:
			cout << "你已经结束该游戏。" << endl;
			return -1;
			break;
		default:
			cout << "操作失败！" << endl;
			break;
		case 1:
			mySorcerer->inRoom(&bathroom);
			system("cls");
			cout << "欢迎来到 " << bathroom.getName() << endl;
			if (bathroom.getIfIn()) {
				cout << "欢迎您再次来到 " << bathroom.getName() << endl;
				break;
			}
			cout << "\n" << Moaning_Myrtle.getName() << "：" << Moaning_Myrtle.getSentence() << endl;
			cout << "在与" << Moaning_Myrtle.getName() << "进行完谈话之后， 发现自己拥有蛇语。" << endl;
			/*mySorcerer->addSkill(Alohomora);
			mySorcerer->increaseSkillNum();*/
			bathroom.inRoom();
			break;
		case 2:
			mySorcerer->inRoom(&hathouse);
			system("cls");
			cout << "欢迎来到 " << hathouse.getName() << endl;
			if (bathroom.getIfIn()) {
				cout << "欢迎您再次来到 " << hathouse.getName() << endl;
				break;
			}
			cout << "只有真正的勇士才能得到" << phoenix.getName() << endl;
			cout << "你是真正的勇士！" << endl;
			mySorcerer->addMagicitem(phoenix);
			hathouse.inRoom();
			break;
		case 3:
			mySorcerer->inRoom(&chamber);
			system("cls");
			cout << "欢迎来到 " << chamber.getName() << endl;
			cout << "此时汤姆正在密室里，你是否选择与它进行对话？" << endl;
			cout << "1.是		2.否" << endl;
			int op1 = 0;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "我是 Tom Marvolo Riddle，换言之我是 Lord Voldemort(伏地魔)！！！\n丝丝斯斯~\n他通过蛇语召唤出了蛇怪。。。" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->isHasTheMagicitem(2);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "你通过凤凰戳瞎了" << Basilisk.getName() << "的眼睛。可以与它进行战斗......" << endl;
					system("pause");
					system("cls");
					cout << "此时蛇妖战斗力被大削，你是否选择与它进行战斗？" << endl;
					cout << "1.是		2.否" << endl;
					int op2 = 0;
					cin >> op2;
					system("cls");
					if (op2 == 1) {
						bool ifWin = 0;
						cout << "战斗开始，你已进入战斗模式..." << endl;
						ifWin = mySorcerer->battle(mySorcerer, Basilisk);
						if (ifWin) {
							cout << "恭喜你成功通过第二关并获得了";
						}
						else {
							cout << "caicaicai" << endl;
						}
					}
					else if (op2 == 2) {
						cout << "你已经逃离战斗。" << endl;
					}
					else {
						cout << "操作失败，你已退出该房间！" << endl;
					}
				}
				else {
					cout << "你被蛇妖的眼睛秒杀。。。\n" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "你已经逃离与他对话。" << endl;
			}
			else {
				cout << "操作失败，你已退出该房间！" << endl;
			}
			break;
		}
	}
	return 1;
}
#endif