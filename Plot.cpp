#include "Plot.h"

int Plot::init1(sorcerer * mySorcerer)
{
	bool end = 0;
	cout << "ħ��ʦ�ǣ�Ϊ�������Ǳ�ø���ǿ�����Ǹ�����һ�����" << endl;
	Magicitem magicStick("ħ����", 1);
	mySorcerer->addMagicitem(magicStick);
	system("pause");
	system("cls");
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

	mySorcerer->inRoom(&hall);
	//map map1("\t\t\t\t\t\t\t\t2.***************\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t****\t��¥\t***\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t*******************\n\n1.********\n***\t***\n***У����**\n***\t***\n***********\n");
	map map1("\t*********\t\t\t\t*********\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*����\t*\t < --------------->\t*����\t*\t----------->\t*��Ѩ\t*\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t*********\n\t / \\.\t\t\t\t\t / \\.\t\n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t  \\ / \t\t\t\t\t || \t\n\t*********\t\t\t\t || \n\t*\t*\t\t\t\t || \n\t*��¥\t *= ================================== = \n\t*\t*\n\t*********");
	cout << "��С���������������Ĺ�������\n��������һ���˵�����������\nȻ������11����������\n�������ص�֪���Լ�ԭ������ʦ\n���ұ�¼ȡΪ�����ִ�ħ��ѧУ�е�һԱ��\n���ϻ����ִ��ؿ��г�\n������ʼ������ħ���ó�������������䷢����ħ��ʯ�����ܡ�����������" << endl;
	system("pause");
	system("cls");
	cout << "��ӭ�����һ��~" << endl;
	cout << "��ϲ���ڿ��ֻ����һ����������ͨ��������ĳ������..." << endl;
	goodPerson Dumbledore("�˲�����", "���쾵�Ӿ�Ҫ�ᵽһ���µĵط��ˣ������������㲻Ҫ��ȥ�����ˡ�������������ɿ���������Ҫ������׼����\n");
	President_Office.addGoodPerson(Dumbledore);
	badPerson Chiro(100, 10, 35, "����");
	badPerson Kerberos(20, 0, 5, "��ͷ��");
	Crypt.addBadPerson(Chiro);

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
		map1.showMap();
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
			shop_G1.showShop(mySorcerer);
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
			mySorcerer->inRoom(&President_Office);
			system("cls");
			cout << "��ӭ���� " << President_Office.getName() << endl;
			if (President_Office.getIfIn()) {
				cout << "��ӭ���ٴ����� " << President_Office.getName() << endl;
				break;
			}
			cout << "\n" << Dumbledore.getName() << "��" << Dumbledore.getSentence() << endl;
			cout << "����" << Dumbledore.getName() << "������̸��֮�� �����һ�����" << endl;
			mySorcerer->addSkill(Alohomora);
			mySorcerer->increaseSkillNum();
			President_Office.inRoom();
			break;
		case 2:
			mySorcerer->inRoom(&Attic);
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
				ifWin = mySorcerer->battle(mySorcerer, Kerberos);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "��ͨ��ս�����ɽ����" << Kerberos.getName() << "����ͨ�����ŵ�����ɹ������Ѩ......" << endl;
					system("pause");
					system("cls");
					cout << "��ӭ������Ѩ~" << endl;
					mySorcerer->inRoom(&Crypt);
					cout << "��ʱ�������ھ����ԣ����Ƿ�ѡ����������ս����" << endl;
					cout << "1.��		2.��" << endl;
					int op2 = 0;
					cin >> op2;
					system("cls");
					if (op2 == 1) {
						bool ifWin = 0;
						cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
						ifWin = mySorcerer->battle(mySorcerer, Chiro);
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
	return 1;
}

void Plot::init_new(sorcerer * mySorcerer)
{
	cout << "��ѡ���������:" << endl;
	cout << "1.Harry Potter			2. Ron Weasley 			3.Hermione Granger" << endl;
	int op;
	cin >> op;
	system("cls");
	switch (op)
	{
	case 1:
		mySorcerer->setValue(100, 120, 100, 100, 100, "Harry Potter", 3000);
		break;
	case 2:
		mySorcerer->setValue(100, 100, 120, 100, 100, "Ron Weasley", 3000);
		break;
	case 3:
		mySorcerer->setValue(100, 100, 100, 120, 100, "Hermione Granger", 3000);
		break;
	default:
		cout << "����������������룡" << endl;
		break;
	}
}

Plot::Plot()
{
}

Plot::~Plot()
{
}