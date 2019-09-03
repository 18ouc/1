#include <iostream>
#include "sorcerer.h"
#include "Plot.h"
using namespace std;
int main() {
	int ifEnd = 0;
	sorcerer *mySorcerer = new sorcerer;
	Plot myPlot;
	cout << "Harry		Potter" << endl;
	cout << "1.新的旅途			2.读取存档			3.退出" << endl;
	int choice;
	cin >> choice;
	system("cls");
	switch (choice) {
	case 1:
		myPlot.init_new(mySorcerer);
		//ifEnd = myPlot.init1(mySorcerer);
		//if (ifEnd == -1)
		//	return 0;
		//ifEnd = myPlot.init2(mySorcerer);
		//ifEnd = myPlot.init3(mySorcerer);
		//ifEnd = myPlot.init4(mySorcerer);
		//ifEnd = myPlot.init5(mySorcerer);
		ifEnd = myPlot.init6(mySorcerer);
		break;
	case 2:
		break;
	case 3:
		cout << "你已经成功退出游戏。" << endl;
		return 0;
	default:
		cout << "输入错误请重新输入！" << endl;
	}
	delete mySorcerer;
}