#include <iostream>
using namespace std;
int main() {
	cout << "Harry		Potter" << endl;
	cout << "1.�µ���;			2.��ȡ�浵			3.�˳�" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		cout << "���Ѿ��ɹ��˳���Ϸ��" << endl;
		return 0;
	default:
		cout << "����������������룡" << endl;
	}
}