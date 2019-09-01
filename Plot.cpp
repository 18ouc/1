#include "Plot.h"

int Plot::init1(sorcerer * mySorcerer)
{
	bool end = 0;
	cout << "魔法师们，为了让你们变得更加强大！我们给了你一件礼物。" << endl;
	Magicitem magicStick("魔法棍", 1);
	mySorcerer->addMagicitem(magicStick);
	system("pause");
	system("cls");
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

	mySorcerer->inRoom(&hall);
	//map map1("\t\t\t\t\t\t\t\t2.***************\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t****\t阁楼\t***\n\t\t\t\t\t\t\t\t****\t\t***\n\t\t\t\t\t\t\t\t*******************\n\n1.********\n***\t***\n***校长室**\n***\t***\n***********\n");
	map map1("\t*********\t\t\t\t*********\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*大厅\t*\t < --------------->\t*密室\t*\t----------->\t*地穴\t*\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t*********\n\t / \\.\t\t\t\t\t / \\.\t\n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t || \t\t\t\t\t || \n\t  \\ / \t\t\t\t\t || \t\n\t*********\t\t\t\t || \n\t*\t*\t\t\t\t || \n\t*阁楼\t *= ================================== = \n\t*\t*\n\t*********");
	cout << "从小被寄养在姨妈家里的哈利波特\n饱受姨妈一家人的歧视与欺侮\n然而就在11岁生日那天\n哈利波特得知了自己原本是巫师\n并且被录取为霍格沃茨魔法学校中的一员。\n登上霍格沃茨特快列车\n哈利开始了他的魔幻旅程在这里他无意间发现了魔法石的秘密。。。。。。" << endl;
	system("pause");
	system("cls");
	cout << "欢迎进入第一关~" << endl;
	cout << "恭喜你在开局获得了一个咒语，你可以通过它进入某个房间..." << endl;
	goodPerson Dumbledore("邓布利多", "明天镜子就要搬到一个新的地方了，哈利，我请你不要再去找它了。如果你哪天碰巧看见它，你要有心理准备。\n");
	President_Office.addGoodPerson(Dumbledore);
	badPerson Chiro(100, 10, 35, "奇洛");
	badPerson Kerberos(20, 0, 5, "三头狗");
	Crypt.addBadPerson(Chiro);

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
		map1.showMap();
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
			shop_G1.showShop(mySorcerer);
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
			mySorcerer->inRoom(&President_Office);
			system("cls");
			cout << "欢迎来到 " << President_Office.getName() << endl;
			if (President_Office.getIfIn()) {
				cout << "欢迎您再次来到 " << President_Office.getName() << endl;
				break;
			}
			cout << "\n" << Dumbledore.getName() << "：" << Dumbledore.getSentence() << endl;
			cout << "在与" << Dumbledore.getName() << "进行完谈话之后， 获得了一个咒语。" << endl;
			mySorcerer->addSkill(Alohomora);
			mySorcerer->increaseSkillNum();
			President_Office.inRoom();
			break;
		case 2:
			mySorcerer->inRoom(&Attic);
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
				ifWin = mySorcerer->battle(mySorcerer, Kerberos);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "你通过战斗轻松解决了" << Kerberos.getName() << "。并通过开门的咒语成功进入地穴......" << endl;
					system("pause");
					system("cls");
					cout << "欢迎来到地穴~" << endl;
					mySorcerer->inRoom(&Crypt);
					cout << "此时奇洛正在镜子旁，你是否选择与它进行战斗？" << endl;
					cout << "1.是		2.否" << endl;
					int op2 = 0;
					cin >> op2;
					system("cls");
					if (op2 == 1) {
						bool ifWin = 0;
						cout << "战斗开始，你已进入战斗模式..." << endl;
						ifWin = mySorcerer->battle(mySorcerer, Chiro);
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
	return 1;
}

void Plot::init_new(sorcerer * mySorcerer)
{
	cout << "请选择你的人物:" << endl;
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
		cout << "输入错误！请重新输入！" << endl;
		break;
	}
}

Plot::Plot()
{
}

Plot::~Plot()
{
}