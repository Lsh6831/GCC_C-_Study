#include "Player.h"
#include<iostream>
#include <string>

Player::Player(const string name, const string& characterClass, bool isHardcore)
: name(name), characterClass(characterClass), isHardcore(isHardcore),
      strength(50), dexterity(50), vitality(50), energy(50),
      level(1),
      fireResist(0), coldResist(0), lightResist(0), poisonResist(0)
{
    maxhp = vitality *2 ;//계산이 필요한 값 세팅
    hp = maxhp;
    maxmp = (int)energy *1.5f ;
    mp = maxmp;
    attackDamage = strength*0.2f;
    attackSpeed = dexterity / 10.0f;
    movingSpeed = movingSpeed / 30.f;
			
    for (int i = 0; i < 5; i++) inventory[i] = 0;
}

void Player::TakeDamage(int damage)
{
    hp -= damage;
    if (hp<=0) hp = 0;    
}

void Player::LevelUp()
{
    level++;
}
void  Player::PreviewCritical() const
{
    float preview = attackDamage*2;
    cout << "크리티컬 예상 데미지 : "<<preview<<"\n";
			
}
void Player:: PrintLevel() const
{
    cout <<"현재레밸"<<level<<"\n";
}
	
int Player:: CriticalAttack() const
{
    return (int)(attackDamage*2);
}


int Player:: Attack() const
{
    return (int)attackDamage;
}