#ifndef _SKILL_H
#define _SKILL_H
#include <string>
using namespace std;
class Skill
{
public:
	Skill();
	~Skill();
	void damage();
private:
	string name;
};

#endif // !_SKILL_H


