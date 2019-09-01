#include "Shop.h"
void Shop::buy(sorcerer * mysorcerer)
{
	cout << "请输入您要购买的药瓶编号：(按0退出）" << endl;
	int op;
	cin >> op;
	if (op == 0) {
		cout << "欢迎您的光临！" << endl;
	}
	else {
		vector<Medicine>::iterator it;
		it = medicine.begin() + op - 1;
		cout << "您购买了" << medicine[op - 1].getName() << ",花费了" << medicine[op - 1].getPrice() << endl;
		mysorcerer->decreaseMoney(medicine[op - 1].getPrice());
		mysorcerer->addMedicine(medicine[op - 1]);
		medicine.erase(it);
	}
}

void Shop::showShop(sorcerer * mysorcerer)
{
	cout << "欢迎魔法师" << mysorcerer->getName() << "进入商店！！！" << endl;
	cout << "目前商店的存货情况:" << endl;
	cout << "药水:" << endl;
	for (int i = 0; i < medicine.size(); i++) {
		cout << i + 1 << ".名称:" << medicine[i].getName()  << " 价格:" << medicine[i].getPrice() << " 恢复值：" << medicine[i].getRecoverValue() << endl;
	}
	buy(mysorcerer);
}
