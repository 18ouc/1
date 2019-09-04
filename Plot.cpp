#include "Plot.h"
#include "File.h"
#include <fstream>
#include <iostream>
//店铺中塞入技能 保存该关卡信息 记录地点 传入参数表明这是读入进去的
void Plot::init_new(sorcerer * mySorcerer) {
	File myFiles("myFiles.txt");
	cout << "请选择你的想获得的人物属性加成:" << endl;
	cout << "1.战士系		 2.坦克系 			3.巫术系" << endl;
	int op;
	string name;
	cin >> op;
	cout << "请输入你要设置的角色名字：" << endl;
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
		cout << "输入错误！请重新输入！" << endl;
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

int Plot::init1(sorcerer * mySorcerer, int myCheckPoint) {	//第一关
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifKillKerberos roomNum 0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
	//bool end = 0;	//
	//开局送的礼物
	if (myCheckPoint == 0) {
		cout << "魔法师们，为了让你们变得更加强大！我们给了你一件礼物。" << endl;
		Magicitem magicStick("魔法棍", 1);
		mySorcerer->addMagicitem(magicStick);
		//格式化操作
		system("pause");
		system("cls");
	}
	//药水设置 1大2中2小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (myCheckPoint == 0) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//超市里技能设置
	//咒语：盔甲护身（盔甲咒）:Protego ：15 600 门牙赛大棒（长出长牙） : Densaugeo：12  400
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Protego("Protego", 15, 600);
	Skill Densaugeo("Densaugeo", 12, 400);
	if (myCheckPoint == 0) {
		skill.push_back(Protego);
		skill.push_back(Densaugeo);
	}
	//超市设置
	//本关魔法咒语设置
	Skill Alohomora("Alohomora", 10);
	//一些判断
	bool check = 1;		//判断是否通关
	bool ifKillKerberos = 1;	//判断是否打败三头狗
	//本关地点设置
	room hall("大厅");
	room President_Office("校长室");
	room Crypt("地穴");
	room Attic("阁楼");
	int roomNum = 0; //储存当前所在的房间号
	//开局先到达一个地点
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	//地图设置 编号为0大厅 1校长室 2阁楼 3地穴
	map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*大厅\t*\t<--------------->\t*阁楼\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t   /\\\t\t\t\t\t   /\\\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   \\/\t\t\t\t\t   \\/\n\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*校长室\t*\t\t\t\t*地穴\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	if (myCheckPoint == 0) {
		//开局背景故事
		cout << "从小被寄养在姨妈家里的哈利波特\n饱受姨妈一家人的歧视与欺侮\n然而就在11岁生日那天\n哈利波特得知了自己原本是巫师\n并且被录取为霍格沃茨魔法学校中的一员。\n登上霍格沃茨特快列车\n哈利开始了他的魔幻旅程在这里他无意间发现了魔法石的秘密。。。。。。" << endl;
		//格式化处理
		system("pause");
		system("cls");
		//开局背景故事
		if (myCheckPoint == 0) {
			cout << "欢迎进入第一关~" << endl;
			cout << "恭喜你在开局获得了一个咒语，你可以通过它进入某个房间..." << endl;
		}
	}
	//人物设置
	goodPerson Dumbledore("邓布利多", "明天镜子就要搬到一个新的地方了，哈利，我请你不要再去找它了。如果你哪天碰巧看见它，你要有心理准备。\n");
	President_Office.addGoodPerson(Dumbledore);
	badPerson Chiro(100, 30, 45, "奇洛");
	badPerson Kerberos(20, 0, 5, "三头狗");
	Crypt.addBadPerson(Chiro);
	//使用pair绑定
	pair<string, int> hallWithNum("大厅", 0);
	pair<string, int> President_OfficeWithNum("校长室", 1);
	pair<string, int> AtticWithNum("阁楼", 2);
	pair<string, int> CryptWithNum("地穴", 3);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第一关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "西皮士魔术用品店", medicine.size(), skill.size());
	//主要程序
	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		//选择为op
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(1);
			//文件处理
			File myFile(mySorcerer->getName() + ".txt");
			File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
				//0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
			stateFile << hall.getIfIn() << " "
				<< President_Office.getIfIn() << " "
				<< Attic.getIfIn() << " "
				<< Crypt.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(1);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "大厅" && roomNum == hallWithNum.second || op == "地穴" && roomNum == CryptWithNum.second || op == "阁楼" && roomNum == AtticWithNum.second || op == "校长室" && roomNum == President_OfficeWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "校长室" && link[roomNum][President_OfficeWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&President_Office);
			system("cls");
			cout << "欢迎来到 " << President_Office.getName() << endl;
			if (President_Office.getIfIn()) {
				cout << "欢迎您再次来到 " << President_Office.getName() << endl;
			}
			else {
				cout << "\n" << Dumbledore.getName() << "：" << Dumbledore.getSentence() << endl;
				cout << "在与" << Dumbledore.getName() << "进行完谈话之后， 获得了一个咒语。" << endl;
				mySorcerer->addSkill(Alohomora);
				President_Office.inRoom();
			}
		}
		else if (op == "校长室" && !link[roomNum][President_OfficeWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达校长室，请仔细观察地图！" << endl;
			//格式化操作
		}
		else if (op == "阁楼" && link[roomNum][AtticWithNum.second]) {
			mySorcerer->inRoom(&Attic);
			roomNum = 2;
			system("cls");
			if (Attic.getIfIn()) {
				cout << "欢迎您再次来到 " << Attic.getName() << endl;
			}
			else {
				cout << "欢迎来到 " << Attic.getName() << endl;
				cout << "此时三头狗正在看守某个房间，你是否选择与它进行战斗？" << endl;
				cout << "1.是		2.否" << endl;
				int op_Attic = 0;
				cin >> op_Attic;
				system("cls");
				if (op_Attic == 1) {
					cout << "战斗已经开始！" << endl;
					bool ifWin = 1;
					ifWin = mySorcerer->battle(mySorcerer, Kerberos);
					if (ifWin) {
						system("pause");
						system("cls");
						cout << "你通过战斗轻松解决了" << Kerberos.getName() << "。并获得了能进入地穴的咒语......" << endl;
						Attic.inRoom();
						ifKillKerberos = 1;
					}
					else {
						//输出菜
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
					}
				}
				else {
					cout << "你成功逃跑至大厅" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
		}
		else if (op == "阁楼" && !link[roomNum][AtticWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达阁楼，请仔细观察地图！" << endl;
			//格式化操作
		}
		else if (op == "地穴" && link[roomNum][CryptWithNum.second]) {
			system("cls");
			if (ifKillKerberos) {
				roomNum = 3;
				mySorcerer->inRoom(&Crypt);
				cout << "通过咒语你进入了地穴。" << endl;
				cout << "欢迎来到地穴~" << endl;
				cout << "此时奇洛正在镜子旁，你是否选择与它进行战斗？" << endl;
				cout << "1.是		2.否" << endl;
				int op_Crypt = 0;
				cin >> op_Crypt;
				system("cls");
				if (op_Crypt == 1) {
					bool ifWin = 0;
					cout << "战斗开始，你已进入战斗模式..." << endl;
					ifWin = mySorcerer->battle(mySorcerer, Chiro);
					if (ifWin) {
						cout << "恭喜你成功通过第一关并获得了";
						check = 0;
						system("pause");
						system("cls");
					}
					else {
						mySorcerer->inRoom(&hall);
						mySorcerer->setBlood(0);
						//输出菜
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n"  << endl;
						system("pause");
						system("cls");
					}
				}
				else if (op_Crypt == 2) {
					cout << "你已经逃离战斗。" << endl;
					mySorcerer->inRoom(&Attic);
				}
				else {
					cout << "操作失败，你已退出该房间！" << endl;
				}
			}
			else {
				cout << "由于你没有打败三头狗，无法进入地穴" << endl;
			}
		}
		else if (op == "地穴" && !link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达地穴，请仔细观察地图！" << endl;
			//格式化操作	
		}
		else if (op == "大厅" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "欢迎来到大厅~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
		}
		else if (op == "大厅" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达大厅，请仔细观察地图！" << endl;
			//格式化操作	
		}
		else {
			system("cls");
			cout << "操作失败！" << endl;
			//格式化操作	
		}
	}
	return 1;
}

Plot::Plot() {
}

Plot::~Plot() {
}

int Plot::init2(sorcerer *mySorcerer) {
	room Crypt("地穴");
	room bathroom("洗手间");
	room chamber("密室");
	room hathouse("帽子屋");
	mySorcerer->inRoom(&Crypt);
	vector<Medicine> medicine_G2;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G2.push_back(medicineTempSmall);
	medicine_G2.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G2.push_back(medicineTempMiddle);
	medicine_G2.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	
	medicine_G2.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G2(medicine_G2, a,"奇幻空间魔术用品店", 5);

	bool check = 1;
	Magicitem phoenix("凤凰", 2);
	map map2("\t0.*******\t\t\t\t1.*******\t\t\t3.*******\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*地穴\t*\t < --------------->\t*洗手间\t*\t----------->\t*密室\t*\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t*********\n\t / \\.\t\t\t\t\t / \\.\t\n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t  \\ / \t\t\t\t\t || \t\n\t2.*******\t\t\t\t || \n\t*\t*\t\t\t\t || \n\t*帽子屋\t*<===================================\n\t*\t*\n\t*********");
	cout << "学校发生了一系列“恐怖”事件—学生莫名其妙被石化\n墙上出现了恐怖的血字...\n人们怀疑是蛇怪所为\n传说中的密室被斯莱特林的继承人打开\n哈利因为会蛇佬腔被所有人怀疑。。。。。。。" << endl;
	system("pause");
	system("cls");
	cout << "欢迎进入第二关~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;
	cout << "据说与洗手间的桃金娘对话可以获得神秘的东西..." << endl;
	goodPerson Moaning_Myrtle("桃金娘", "盥洗池里有神奇的东西...当时我就是因为看到它的眼睛而...\n");
	bathroom.addGoodPerson(Moaning_Myrtle);

	//mySorcerer->decreaseBlood(100);//测试debug用

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

int Plot::init3(sorcerer * mySorcerer)
{
	vector<Medicine> medicine_G3;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G3.push_back(medicineTempSmall);
	medicine_G3.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G3.push_back(medicineTempMiddle);
	medicine_G3.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G3.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G3(medicine_G3, a, "奇幻空间魔术用品店", 5);
	//商店里面有守护神咒可以买不买很难通关
	bool check = 1;
	room chamber("密室");
	room auditorium("礼堂");
	room villa("别墅");
	room lakes("湖泊");
	Magicitem phoenix("凤凰", 2);
	mySorcerer->inRoom(&chamber);
	map map3("\t2.*******\t\t\t\t1.*******\t\t\t\t0.*******\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*别墅\t*\t<--------------->\t*礼堂\t*\t<--------------->\t*密室\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t  /\\.\t\t\t\t\t   /\\.\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t3.*******\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*湖泊\t*====================================\n\t*\t*\n\t*********");
	cout << "得知阿兹卡班罪犯小天狼星逃出监狱\n而哈利等人在去霍格莫德时无意中听到是小天狼星背叛了哈利的父母\n使其遭到了伏地魔的杀害\n后来小天狼星出现，点明了事情真相-他没有被判哈利的父母，而是小矮星彼得背叛后将一切罪名转移到了他的身上。。。。。。。。。。" << endl;
	system("pause");
	system("cls");
	cout << "欢迎进入第三关~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;
	//cout << "据说与洗手间的桃金娘对话可以获得神秘的东西..." << endl;
	goodPerson Sirius("小天狼星", "我跟詹姆斯和莉莉在一起那么久，你却没有，是很残忍。...\n");
	villa.addGoodPerson(Sirius);
	badPerson pettigrew(100, 10, 35, "小矮星");
	badPerson dementor(100, 10, 35, "摄魂怪");
	villa.addBadPerson(pettigrew);
	lakes.addBadPerson(dementor);
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
		map3.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		int op1 = 0; //战斗时的选择
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
			cout << "还未设置" << endl;
			break;
		case 111:
			cout << "你已经结束该游戏。" << endl;
			return -1;
			break;
		default:
			cout << "操作失败！" << endl;
			break;
		case 0:
			//密室
			mySorcerer->inRoom(&chamber);
			cout << "欢迎来到密室" << endl;
			break;
		case 1:
			//礼堂
			mySorcerer->inRoom(&auditorium);
			system("cls");
			cout << "欢迎来到 " << auditorium.getName() << endl;
			if (auditorium.getIfIn()) {
				cout << "欢迎您再次来到 " << auditorium.getName() << endl;
				break;
			}
			//cout << "\n" << Moaning_Myrtle.getName() << "：" << Moaning_Myrtle.getSentence() << endl;
			//cout << "在与" << Moaning_Myrtle.getName() << "进行完谈话之后， 发现自己拥有蛇语。" << endl;
			/*mySorcerer->addSkill(Alohomora);
			mySorcerer->increaseSkillNum();*/
			auditorium.inRoom();
			break;
		case 2:
			//别墅
			mySorcerer->inRoom(&villa);
			system("cls");
			cout << "欢迎来到 " << villa.getName() << endl;
			if (villa.getIfIn()) {
				cout << "欢迎您再次来到 " << villa.getName() << endl;
				break;
			}
			villa.inRoom();
			//与小矮星进行战斗
			cout << "此时小矮星正准备逃跑，你是否选择与它进行战斗？" << endl;
			cout << "1.是		2.否" << endl;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "战斗已经开始！" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->battle(mySorcerer, pettigrew);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "你通过战斗消耗了" << pettigrew.getName() << "的大部分力量。但是小天狼星逃到了湖泊......" << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "你被小矮星击败，建议再购买点儿装备进行战斗。" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "你已经逃离战斗。小矮星成功逃跑" << endl;
			}
			else {
				cout << "操作失败，你已退出该房间！" << endl;
			}

			break;
		case 3:
			//湖泊
			mySorcerer->inRoom(&lakes);
			system("cls");
			cout << "欢迎来到 " << lakes.getName() << endl;
			cout << "此时摄魂怪已经将小天狼星包围，你是否选择与它进行对话？" << endl;
			cout << "1.是		2.否" << endl;
			int op1 = 0;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "战斗已经开始！" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->battle(mySorcerer, dementor);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "你通过战斗击退了" << dementor.getName() << "。小天狼星成功逃离......" << endl;
					system("pause");
					system("cls");
				}
				else {
					cout << "你被摄魂怪击败，建议再购买点儿装备进行战斗。" << endl;
				}
			}
			else if (op1 == 2) {
				cout << "你已经逃离战斗。小矮星成功逃跑" << endl;
			}
			else {
				cout << "操作失败，你已退出该房间！" << endl;
			}
			break;
		}
	}
	return 1;
}

int Plot::init4(sorcerer *mySorcerer) {
	vector<Medicine> medicine_G4;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G4.push_back(medicineTempSmall);
	medicine_G4.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G4.push_back(medicineTempMiddle);
	medicine_G4.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G4.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G4(medicine_G4, a, "奇幻空间魔术用品店", 5);
	//商店里面有守护神咒可以买不买很难通关
	bool check = 1;

	Magicitem The_goblet_of_fire("火焰杯", 100);

	room hall("大厅");
	room auditorium("礼堂");
	room maze("迷宫");	//1迷宫 2坟墓
	room grave("坟墓");
	room office("办公室");
	mySorcerer->inRoom(&auditorium);
	//Magicitem phoenix("凤凰", 2);
	map map4("\t0.*******\t\t\t\t1.*******\t\t\t\t2.*******\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*礼堂\t*\t<--------------->\t*迷宫\t*\t---------------->\t*坟墓\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t   ||\n \t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   \\/\n\t\t\t\t\t\t\t\t\t\t\t3.*******\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*大厅\t*\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*********");
	cout << "哈利没有报名参加“三强争霸赛”却意外地成为了三强争霸赛的第四名勇士\n没想到更大的阴谋正在后面等着他。。。。。。。。" << endl;
	system("pause");
	system("cls");
	cout << "欢迎进入第四关~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;
	//cout << "据说与洗手间的桃金娘对话可以获得神秘的东西..." << endl;
	//goodPerson Sirius("小天狼星", "我跟詹姆斯和莉莉在一起那么久，你却没有，是很残忍。...\n");
	//villa.addGoodPerson(Sirius);
	badPerson voldemort(100, 10, 35, "伏地魔");
	badPerson Little_buddy(100, 10, 15, "小巴蒂");
	grave.addBadPerson(voldemort);
	office.addBadPerson(Little_buddy);
	int trueanswer = 0;
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
		map4.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		int op2 = 0;//办公室那儿的判断
		int op3 = 0;//逃跑时的判断
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
			cout << "还未设置" << endl;
			break;
		case 111:
			cout << "你已经结束该游戏。" << endl;
			return -1;
			break;
		default:
			cout << "操作失败！" << endl;
			break;
		case 0:
			mySorcerer->inRoom(&auditorium);
			cout << "欢迎来到 " << auditorium.getName() << endl;
			break;
		case 1:
			//迷宫
			system("cls");
			mySorcerer->inRoom(&maze);

			char indicatation;
			cout << "通过回答一些小问题你可以通过迷宫。" << endl;
			system("pause");
			while (trueanswer < 3) {
				trueanswer = 0;
				cout << "1、哈利波特的生日是几月几日？" << endl;
				cout << "A.8.31    B. 7.31    C.7.11" << endl;
				cin >> indicatation;
				switch (indicatation) {
				case 'B': {
					cout << "回答正确" << endl;
					cout << "2.咒语Imperio是什么意思？" << endl;
					cout << "A. 魂魄出窍              B. 钻心剜骨              C. 黑魔标记" << endl;
					cin >> indicatation;
					switch (indicatation) {
					case 'A': {
						cout << "回答正确" << endl;
						cout << "3. Bezoar 毛粪石有什么作用？" << endl;
						cout << "A. 用来解毒 B.对难缠的面疱有特别的疗效  C.在水里可以呼吸" << endl;
						cin >> indicatation;
						switch (indicatation) {
						case 'A': {
							cout << "回答正确" << endl;
							trueanswer = trueanswer + 1;
							break;
						}
						default: {
							cout << "回答错误" << endl;
							trueanswer = trueanswer;
							break;
						}
						}
						trueanswer = trueanswer + 1;
						break;
					}
					default: {
						cout << "回答错误" << endl;
						trueanswer = trueanswer;
						break;
					}
					}
					trueanswer = trueanswer + 1; break; }
				default: {
					cout << "回答错误" << endl;
					cout << "2.咒语Imperio是什么意思？" << endl;
					cout << "A. 魂魄出窍              B. 钻心剜骨              C. 黑魔标记" << endl;
					cin >> indicatation;
					switch (indicatation) {
					case 'A': {
						cout << "回答正确" << endl;
						cout << "3. Bezoar 毛粪石有什么作用？" << endl;
						cout << "A. 用来解毒 B.对难缠的面疱有特别的疗效  C.在水里可以呼吸" << endl;
						cin >> indicatation;
						switch (indicatation) {
						case 'A': {
							cout << "回答正确" << endl;
							trueanswer = trueanswer + 1;
							break;
						}
						default: {
							cout << "回答错误" << endl;
							trueanswer = trueanswer;
							break;
						}
						}
						trueanswer = trueanswer + 1;
						break;
					}
					default: {
						cout << "回答错误" << endl;
						cout << "3. Bezoar 毛粪石有什么作用？" << endl;
						cout << "A. 用来解毒 B.对难缠的面疱有特别的疗效  C.在水里可以呼吸" << endl;
						cin >> indicatation;
						switch (indicatation) {
						case 'A': {
							cout << "回答正确" << endl;
							trueanswer = trueanswer + 1;
							break;
						}
						default: {
							cout << "回答错误" << endl;
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

			cout << "你通过神奇的火焰杯，来到了一个神奇的地方" << endl;
			system("pause");
			system("cls");
			mySorcerer->inRoom(&grave);
			cout << "欢迎来到 " << grave.getName() << endl;
			//麻烦加一段文字，表明伏地魔复活。


			cout << "是否选择与伏地魔进行战斗:" << endl;
			cout << "1.是		2.否" << endl;
			cin >> op3;
			if (op3 == 1) {
				cout << "战斗过程中，发现实力差距较大，你使用火焰杯顺利逃脱。" << endl;
			}
			else {
				cout << "你使用火焰杯顺利逃脱。" << endl;
			}
			system("pause");
			system("cls");
			mySorcerer->inRoom(&hall);
		
			break;
		case 4:
			mySorcerer->inRoom(&office);
			cout << "欢迎来到" << office.getName() << endl;
			cout << "原来小巴蒂是食司徒!!!" << endl;
			cout << "你是否选择与它进行战斗？" << endl;
			cout << "1.是		2.否" << endl;
			cin >> op2;
			system("cls");
			if (op2 == 1) {
				bool ifWin = 0;
				cout << "战斗开始，你已进入战斗模式..." << endl;
				ifWin = mySorcerer->battle(mySorcerer, Little_buddy);
				if (ifWin) {
					cout << "恭喜你成功通过第四关关并获得了";
					check = 0;
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
				mySorcerer->inRoom(&hall);
			}
		}
	}
	cout << "恭喜你成功通过第四关。" << endl;
	system("pause");
	system("cls");
	return 1;
}


int Plot::init5(sorcerer *mySorcerer) {

	//药水配置待改
	vector<Medicine> medicine_G5;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G5.push_back(medicineTempSmall);
	medicine_G5.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G5.push_back(medicineTempMiddle);
	medicine_G5.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G5.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G5(medicine_G5, a, "奇幻空间魔术用品店", 5);
	bool check = 1;
	room Room_of_requirement("有求必应屋");
	room bathroom("洗手间");
	room hall("大厅");
	room The_ministry_of_magic("魔法部");
	room The_dragon_pavilion("神龙阁");
	map map5("\t1.*******\n\t*\t*\n\t*魔法部\t*\n\t*\t*\n\t*********\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t0.*******\t\t\t\t2.***************\n\t*\t*\t\t\t\t*\t\t*\n\t*大厅\t*<----------------------------->*有求必应屋\t*\n\t*\t*\t\t\t\t*\t\t*\n\t*********\t\t\t\t*****************\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t3.*******\n\t*\t*\n\t*神龙阁\t*\n\t*\t*\n\t*********");
	cout << "没有人相信伏地魔回来，\n哈利被认为是个骗子，\n只有他的朋友们相信并支持着他。\n哈利于伙伴们组建邓不利多军来抵抗，\n但到后来他中了伏地魔的诡计，\n与朋友们来到魔法部解救教父小天狼星。。。。。。。" << endl;
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "欢迎进入第五关~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;

	goodPerson Sirius("小天狼星", "我跟詹姆斯和莉莉在一起那么久，你却没有，是很残忍。...\n");
	badPerson Lucius(100, 10, 35, "卢修斯");
	The_ministry_of_magic.addGoodPerson(Sirius);

	badPerson Fire_dragon(100, 10, 35, "火龙");
	badPerson Earth_dragon(100, 10, 35, "土龙");
	badPerson Water_dragon(100, 10, 35, "水龙");
	badPerson Wind_dragon(100, 10, 35, "风龙");
	badPerson Far_from_cologne(100, 10, 35, "远古龙");
	//在神龙阁可以 挑战木龙，土龙，火龙，风龙和远古龙

	The_dragon_pavilion.addBadPerson(Fire_dragon);
	The_dragon_pavilion.addBadPerson(Earth_dragon);
	The_dragon_pavilion.addBadPerson(Water_dragon);
	The_dragon_pavilion.addBadPerson(Far_from_cologne);
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
		map5.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		bool ifWin = 0;
		int op3 = 0;//选龙
		int op1 = 0;//卢修斯
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
			cout << "还未设置" << endl;
			break;
		case 111:
			cout << "你已经结束该游戏。" << endl;
			return -1;
			break;
		default:
			cout << "操作失败！" << endl;
			break;
		case 3:	//进入神龙阁
			mySorcerer->inRoom(&The_dragon_pavilion);
			system("cls");
			cout << "欢迎来到 " << The_dragon_pavilion.getName() << endl;
			The_dragon_pavilion.inRoom();
			cout << "在这里你可以挑战巨龙，打败它们你可以获得相应的加成" << endl;
			cout << "1.火龙		2.风龙		3.水龙		4.土龙		5.远古龙	0.逃跑大厅" << endl;
			cin >> op3;
			switch (op3)
			{
			case 1:
				cout << "你准备挑战的是火龙...战斗即将开始。" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Fire_dragon);
				if (ifWin == 1) {
					cout << "恭喜你击败了了火龙并获得了属性加成。" << endl;
					//写属性加成商量后定
				}
				else {
					cout << "你被火龙击败，请调整状态后再来。" << endl;
				}
				break;
			case 2:
				cout << "你准备挑战的是风龙...战斗即将开始。" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Wind_dragon);
				if (ifWin == 1) {
					cout << "恭喜你击败了了风龙并获得了属性加成。" << endl;
					//写属性加成商量后定
				}
				else {
					cout << "你被风龙击败，请调整状态后再来。" << endl;
				}
				break;
			case 3:
				cout << "你准备挑战的是水龙...战斗即将开始。" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Water_dragon);
				if (ifWin == 1) {
					cout << "恭喜你击败了了水龙并获得了属性加成。" << endl;
					//写属性加成商量后定
				}
				else {
					cout << "你被水龙击败，请调整状态后再来。" << endl;
				}
				break;
			case 4:
				cout << "你准备挑战的是土龙...战斗即将开始。" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Earth_dragon);
				if (ifWin == 1) {
					cout << "恭喜你击败了了土龙并获得了属性加成。" << endl;
					//写属性加成商量后定
				}
				else {
					cout << "你被土龙击败，请调整状态后再来。" << endl;
				}
				break;
			case 5:
				cout << "你准备挑战的是远古龙...战斗即将开始。" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Far_from_cologne);
				if (ifWin == 1) {
					cout << "恭喜你击败了了远古龙并获得了属性加成。" << endl;
					//写属性加成商量后定
				}
				else {
					cout << "你被远古龙击败，请调整状态后再来。" << endl;
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
			cout << "欢迎来到 " << Room_of_requirement.getName() << endl;
			if (bathroom.getIfIn()) {
				cout << "欢迎您再次来到 " << Room_of_requirement.getName() << endl;
				break;
			}
			//在有求必应屋获得什么等待添加。
			Room_of_requirement.inRoom();
			break;
		case 1:

			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "欢迎来到 " << The_ministry_of_magic.getName() << endl;
			cout << "此时卢修斯正在魔法部里，你是否选择逃跑" << endl;
			cout << "1.否		2.是" << endl;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				cout << "卢修斯说的话" << endl;
				ifWin = mySorcerer->battle(mySorcerer, Lucius);
				if (ifWin == 1) {
					//成功打败的话
					check = 1;
				}
				else if (ifWin == 0) {
					cout << "挑战失败！" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
			else if (op1 == 2) {
				cout << "你成功逃离。" << endl;
				mySorcerer->inRoom(&hall);
			}
			else {
				cout << "操作失败！请正确输入。" << endl;
				mySorcerer->inRoom(&hall);
			}
			break;
		}
	}
	cout << "恭喜你通过第五关" << endl;
	return 1;
}


int Plot::init6(sorcerer *mySorcerer) {

	//药水配置待改
	vector<Medicine> medicine_G5;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G5.push_back(medicineTempSmall);
	medicine_G5.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G5.push_back(medicineTempMiddle);
	medicine_G5.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G5.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G5(medicine_G5, a, "奇幻空间魔术用品店", 5);
	bool check = 1;
	room hall("大厅");
	room The_ministry_of_magic("魔法部");
	room gringotts("古灵阁");
	map map6("\t1.*******\t\t\t\t2.*******\n\t*\t*\t\t\t\t*\t*\n\t*魔法部\t*\t<--------------->\t*古灵阁\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t  /\\\t\t\t\t\t   ||\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t0.*******\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*大厅\t*<===================================\n\t*\t*\n\t*********");
	//cout << "没有人相信伏地魔回来，\n哈利被认为是个骗子，\n只有他的朋友们相信并支持着他。\n哈利于伙伴们组建邓不利多军来抵抗，\n但到后来他中了伏地魔的诡计，\n与朋友们来到魔法部解救教父小天狼星。。。。。。。" << endl;
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "欢迎进入第六关~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;
	//在古灵阁需要打6个食死徒
	//在这里
	badPerson dolohov(100, 5, 10, "多洛霍夫");
	badPerson rookwood(100, 5, 10, "卢克伍德");
	badPerson bellatrix(100, 5, 10, "贝拉特里克斯");
	badPerson travers(100, 5, 10, "特拉弗斯");
	badPerson DoleFinn(100, 5, 10, "多尔芬");
	badPerson malfoy(100, 5, 10, "马尔福");
	gringotts.addBadPerson(dolohov);
	gringotts.addBadPerson(rookwood);
	gringotts.addBadPerson(bellatrix);
	gringotts.addBadPerson(travers);
	gringotts.addBadPerson(DoleFinn);
	gringotts.addBadPerson(malfoy);

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
		map6.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		bool ifWin = 0;
		int op1 = 1;	//选打什么怪用
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
			mySorcerer->inRoom(&The_ministry_of_magic);
			cout << "欢迎来到魔法部" << endl;
			break;
		case 2:
			op2 = 1;
			mySorcerer->inRoom(&gringotts);
			cout << "欢迎来到古灵阁，一群食死徒正在等着你。。。。。。";
			while (op2 == 1) {
				gringotts.showBadPerson();
				cout << "请输入你要对战的食死徒:(0是逃跑)" << endl;
				cin >> op1;
				if (op1 == 0) {
					cout << "逃跑成功！" << endl;
					mySorcerer->inRoom(&The_ministry_of_magic);
				}
				ifWin = mySorcerer->battle(mySorcerer, gringotts.getBadPerson(op1));	//	修改
				if (ifWin == 1) {
					gringotts.eraseBadPerson(op1);
					cout << "恭喜你你击败了一个食司徒,你可以选择继续战斗或者逃跑。" << endl;
					cout << "1.继续战斗		2.逃跑" << endl;
					cin >> op2;
					if (op2 == 2) {
						op2 = 0;
						cout << "逃跑成功！" << endl;
						mySorcerer->inRoom(&The_ministry_of_magic);
					}
					else {
						cout << "你选择了继续战斗" << endl;
					}
				}
				else {
					cout << "你被打败" << endl;
				}
				if (gringotts.getBadPersonSize() == 0) {
					check = 1;
					op2 = 0;
				}
			}

			break;
		}
	}
	cout << "恭喜你通过第六关" << endl;
	return 1;
}

int Plot::initFinal(sorcerer * mySorcerer)
{
	//药水配置待改
	vector<Medicine> medicine_G5;
	Medicine medicineTempSmall("小药水", 20, 400);
	medicine_G5.push_back(medicineTempSmall);
	medicine_G5.push_back(medicineTempSmall);
	Medicine medicineTempMiddle("中药水", 40, 800);
	medicine_G5.push_back(medicineTempMiddle);
	medicine_G5.push_back(medicineTempMiddle);
	Medicine medicineTempLarge("大药水", 60, 1200);
	medicine_G5.push_back(medicineTempLarge);
	vector<Skill> a;
	Shop shop_G2(medicine_G5, a, "奇幻空间魔术用品店", 5);
	bool check = 1;
	room hall("大厅");
	room The_black_forest("黑森林");
	map mapfinal("\t0.*******\t\t\t\t1.*******\n\t*\t*\t\t\t\t*\t*\n\t*大厅\t*\t---------------- > \t*黑森林\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	//cout << "没有人相信伏地魔回来，\n哈利被认为是个骗子，\n只有他的朋友们相信并支持着他。\n哈利于伙伴们组建邓不利多军来抵抗，\n但到后来他中了伏地魔的诡计，\n与朋友们来到魔法部解救教父小天狼星。。。。。。。" << endl;
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "欢迎进入第终局之战~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;

	badPerson voldemort(100, 5, 10, "伏地魔");


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
		mapfinal.showMap();
		cout << "请输入数字选择:" << endl;
		int op = 0;
		bool ifWin = 0;
		int op1 = 1;	//选打什么怪用
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
			mySorcerer->inRoom(&The_black_forest);
			cout << "欢迎来到魔法部" << endl;
			//加一些话
			cout << "此时伏地魔正在黑森林里，你是否选择进行最终之战" << endl;
			cout << "1.是		2.否" << endl;
			cin >> op1;
			system("cls");
			if (op1 == 1) {
				ifWin = mySorcerer->battle(mySorcerer, voldemort);
				if (ifWin == 1) {
					//成功打败的话
					check = 1;
				}
				else if (ifWin == 0) {
					cout << "挑战失败！" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
			else if (op1 == 2) {
				cout << "你成功逃离。" << endl;
				mySorcerer->inRoom(&hall);
			}
			else {
				cout << "操作失败！请正确输入。" << endl;
				mySorcerer->inRoom(&hall);
			}
			break;
		}
	}
	cout << "恭喜你通过所有关卡" << endl;
	return 1;
}