#ifndef _SHOP_
#define _SHOP_
#include <iostream>
#include <string>
#include "sorcerer.h"
#include "Medicine.h"
using namespace std;
class Shop {
public:
	Shop(vector<Medicine> medicine, string name = 0, int number = 0) : name(name), medicine(medicine), number(number) {};
	void buy(sorcerer * mysorcerer = NULL);
	void showShop(sorcerer *mysorcerer);
private:
	string name;
	vector<Medicine> medicine;
	int number;
};

#endif