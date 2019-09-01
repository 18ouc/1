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
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G2.push_back(medicineTempSmall);
	medicine_G2.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G2.push_back(medicineTempMiddle);
	medicine_G2.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G2.push_back(medicineTempLarge);
	Shop shop_G2(medicine_G2, "��ÿռ�ħ����Ʒ��", 5);
	bool check = 1;
	room Crypt("��Ѩ");
	room bathroom("ϴ�ּ�");
	room chamber("����");
	room hathouse("ñ����");
	Magicitem phoenix("���", 2);
	map map2("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*��Ѩ\t*\t < --------------->\t*1.ϴ�ּ�\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t\t\t\t\t\t / \\\n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t || \n\t\t\t\t\t\t   \\ / \n\t\t\t\t\t\t*********\n\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t*2.����\t*\n\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t*********");
	cout << "ѧУ������һϵ�С��ֲ����¼���ѧ��Ī�����ʯ��\nǽ�ϳ����˿ֲ���Ѫ��...\n���ǻ������߹���Ϊ\n��˵�е����ұ�˹�����ֵļ̳��˴�\n������Ϊ������ǻ�������˻��ɡ�������������" << endl;
	system("pause");
	system("cls");
	cout << "��ӭ����ڶ���~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom() << endl;
	cout << "��˵��ϴ�ּ���ҽ���Ի����Ի�����صĶ���..." << endl;
	goodPerson Moaning_Myrtle("�ҽ���", "��ϴ����������Ķ���...��ʱ�Ҿ�����Ϊ���������۾���...\n");
	bathroom.addGoodPerson(Moaning_Myrtle);
	badPerson Basilisk(100, 10, 35, "�߹�");
	//badPerson Kerberos(20, 0, 5, "��ͷ��");
	chamber.addBadPerson(Basilisk);
	while (check) {
		system("pause");
		system("cls");
		cout << "����100���Բ鿴��ǰ�Լ�������" << endl;
		cout << "����101���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "����102���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "����103���Խ���ؿ��ĵ���" << endl;
		cout << "����110���Ա��浱ǰ����" << endl;
		cout << "����111�����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ���Ͻǵ����ֿ��Խ���õ�ͼ" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map2.showMap();
		cout << "����������ѡ��:" << endl;
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
			cout << "��δ����" << endl;
			break;
		case 111:
			cout << "���Ѿ���������Ϸ��" << endl;
			return -1;
			break;
		default:
			cout << "����ʧ�ܣ�" << endl;
			break;
		case 1:
			mySorcerer->inRoom(&bathroom);
			system("cls");
			cout << "��ӭ���� " << bathroom.getName() << endl;
			if (bathroom.getIfIn()) {
				cout << "��ӭ���ٴ����� " << bathroom.getName() << endl;
				break;
			}
			cout << "\n" << Moaning_Myrtle.getName() << "��" << Moaning_Myrtle.getSentence() << endl;
			cout << "����" << Moaning_Myrtle.getName() << "������̸��֮�� �����Լ�ӵ�����" << endl;
			/*mySorcerer->addSkill(Alohomora);
			mySorcerer->increaseSkillNum();*/
			bathroom.inRoom();
			break;
		case 2:
			mySorcerer->inRoom(&hathouse);
			system("cls");
			cout << "��ӭ���� " << hathouse.getName() << endl;
			if (bathroom.getIfIn()) {
				cout << "��ӭ���ٴ����� " << hathouse.getName() << endl;
				break;
			}
			cout << "ֻ����������ʿ���ܵõ�" << phoenix.getName() << endl;
			cout << "������������ʿ��" << endl;
			mySorcerer->addMagicitem(phoenix);
			hathouse.inRoom();
			break;
		case 3:
			mySorcerer->inRoom(&chamber);
			system("cls");
			cout << "��ӭ���� " << chamber.getName() << endl;
			cout << "��ʱ��ķ������������Ƿ�ѡ���������жԻ���" << endl;
			cout << "1.��		2.��" << endl;
			int op1 = 0;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "���� Tom Marvolo Riddle������֮���� Lord Voldemort(����ħ)������\n˿˿˹˹~\n��ͨ�������ٻ������߹֡�����" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->isHasTheMagicitem(2);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "��ͨ����˴�Ϲ��" << Basilisk.getName() << "���۾���������������ս��......" << endl;
					system("pause");
					system("cls");
					cout << "��ʱ����ս���������������Ƿ�ѡ����������ս����" << endl;
					cout << "1.��		2.��" << endl;
					int op2 = 0;
					cin >> op2;
					system("cls");
					if (op2 == 1) {
						bool ifWin = 0;
						cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
						ifWin = mySorcerer->battle(mySorcerer, Basilisk);
						if (ifWin) {
							cout << "��ϲ��ɹ�ͨ���ڶ��ز������";
						}
						else {
							cout << "caicaicai" << endl;
						}
					}
					else if (op2 == 2) {
						cout << "���Ѿ�����ս����" << endl;
					}
					else {
						cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
					}
				}
				else {
					cout << "�㱻�������۾���ɱ������\n" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "���Ѿ����������Ի���" << endl;
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
			}
			break;
		}
	}
	return 1;
}
#endif