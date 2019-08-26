#include <iostream>
using namespace std;
int main() {
	cout << "Harry		Potter" << endl;
	cout << "1.新的旅途			2.读取存档			3.退出" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		cout << "你已经成功退出游戏。" << endl;
		return 0;
	default:
		cout << "输入错误请重新输入！" << endl;
	}
}