#ifndef _G1
#define _G1
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
using namespace std;

void init1(sorcerer *s) {
	vector<Medicine> medicine_G1;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G1.push_back(medicineTempSmall);
	medicine_G1.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G1.push_back(medicineTempMiddle);
	medicine_G1.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G1.push_back(medicineTempLarge);
	Shop shop_G1(medicine_G1, "西皮士魔术用品店", 5);
	Skill Alohomora("Alohomora", 10);
	bool check = 1;
	room hall("大厅");
	room President_Office("校长室");
	room Crypt("地穴");
	room Attic("阁楼");

	s->inRoom(&hall);
	map map1("\t\t\t\t\t\t\t\t2.***************\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t****\t阁楼\t***\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t*******************\n\n1.********\n***\t***\n***校长室**\n***\t***\n***********\n");
	cout << "故事背景..." << endl;
	cout << "欢迎进入第一关~" << endl;
	cout << "恭喜你在开局获得了一个咒语，你可以通过它进入某个房间..." << endl;
	goodPerson Dumbledore("邓布利多", "明天镜子就要搬到一个新的地方了，哈利，我请你不要再去找它了。如果你哪天碰巧看见它，你要有心理准备。\n");
	President_Office.addGoodPerson(Dumbledore);
	badPerson Chiro(100, 10, 35, "奇洛");
	badPerson Kerberos(20, 0, 5, "三头狗");
	Crypt.addBadPerson(Chiro);
	
	while (check){
		system("pause");
		system("cls");
		cout << "输入100可以查看当前自己的属性" << endl;
		cout << "输入101可以查看或使用自己拥有的药品" << endl;
		cout << "输入102可以查看自己目前已经拥有的装备" << endl;
		cout << "输入103可以进入关卡的店铺" << endl;
		cout << "你目前所在的位置为：" << s->getRoom()->getName() << endl;
		cout << "输入地图左上角的数字可以进入该地图" << endl;
		cout << "此关卡的地图：" << endl;
		map1.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		cin >> op;
		switch (op)
		{
		case 100:
			system("cls");
			s->showInformation();
			break;
		case 101:
			system("cls");
			s->showMedicine();
			break;
		case 103:
			system("cls");
			shop_G1.showShop(s);
			break;
		default:
			cout << "操作失败！" << endl;
			break;
		case 1:
			s->inRoom(&President_Office);
			system("cls");
			cout << "欢迎来到 " << President_Office.getName() << endl;	
			if (President_Office.getIfIn()) {
				cout << "欢迎您再次来到 " << President_Office.getName() << endl;
				break;
			}
			cout << "\n" << Dumbledore.getName() << "：" << Dumbledore.getSentence()  << endl;
			cout << "在与" << Dumbledore.getName() << "进行完谈话之后， 获得了一个咒语。" << endl;
			s->addSkill(Alohomora);
			s->increaseSkillNum();
			President_Office.inRoom();
			break;
		case 2:
			s->inRoom(&Attic);
			system("cls");
			cout << "欢迎来到 " << Attic.getName() << endl;
			cout << "此时三头狗正在看守某个房间，你是否选择与它进行战斗？" << endl;
			cout << "1.是		2.否" << endl;
			int op1 = 0;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "战斗已经开始！" << endl;
				bool ifWin = 1;
				ifWin = s->battle(s, Kerberos);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "你通过战斗轻松解决了" << Kerberos.getName() << "。并通过开门的咒语成功进入地穴......" << endl;
					system("pause");
					system("cls");
					cout << "欢迎来到地穴~" << endl;
					s->inRoom(&Crypt);
					cout << "此时奇洛正在镜子旁，你是否选择与它进行战斗？" << endl;
					cout << "1.是		2.否" << endl;
					int op2 = 0;
					cin >> op2;
					system("cls");
					if (op2 == 1) {
						bool ifWin = 0;
						cout << "战斗开始，你已进入战斗模式..." << endl;
						ifWin = s->battle(s, Chiro);
						if (ifWin) {
							cout << "恭喜你成功通过第一关并获得了";
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
					cout << "caicaicai" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "你已经逃离战斗。" << endl;
			}
			else {
				cout << "操作失败，你已退出该房间！" << endl;
			}
			break;
		}
	}
}
#endif