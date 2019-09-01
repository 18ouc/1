#ifndef _GOODPERSON_H
#define _GOODPERSON_H
#include <string>
#include "Person.h"
using namespace std;
class goodPerson :
	public Person
{
public:
	goodPerson(string name = 0, string sentence = 0) : name(name), sentence(sentence){}
	~goodPerson();
	string getName();
	string getSentence();
private:
	string sentence;
	string name;
};
#endif

