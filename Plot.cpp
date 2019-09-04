#include "Plot.h"
#include "File.h"
#include <fstream>
#include <iostream>
//���������뼼�� ����ùؿ���Ϣ ��¼�ص� ��������������Ƕ����ȥ��
void Plot::init_new(sorcerer * mySorcerer) {
	File myFiles("myFiles.txt");
	cout << "��ѡ��������õ��������Լӳ�:" << endl;
	cout << "1.սʿϵ		 2.̹��ϵ 			3.����ϵ" << endl;
	int op;
	string name;
	cin >> op;
	cout << "��������Ҫ���õĽ�ɫ���֣�" << endl;
	cin >> name;
	File myFile(name + ".txt");
	ofstream tempFile(name + ".txt");
	ofstream outFiles("myFiles.txt", ios::out | ios::app);
	system("cls");
	switch (op) {
	case 1:
		mySorcerer->setValue(100, 120, 100, 100, 100, name, 3000);
		break;
	case 2:
		mySorcerer->setValue(100, 100, 120, 100, 100, name, 3000);
		break;
	case 3:
		mySorcerer->setValue(100, 100, 100, 120, 100, name, 3000);
		break;
	default:
		cout << "����������������룡" << endl;
		break;
	}
	tempFile << mySorcerer->getDisguiseValue() << " "
		<< mySorcerer->getForceValue() << " "
		<< mySorcerer->getDefenceValue() << " "
		<< mySorcerer->getMagicValue() << " "
		<< mySorcerer->getBloodValue() << " "
		<< mySorcerer->getMoney() << " "
		<< mySorcerer->getName() << " ";
	outFiles << name + ".txt" << endl;
	tempFile.close();
	outFiles.close();
}

int Plot::init1(sorcerer * mySorcerer, int myCheckPoint) {	//��һ��
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifKillKerberos roomNum 0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
	//bool end = 0;	//
	//�����͵�����
	if (myCheckPoint == 0) {
		cout << "ħ��ʦ�ǣ�Ϊ�������Ǳ�ø���ǿ�����Ǹ�����һ�����" << endl;
		Magicitem magicStick("ħ����", 1);
		mySorcerer->addMagicitem(magicStick);
		//��ʽ������
		system("pause");
		system("cls");
	}
	//ҩˮ���� 1��2��2С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (myCheckPoint == 0) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//�����＼������
	//������׻��������䣩:Protego ��15 600 ��������������������� : Densaugeo��12  400
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Protego("Protego", 15, 600);
	Skill Densaugeo("Densaugeo", 12, 400);
	if (myCheckPoint == 0) {
		skill.push_back(Protego);
		skill.push_back(Densaugeo);
	}
	//��������
	//����ħ����������
	Skill Alohomora("Alohomora", 10);
	//һЩ�ж�
	bool check = 1;		//�ж��Ƿ�ͨ��
	bool ifKillKerberos = 1;	//�ж��Ƿ�����ͷ��
	//���صص�����
	room hall("����");
	room President_Office("У����");
	room Crypt("��Ѩ");
	room Attic("��¥");
	int roomNum = 0; //���浱ǰ���ڵķ����
	//�����ȵ���һ���ص�
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	//��ͼ���� ���Ϊ0���� 1У���� 2��¥ 3��Ѩ
	map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*��¥\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t   /\\\t\t\t\t\t   /\\\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   \\/\t\t\t\t\t   \\/\n\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*У����\t*\t\t\t\t*��Ѩ\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	if (myCheckPoint == 0) {
		//���ֱ�������
		cout << "��С���������������Ĺ�������\n��������һ���˵�����������\nȻ������11����������\n�������ص�֪���Լ�ԭ������ʦ\n���ұ�¼ȡΪ�����ִ�ħ��ѧУ�е�һԱ��\n���ϻ����ִ��ؿ��г�\n������ʼ������ħ���ó�������������䷢����ħ��ʯ�����ܡ�����������" << endl;
		//��ʽ������
		system("pause");
		system("cls");
		//���ֱ�������
		if (myCheckPoint == 0) {
			cout << "��ӭ�����һ��~" << endl;
			cout << "��ϲ���ڿ��ֻ����һ����������ͨ��������ĳ������..." << endl;
		}
	}
	//��������
	goodPerson Dumbledore("�˲�����", "���쾵�Ӿ�Ҫ�ᵽһ���µĵط��ˣ������������㲻Ҫ��ȥ�����ˡ�������������ɿ���������Ҫ������׼����\n");
	President_Office.addGoodPerson(Dumbledore);
	badPerson Chiro(100, 30, 45, "����");
	badPerson Kerberos(20, 0, 5, "��ͷ��");
	Crypt.addBadPerson(Chiro);
	//ʹ��pair��
	pair<string, int> hallWithNum("����", 0);
	pair<string, int> President_OfficeWithNum("У����", 1);
	pair<string, int> AtticWithNum("��¥", 2);
	pair<string, int> CryptWithNum("��Ѩ", 3);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[hallWithNum.second][President_OfficeWithNum.second] = 1;
	link[President_OfficeWithNum.second][hallWithNum.second] = 1;
	link[hallWithNum.second][AtticWithNum.second] = 1;
	link[AtticWithNum.second][hallWithNum.second] = 1;
	link[AtticWithNum.second][CryptWithNum.second] = 1;
	link[CryptWithNum.second][AtticWithNum.second]= 1;

	if (myCheckPoint == 1) {
		cout << "��ӭ���ٴν�����Ϸ������������һ�ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//���������ʼ��
		infile >> ifKillKerberos >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		hall.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		President_Office.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		Attic.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		Crypt.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&President_Office);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&Attic);
		}
		else if (roomNum == 3) {
			mySorcerer->inRoom(&Crypt);
		}
	}
	Shop shop(medicine, skill, "��Ƥʿħ����Ʒ��", medicine.size(), skill.size());
	//��Ҫ����
	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		//ѡ��Ϊop
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(1);
			//�ļ�����
			File myFile(mySorcerer->getName() + ".txt");
			File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint()  << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for(int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << ifKillKerberos << " " << roomNum << endl;
				//0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
			stateFile << hall.getIfIn() << " "
				<< President_Office.getIfIn() << " "
				<< Attic.getIfIn() << " "
				<< Crypt.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(1);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == hallWithNum.second || op == "��Ѩ" && roomNum == CryptWithNum.second || op == "��¥" && roomNum == AtticWithNum.second || op == "У����" && roomNum == President_OfficeWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "У����" && link[roomNum][President_OfficeWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&President_Office);
			system("cls");
			cout << "��ӭ���� " << President_Office.getName() << endl;
			if (President_Office.getIfIn()) {
				cout << "��ӭ���ٴ����� " << President_Office.getName() << endl;
			}
			else {
				cout << "\n" << Dumbledore.getName() << "��" << Dumbledore.getSentence() << endl;
				cout << "����" << Dumbledore.getName() << "������̸��֮�� �����һ�����" << endl;
				mySorcerer->addSkill(Alohomora);
				President_Office.inRoom();
			}
		}
		else if (op == "У����" && !link[roomNum][President_OfficeWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���У���ң�����ϸ�۲��ͼ��" << endl;
			//��ʽ������
		}
		else if (op == "��¥" && link[roomNum][AtticWithNum.second]) {
			mySorcerer->inRoom(&Attic);
			roomNum = 2;
			system("cls");
			if (Attic.getIfIn()) {
				cout << "��ӭ���ٴ����� " << Attic.getName() << endl;
			}
			else {
				cout << "��ӭ���� " << Attic.getName() << endl;
				cout << "��ʱ��ͷ�����ڿ���ĳ�����䣬���Ƿ�ѡ����������ս����" << endl;
				cout << "1.��		2.��" << endl;
				int op_Attic = 0;
				cin >> op_Attic;
				system("cls");
				if (op_Attic == 1) {
					cout << "ս���Ѿ���ʼ��" << endl;
					bool ifWin = 1;
					ifWin = mySorcerer->battle(mySorcerer, Kerberos);
					if (ifWin) {
						system("pause");
						system("cls");
						cout << "��ͨ��ս�����ɽ����" << Kerberos.getName() << "����������ܽ����Ѩ������......" << endl;
						Attic.inRoom();
						ifKillKerberos = 1;
					}
					else {
						//�����
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
					}
				}
				else {
					cout << "��ɹ�����������" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
		}
		else if (op == "��¥" && !link[roomNum][AtticWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����¥������ϸ�۲��ͼ��" << endl;
			//��ʽ������
		}
		else if (op == "��Ѩ" && link[roomNum][CryptWithNum.second]) {
			system("cls");
			if (ifKillKerberos) {
				roomNum = 3;
				mySorcerer->inRoom(&Crypt);
				cout << "ͨ������������˵�Ѩ��" << endl;
				cout << "��ӭ������Ѩ~" << endl;
				cout << "��ʱ�������ھ����ԣ����Ƿ�ѡ����������ս����" << endl;
				cout << "1.��		2.��" << endl;
				int op_Crypt = 0;
				cin >> op_Crypt;
				system("cls");
				if (op_Crypt == 1) {
					bool ifWin = 0;
					cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
					ifWin = mySorcerer->battle(mySorcerer, Chiro);
					if (ifWin) {
						cout << "��ϲ��ɹ�ͨ����һ�ز������";
						check = 0;
						system("pause");
						system("cls");
					}
					else {
						mySorcerer->inRoom(&hall);
						mySorcerer->setBlood(0);
						//�����
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n"  << endl;
						system("pause");
						system("cls");
					}
				}
				else if (op_Crypt == 2) {
					cout << "���Ѿ�����ս����" << endl;
					mySorcerer->inRoom(&Attic);
				}
				else {
					cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
				}
			}
			else {
				cout << "������û�д����ͷ�����޷������Ѩ" << endl;
			}
		}
		else if (op == "��Ѩ" && !link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����Ѩ������ϸ�۲��ͼ��" << endl;
			//��ʽ������	
		}
		else if (op == "����" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "��ӭ��������~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
		}
		else if (op == "����" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			//��ʽ������	
		}
		else {
			system("cls");
			cout << "����ʧ�ܣ�" << endl;
			//��ʽ������	
		}
	}
	return 1;
}

Plot::Plot() {
}

Plot::~Plot() {
}

int Plot::init2(sorcerer *mySorcerer) {
	room Crypt("��Ѩ");
	room bathroom("ϴ�ּ�");
	room chamber("����");
	room hathouse("ñ����");
	mySorcerer->inRoom(&Crypt);
	vector<Medicine> medicine_G2;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G2.push_back(medicineTempSmall);
	medicine_G2.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G2.push_back(medicineTempMiddle);
	medicine_G2.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	
	medicine_G2.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G2(medicine_G2, a,"��ÿռ�ħ����Ʒ��", 5);

	bool check = 1;
	Magicitem phoenix("���", 2);
	map map2("\t0.*******\t\t\t\t1.*******\t\t\t3.*******\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*��Ѩ\t*\t < --------------->\t*ϴ�ּ�\t*\t----------->\t*����\t*\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t*********\n\t / \\.\t\t\t\t\t / \\.\t\n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t  \\ / \t\t\t\t\t || \t\n\t2.*******\t\t\t\t || \n\t*\t*\t\t\t\t || \n\t*ñ����\t*<===================================\n\t*\t*\n\t*********");
	cout << "ѧУ������һϵ�С��ֲ����¼���ѧ��Ī�����ʯ��\nǽ�ϳ����˿ֲ���Ѫ��...\n���ǻ������߹���Ϊ\n��˵�е����ұ�˹�����ֵļ̳��˴�\n������Ϊ������ǻ�������˻��ɡ�������������" << endl;
	system("pause");
	system("cls");
	cout << "��ӭ����ڶ���~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;
	cout << "��˵��ϴ�ּ���ҽ���Ի����Ի�����صĶ���..." << endl;
	goodPerson Moaning_Myrtle("�ҽ���", "��ϴ����������Ķ���...��ʱ�Ҿ�����Ϊ���������۾���...\n");
	bathroom.addGoodPerson(Moaning_Myrtle);

	//mySorcerer->decreaseBlood(100);//����debug��

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

int Plot::init3(sorcerer * mySorcerer)
{
	vector<Medicine> medicine_G3;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G3.push_back(medicineTempSmall);
	medicine_G3.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G3.push_back(medicineTempMiddle);
	medicine_G3.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G3.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G3(medicine_G3, a, "��ÿռ�ħ����Ʒ��", 5);
	//�̵��������ػ���������������ͨ��
	bool check = 1;
	room chamber("����");
	room auditorium("����");
	room villa("����");
	room lakes("����");
	Magicitem phoenix("���", 2);
	mySorcerer->inRoom(&chamber);
	map map3("\t2.*******\t\t\t\t1.*******\t\t\t\t0.*******\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*����\t*\t<--------------->\t*����\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t  /\\.\t\t\t\t\t   /\\.\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t3.*******\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*����\t*====================================\n\t*\t*\n\t*********");
	cout << "��֪���ȿ����ﷸС�������ӳ�����\n������������ȥ����Ī��ʱ������������С�����Ǳ����˹����ĸ�ĸ\nʹ���⵽�˷���ħ��ɱ��\n����С�����ǳ��֣���������������-��û�б��й����ĸ�ĸ������С���Ǳ˵ñ��Ѻ�һ������ת�Ƶ����������ϡ�������������������" << endl;
	system("pause");
	system("cls");
	cout << "��ӭ���������~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;
	//cout << "��˵��ϴ�ּ���ҽ���Ի����Ի�����صĶ���..." << endl;
	goodPerson Sirius("С������", "�Ҹ�ղķ˹��������һ����ô�ã���ȴû�У��Ǻܲ��̡�...\n");
	villa.addGoodPerson(Sirius);
	badPerson pettigrew(100, 10, 35, "С����");
	badPerson dementor(100, 10, 35, "����");
	villa.addBadPerson(pettigrew);
	lakes.addBadPerson(dementor);
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
		map3.showMap();
		cout << "����������ѡ��:" << endl;
		int op = 0;
		int op1 = 0; //ս��ʱ��ѡ��
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
			shop_G3.showShop(mySorcerer);
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
		case 0:
			//����
			mySorcerer->inRoom(&chamber);
			cout << "��ӭ��������" << endl;
			break;
		case 1:
			//����
			mySorcerer->inRoom(&auditorium);
			system("cls");
			cout << "��ӭ���� " << auditorium.getName() << endl;
			if (auditorium.getIfIn()) {
				cout << "��ӭ���ٴ����� " << auditorium.getName() << endl;
				break;
			}
			//cout << "\n" << Moaning_Myrtle.getName() << "��" << Moaning_Myrtle.getSentence() << endl;
			//cout << "����" << Moaning_Myrtle.getName() << "������̸��֮�� �����Լ�ӵ�����" << endl;
			/*mySorcerer->addSkill(Alohomora);
			mySorcerer->increaseSkillNum();*/
			auditorium.inRoom();
			break;
		case 2:
			//����
			mySorcerer->inRoom(&villa);
			system("cls");
			cout << "��ӭ���� " << villa.getName() << endl;
			if (villa.getIfIn()) {
				cout << "��ӭ���ٴ����� " << villa.getName() << endl;
				break;
			}
			villa.inRoom();
			//��С���ǽ���ս��
			cout << "��ʱС������׼�����ܣ����Ƿ�ѡ����������ս����" << endl;
			cout << "1.��		2.��" << endl;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "ս���Ѿ���ʼ��" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->battle(mySorcerer, pettigrew);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "��ͨ��ս��������" << pettigrew.getName() << "�Ĵ󲿷�����������С�������ӵ��˺���......" << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "�㱻С���ǻ��ܣ������ٹ�����װ������ս����" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "���Ѿ�����ս����С���ǳɹ�����" << endl;
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
			}

			break;
		case 3:
			//����
			mySorcerer->inRoom(&lakes);
			system("cls");
			cout << "��ӭ���� " << lakes.getName() << endl;
			cout << "��ʱ�����Ѿ���С�����ǰ�Χ�����Ƿ�ѡ���������жԻ���" << endl;
			cout << "1.��		2.��" << endl;
			int op1 = 0;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "ս���Ѿ���ʼ��" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->battle(mySorcerer, dementor);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "��ͨ��ս��������" << dementor.getName() << "��С�����ǳɹ�����......" << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "�㱻���ֻ��ܣ������ٹ�����װ������ս����" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "���Ѿ�����ս����С���ǳɹ�����" << endl;
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
			}
			break;
		}
	}
	return 1;
}

int Plot::init4(sorcerer *mySorcerer) {
	vector<Medicine> medicine_G4;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G4.push_back(medicineTempSmall);
	medicine_G4.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G4.push_back(medicineTempMiddle);
	medicine_G4.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G4.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G4(medicine_G4, a, "��ÿռ�ħ����Ʒ��", 5);
	//�̵��������ػ���������������ͨ��
	bool check = 1;

	Magicitem The_goblet_of_fire("���汭", 100);

	room hall("����");
	room auditorium("����");
	room maze("�Թ�");	//1�Թ� 2��Ĺ
	room grave("��Ĺ");
	room office("�칫��");
	mySorcerer->inRoom(&auditorium);
	//Magicitem phoenix("���", 2);
	map map4("\t0.*******\t\t\t\t1.*******\t\t\t\t2.*******\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*�Թ�\t*\t---------------->\t*��Ĺ\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t   ||\n \t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   \\/\n\t\t\t\t\t\t\t\t\t\t\t3.*******\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*����\t*\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*********");
	cout << "����û�б����μӡ���ǿ��������ȴ����س�Ϊ����ǿ�������ĵ�������ʿ\nû�뵽�������ı���ں������������������������" << endl;
	system("pause");
	system("cls");
	cout << "��ӭ������Ĺ�~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;
	//cout << "��˵��ϴ�ּ���ҽ���Ի����Ի�����صĶ���..." << endl;
	//goodPerson Sirius("С������", "�Ҹ�ղķ˹��������һ����ô�ã���ȴû�У��Ǻܲ��̡�...\n");
	//villa.addGoodPerson(Sirius);
	badPerson voldemort(100, 10, 35, "����ħ");
	badPerson Little_buddy(100, 10, 15, "С�͵�");
	grave.addBadPerson(voldemort);
	office.addBadPerson(Little_buddy);
	int trueanswer = 0;
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
		map4.showMap();
		cout << "����������ѡ��:" << endl;
		int op = 0;
		int op2 = 0;//�칫���Ƕ����ж�
		int op3 = 0;//����ʱ���ж�
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
			shop_G4.showShop(mySorcerer);
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
		case 0:
			mySorcerer->inRoom(&auditorium);
			cout << "��ӭ���� " << auditorium.getName() << endl;
			break;
		case 1:
			//�Թ�
			system("cls");
			mySorcerer->inRoom(&maze);

			char indicatation;
			cout << "ͨ���ش�һЩС���������ͨ���Թ���" << endl;
			system("pause");
			while (trueanswer < 3) {
				trueanswer = 0;
				cout << "1���������ص������Ǽ��¼��գ�" << endl;
				cout << "A.8.31    B. 7.31    C.7.11" << endl;
				cin >> indicatation;
				switch (indicatation) {
				case 'B': {
					cout << "�ش���ȷ" << endl;
					cout << "2.����Imperio��ʲô��˼��" << endl;
					cout << "A. ���ǳ���              B. �������              C. ��ħ���" << endl;
					cin >> indicatation;
					switch (indicatation) {
					case 'A': {
						cout << "�ش���ȷ" << endl;
						cout << "3. Bezoar ë��ʯ��ʲô���ã�" << endl;
						cout << "A. �����ⶾ B.���Ѳ����������ر����Ч  C.��ˮ����Ժ���" << endl;
						cin >> indicatation;
						switch (indicatation) {
						case 'A': {
							cout << "�ش���ȷ" << endl;
							trueanswer = trueanswer + 1;
							break;
						}
						default: {
							cout << "�ش����" << endl;
							trueanswer = trueanswer;
							break;
						}
						}
						trueanswer = trueanswer + 1;
						break;
					}
					default: {
						cout << "�ش����" << endl;
						trueanswer = trueanswer;
						break;
					}
					}
					trueanswer = trueanswer + 1; break; }
				default: {
					cout << "�ش����" << endl;
					cout << "2.����Imperio��ʲô��˼��" << endl;
					cout << "A. ���ǳ���              B. �������              C. ��ħ���" << endl;
					cin >> indicatation;
					switch (indicatation) {
					case 'A': {
						cout << "�ش���ȷ" << endl;
						cout << "3. Bezoar ë��ʯ��ʲô���ã�" << endl;
						cout << "A. �����ⶾ B.���Ѳ����������ر����Ч  C.��ˮ����Ժ���" << endl;
						cin >> indicatation;
						switch (indicatation) {
						case 'A': {
							cout << "�ش���ȷ" << endl;
							trueanswer = trueanswer + 1;
							break;
						}
						default: {
							cout << "�ش����" << endl;
							trueanswer = trueanswer;
							break;
						}
						}
						trueanswer = trueanswer + 1;
						break;
					}
					default: {
						cout << "�ش����" << endl;
						cout << "3. Bezoar ë��ʯ��ʲô���ã�" << endl;
						cout << "A. �����ⶾ B.���Ѳ����������ر����Ч  C.��ˮ����Ժ���" << endl;
						cin >> indicatation;
						switch (indicatation) {
						case 'A': {
							cout << "�ش���ȷ" << endl;
							trueanswer = trueanswer + 1;
							break;
						}
						default: {
							cout << "�ش����" << endl;
							trueanswer = trueanswer;
							break;
						}
						}
						trueanswer = trueanswer + 1;
						break;
					}
							 trueanswer = trueanswer;
							 break;
					}
				}
						 trueanswer = trueanswer; break;
				}
			}

			cout << "��ͨ������Ļ��汭��������һ������ĵط�" << endl;
			system("pause");
			system("cls");
			mySorcerer->inRoom(&grave);
			cout << "��ӭ���� " << grave.getName() << endl;
			//�鷳��һ�����֣���������ħ���


			cout << "�Ƿ�ѡ�������ħ����ս��:" << endl;
			cout << "1.��		2.��" << endl;
			cin >> op3;
			if (op3 == 1) {
				cout << "ս�������У�����ʵ�����ϴ���ʹ�û��汭˳�����ѡ�" << endl;
			}
			else {
				cout << "��ʹ�û��汭˳�����ѡ�" << endl;
			}
			system("pause");
			system("cls");
			mySorcerer->inRoom(&hall);
		
			break;
		case 4:
			mySorcerer->inRoom(&office);
			cout << "��ӭ����" << office.getName() << endl;
			cout << "ԭ��С�͵���ʳ˾ͽ!!!" << endl;
			cout << "���Ƿ�ѡ����������ս����" << endl;
			cout << "1.��		2.��" << endl;
			cin >> op2;
			system("cls");
			if (op2 == 1) {
				bool ifWin = 0;
				cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
				ifWin = mySorcerer->battle(mySorcerer, Little_buddy);
				if (ifWin) {
					cout << "��ϲ��ɹ�ͨ�����Ĺعز������";
					check = 0;
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
				mySorcerer->inRoom(&hall);
			}
		}
	}
	cout << "��ϲ��ɹ�ͨ�����Ĺء�" << endl;
	system("pause");
	system("cls");
	return 1;
}


int Plot::init5(sorcerer *mySorcerer) {

	//ҩˮ���ô���
	vector<Medicine> medicine_G5;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G5.push_back(medicineTempSmall);
	medicine_G5.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G5.push_back(medicineTempMiddle);
	medicine_G5.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G5.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G5(medicine_G5, a, "��ÿռ�ħ����Ʒ��", 5);
	bool check = 1;
	room Room_of_requirement("�����Ӧ��");
	room bathroom("ϴ�ּ�");
	room hall("����");
	room The_ministry_of_magic("ħ����");
	room The_dragon_pavilion("������");
	map map5("\t1.*******\n\t*\t*\n\t*ħ����\t*\n\t*\t*\n\t*********\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t0.*******\t\t\t\t2.***************\n\t*\t*\t\t\t\t*\t\t*\n\t*����\t*<----------------------------->*�����Ӧ��\t*\n\t*\t*\t\t\t\t*\t\t*\n\t*********\t\t\t\t*****************\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t3.*******\n\t*\t*\n\t*������\t*\n\t*\t*\n\t*********");
	cout << "û�������ŷ���ħ������\n��������Ϊ�Ǹ�ƭ�ӣ�\nֻ���������������Ų�֧��������\n�����ڻ�����齨�˲���������ֿ���\n�������������˷���ħ�Ĺ�ƣ�\n������������ħ������Ƚ̸�С�����ǡ�������������" << endl;
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "��ӭ��������~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;

	goodPerson Sirius("С������", "�Ҹ�ղķ˹��������һ����ô�ã���ȴû�У��Ǻܲ��̡�...\n");
	badPerson Lucius(100, 10, 35, "¬��˹");
	The_ministry_of_magic.addGoodPerson(Sirius);

	badPerson Fire_dragon(100, 10, 35, "����");
	badPerson Earth_dragon(100, 10, 35, "����");
	badPerson Water_dragon(100, 10, 35, "ˮ��");
	badPerson Wind_dragon(100, 10, 35, "����");
	badPerson Far_from_cologne(100, 10, 35, "Զ����");
	//����������� ��սľ����������������������Զ����

	The_dragon_pavilion.addBadPerson(Fire_dragon);
	The_dragon_pavilion.addBadPerson(Earth_dragon);
	The_dragon_pavilion.addBadPerson(Water_dragon);
	The_dragon_pavilion.addBadPerson(Far_from_cologne);
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
		map5.showMap();
		cout << "����������ѡ��:" << endl;
		int op = 0;
		bool ifWin = 0;
		int op3 = 0;//ѡ��
		int op1 = 0;//¬��˹
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
			shop_G5.showShop(mySorcerer);
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
		case 3:	//����������
			mySorcerer->inRoom(&The_dragon_pavilion);
			system("cls");
			cout << "��ӭ���� " << The_dragon_pavilion.getName() << endl;
			The_dragon_pavilion.inRoom();
			cout << "�������������ս�����������������Ի����Ӧ�ļӳ�" << endl;
			cout << "1.����		2.����		3.ˮ��		4.����		5.Զ����	0.���ܴ���" << endl;
			cin >> op3;
			switch (op3)
			{
			case 1:
				cout << "��׼����ս���ǻ���...ս��������ʼ��" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Fire_dragon);
				if (ifWin == 1) {
					cout << "��ϲ��������˻�������������Լӳɡ�" << endl;
					//д���Լӳ�������
				}
				else {
					cout << "�㱻�������ܣ������״̬��������" << endl;
				}
				break;
			case 2:
				cout << "��׼����ս���Ƿ���...ս��������ʼ��" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Wind_dragon);
				if (ifWin == 1) {
					cout << "��ϲ��������˷�������������Լӳɡ�" << endl;
					//д���Լӳ�������
				}
				else {
					cout << "�㱻�������ܣ������״̬��������" << endl;
				}
				break;
			case 3:
				cout << "��׼����ս����ˮ��...ս��������ʼ��" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Water_dragon);
				if (ifWin == 1) {
					cout << "��ϲ���������ˮ������������Լӳɡ�" << endl;
					//д���Լӳ�������
				}
				else {
					cout << "�㱻ˮ�����ܣ������״̬��������" << endl;
				}
				break;
			case 4:
				cout << "��׼����ս��������...ս��������ʼ��" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Earth_dragon);
				if (ifWin == 1) {
					cout << "��ϲ�����������������������Լӳɡ�" << endl;
					//д���Լӳ�������
				}
				else {
					cout << "�㱻�������ܣ������״̬��������" << endl;
				}
				break;
			case 5:
				cout << "��׼����ս����Զ����...ս��������ʼ��" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Far_from_cologne);
				if (ifWin == 1) {
					cout << "��ϲ���������Զ��������������Լӳɡ�" << endl;
					//д���Լӳ�������
				}
				else {
					cout << "�㱻Զ�������ܣ������״̬��������" << endl;
				}
				break;
			default:
				break;
			}
			mySorcerer->inRoom(&hall);
			break;
		case 2:
			mySorcerer->inRoom(&Room_of_requirement);
			system("cls");
			cout << "��ӭ���� " << Room_of_requirement.getName() << endl;
			if (bathroom.getIfIn()) {
				cout << "��ӭ���ٴ����� " << Room_of_requirement.getName() << endl;
				break;
			}
			//�������Ӧ�ݻ��ʲô�ȴ���ӡ�
			Room_of_requirement.inRoom();
			break;
		case 1:

			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "��ӭ���� " << The_ministry_of_magic.getName() << endl;
			cout << "��ʱ¬��˹����ħ��������Ƿ�ѡ������" << endl;
			cout << "1.��		2.��" << endl;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "¬��˹˵�Ļ�" << endl;
				ifWin = mySorcerer->battle(mySorcerer, Lucius);
				if (ifWin == 1) {
					//�ɹ���ܵĻ�
					check = 1;
				}
				else if (ifWin == 0) {
					cout << "��սʧ�ܣ�" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
			else if (op1 == 2) {
				cout << "��ɹ����롣" << endl;
				mySorcerer->inRoom(&hall);
			}
			else {
				cout << "����ʧ�ܣ�����ȷ���롣" << endl;
				mySorcerer->inRoom(&hall);
			}
			break;
		}
	}
	cout << "��ϲ��ͨ�������" << endl;
	return 1;
}


int Plot::init6(sorcerer *mySorcerer) {

	//ҩˮ���ô���
	vector<Medicine> medicine_G5;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G5.push_back(medicineTempSmall);
	medicine_G5.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G5.push_back(medicineTempMiddle);
	medicine_G5.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G5.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G5(medicine_G5, a, "��ÿռ�ħ����Ʒ��", 5);
	bool check = 1;
	room hall("����");
	room The_ministry_of_magic("ħ����");
	room gringotts("�����");
	map map6("\t1.*******\t\t\t\t2.*******\n\t*\t*\t\t\t\t*\t*\n\t*ħ����\t*\t<--------------->\t*�����\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t  /\\\t\t\t\t\t   ||\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t0.*******\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*����\t*<===================================\n\t*\t*\n\t*********");
	//cout << "û�������ŷ���ħ������\n��������Ϊ�Ǹ�ƭ�ӣ�\nֻ���������������Ų�֧��������\n�����ڻ�����齨�˲���������ֿ���\n�������������˷���ħ�Ĺ�ƣ�\n������������ħ������Ƚ̸�С�����ǡ�������������" << endl;
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "��ӭ���������~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;
	//�ڹ������Ҫ��6��ʳ��ͽ
	//������
	badPerson dolohov(100, 5, 10, "�������");
	badPerson rookwood(100, 5, 10, "¬�����");
	badPerson bellatrix(100, 5, 10, "���������˹");
	badPerson travers(100, 5, 10, "������˹");
	badPerson DoleFinn(100, 5, 10, "�����");
	badPerson malfoy(100, 5, 10, "�����");
	gringotts.addBadPerson(dolohov);
	gringotts.addBadPerson(rookwood);
	gringotts.addBadPerson(bellatrix);
	gringotts.addBadPerson(travers);
	gringotts.addBadPerson(DoleFinn);
	gringotts.addBadPerson(malfoy);

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
		map6.showMap();
		cout << "����������ѡ��:" << endl;
		int op = 0;
		bool ifWin = 0;
		int op1 = 1;	//ѡ��ʲô����
		int op2 = 0;
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
			shop_G5.showShop(mySorcerer);
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
			mySorcerer->inRoom(&The_ministry_of_magic);
			cout << "��ӭ����ħ����" << endl;
			break;
		case 2:
			op2 = 1;
			mySorcerer->inRoom(&gringotts);
			cout << "��ӭ���������һȺʳ��ͽ���ڵ����㡣����������";
			while (op2 == 1) {
				gringotts.showBadPerson();
				cout << "��������Ҫ��ս��ʳ��ͽ:(0������)" << endl;
				cin >> op1;
				if (op1 == 0) {
					cout << "���ܳɹ���" << endl;
					mySorcerer->inRoom(&The_ministry_of_magic);
				}
				ifWin = mySorcerer->battle(mySorcerer, gringotts.getBadPerson(op1));	//	�޸�
				if (ifWin == 1) {
					gringotts.eraseBadPerson(op1);
					cout << "��ϲ���������һ��ʳ˾ͽ,�����ѡ�����ս���������ܡ�" << endl;
					cout << "1.����ս��		2.����" << endl;
					cin >> op2;
					if (op2 == 2) {
						op2 = 0;
						cout << "���ܳɹ���" << endl;
						mySorcerer->inRoom(&The_ministry_of_magic);
					}
					else {
						cout << "��ѡ���˼���ս��" << endl;
					}
				}
				else {
					cout << "�㱻���" << endl;
				}
				if (gringotts.getBadPersonSize() == 0) {
					check = 1;
					op2 = 0;
				}
			}

			break;
		}
	}
	cout << "��ϲ��ͨ��������" << endl;
	return 1;
}

int Plot::initFinal(sorcerer * mySorcerer)
{
	//ҩˮ���ô���
	vector<Medicine> medicine_G5;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	medicine_G5.push_back(medicineTempSmall);
	medicine_G5.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	medicine_G5.push_back(medicineTempMiddle);
	medicine_G5.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	medicine_G5.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G2(medicine_G5, a, "��ÿռ�ħ����Ʒ��", 5);
	bool check = 1;
	room hall("����");
	room The_black_forest("��ɭ��");
	map mapfinal("\t0.*******\t\t\t\t1.*******\n\t*\t*\t\t\t\t*\t*\n\t*����\t*\t---------------- > \t*��ɭ��\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	//cout << "û�������ŷ���ħ������\n��������Ϊ�Ǹ�ƭ�ӣ�\nֻ���������������Ų�֧��������\n�����ڻ�����齨�˲���������ֿ���\n�������������˷���ħ�Ĺ�ƣ�\n������������ħ������Ƚ̸�С�����ǡ�������������" << endl;
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "��ӭ������վ�֮ս~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;

	badPerson voldemort(100, 5, 10, "����ħ");


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
		mapfinal.showMap();
		cout << "����������ѡ��:" << endl;
		int op = 0;
		bool ifWin = 0;
		int op1 = 1;	//ѡ��ʲô����
		int op2 = 0;
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
			mySorcerer->inRoom(&The_black_forest);
			cout << "��ӭ����ħ����" << endl;
			//��һЩ��
			cout << "��ʱ����ħ���ں�ɭ������Ƿ�ѡ���������֮ս" << endl;
			cout << "1.��		2.��" << endl;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				ifWin = mySorcerer->battle(mySorcerer, voldemort);
				if (ifWin == 1) {
					//�ɹ���ܵĻ�
					check = 1;
				}
				else if (ifWin == 0) {
					cout << "��սʧ�ܣ�" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
			else if (op1 == 2) {
				cout << "��ɹ����롣" << endl;
				mySorcerer->inRoom(&hall);
			}
			else {
				cout << "����ʧ�ܣ�����ȷ���롣" << endl;
				mySorcerer->inRoom(&hall);
			}
			break;
		}
	}
	cout << "��ϲ��ͨ�����йؿ�" << endl;
	return 1;
}