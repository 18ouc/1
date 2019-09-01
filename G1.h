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
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G1.push_back(medicineTempSmall);
	medicine_G1.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G1.push_back(medicineTempMiddle);
	medicine_G1.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G1.push_back(medicineTempLarge);
	Shop shop_G1(medicine_G1, "��Ƥʿħ����Ʒ��", 5);
	Skill Alohomora("Alohomora", 10);
	bool check = 1;
	room hall("����");
	room President_Office("У����");
	room Crypt("��Ѩ");
	room Attic("��¥");

	s->inRoom(&hall);
	map map1("\t\t\t\t\t\t\t\t2.***************\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t****\t��¥\t***\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t*******************\n\n1.********\n***\t***\n***У����**\n***\t***\n***********\n");
	cout << "���±���..." << endl;
	cout << "��ӭ�����һ��~" << endl;
	cout << "��ϲ���ڿ��ֻ����һ����������ͨ��������ĳ������..." << endl;
	goodPerson Dumbledore("�˲�����", "���쾵�Ӿ�Ҫ�ᵽһ���µĵط��ˣ������������㲻Ҫ��ȥ�����ˡ�������������ɿ���������Ҫ������׼����\n");
	President_Office.addGoodPerson(Dumbledore);
	badPerson Chiro(100, 10, 35, "����");
	badPerson Kerberos(20, 0, 5, "��ͷ��");
	Crypt.addBadPerson(Chiro);
	
	while (check){
		system("pause");
		system("cls");
		cout << "����100���Բ鿴��ǰ�Լ�������" << endl;
		cout << "����101���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "����102���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�װ��" << endl;
		cout << "����103���Խ���ؿ��ĵ���" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << s->getRoom()->getName() << endl;
		cout << "�����ͼ���Ͻǵ����ֿ��Խ���õ�ͼ" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map1.showMap();
		cout << "����������ѡ��:" << endl;
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
			cout << "����ʧ�ܣ�" << endl;
			break;
		case 1:
			s->inRoom(&President_Office);
			system("cls");
			cout << "��ӭ���� " << President_Office.getName() << endl;	
			if (President_Office.getIfIn()) {
				cout << "��ӭ���ٴ����� " << President_Office.getName() << endl;
				break;
			}
			cout << "\n" << Dumbledore.getName() << "��" << Dumbledore.getSentence()  << endl;
			cout << "����" << Dumbledore.getName() << "������̸��֮�� �����һ�����" << endl;
			s->addSkill(Alohomora);
			s->increaseSkillNum();
			President_Office.inRoom();
			break;
		case 2:
			s->inRoom(&Attic);
			system("cls");
			cout << "��ӭ���� " << Attic.getName() << endl;
			cout << "��ʱ��ͷ�����ڿ���ĳ�����䣬���Ƿ�ѡ����������ս����" << endl;
			cout << "1.��		2.��" << endl;
			int op1 = 0;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "ս���Ѿ���ʼ��" << endl;
				bool ifWin = 1;
				ifWin = s->battle(s, Kerberos);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "��ͨ��ս�����ɽ����" << Kerberos.getName() << "����ͨ�����ŵ�����ɹ������Ѩ......" << endl;
					system("pause");
					system("cls");
					cout << "��ӭ������Ѩ~" << endl;
					s->inRoom(&Crypt);
					cout << "��ʱ�������ھ����ԣ����Ƿ�ѡ����������ս����" << endl;
					cout << "1.��		2.��" << endl;
					int op2 = 0;
					cin >> op2;
					system("cls");
					if (op2 == 1) {
						bool ifWin = 0;
						cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
						ifWin = s->battle(s, Chiro);
						if (ifWin) {
							cout << "��ϲ��ɹ�ͨ����һ�ز������";
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
					cout << "caicaicai" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "���Ѿ�����ս����" << endl;
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
			}
			break;
		}
	}
}
#endif