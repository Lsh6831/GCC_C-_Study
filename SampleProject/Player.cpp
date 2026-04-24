#include "Player.h"
#include<iostream>
#include <string>
#include  <iomanip>
Player::Player(const string name, const string& characterClass, bool isHardcore)
//외부 입력값 세팅
: Character(50,50,50,50,1),
name(name), characterClass(characterClass), isHardcore(isHardcore),
exp(0), exptoNextLevel(100)//단순 값 세팅 초기화
{
    maxhp = vitality *2 ;//계산이 필요한 값 세팅
    hp = maxhp;
    maxmp = (int)energy *1.5f ;
    mp = maxmp;
    attackDamage = strength*0.2f;
    attackSpeed = dexterity / 10.0f;
    movingSpeed = movingSpeed / 30.f;
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
    return (int)(attackDamage*10);
}

void Player::GainExp(int amoudnt)
{
    exp += amoudnt;
    if (exp >= exptoNextLevel)
    {
        exp -= exptoNextLevel;
        level++;
        
        exptoNextLevel = level*100;
        cout << "[레벨 업!] Level:" << level << "\n";
    }
}

void Player::Loot(int count)
{
    // count 개 아이켐을 vector에 추가
    for (int i=0; i<count; i++)
    {
        //랜덤 숫자 1개씩 인벤토리에 벡터에 넣음
        inventory.push_back(rand()%4+1);
        
        // 인벤토리 출력
        // cout << " --------------------------------------------\n";2
        // cout << " ------------"<<left << setw(46)<<"-----\n";
        // cout << " --------------------------------------------\n";
        for (int i=0; i<inventory.size(); i++)
        {
            string itemName;
            if (inventory[i] == 1) itemName = "Gold";
            else if (inventory[i] == 2) itemName = "Healing Potion";
            else if (inventory[i] == 3) itemName = "Weapon";
            else if (inventory[i] == 4) itemName = "Armor";
            else itemName = "None";
            cout << " > Slot " << i << "[" << itemName << "]\n";
        }
    }
}