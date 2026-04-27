#pragma once
#include "Character.h"
#include  <string>
using namespace std;


class Monster : public Character
{
private:
	string name;
	int expReward;
	
public:
	Monster(const string& name, int str,int dex,int vit, int eng,int expReward ,int lv= 1);
	virtual ~Monster();// 소멸자
    
	string GetName() const{return name;};
    int GetExpReward() const{return expReward;};
	
	virtual string GetAttackMessage() const{return "";};
};