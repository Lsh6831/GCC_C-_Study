#include "Player.h"
#include "Item.h"
#include<iostream>
#include <string>
#include  <iomanip>
class Item;

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

Player::Player(const string& name, const string& characterClass, bool isHardcore, 
    int str, int dex, int vit, int eng)
        : Character(str,dex,vit,eng,1),exp(0),exptoNextLevel(100){}

Player::~Player()
{
    cout<<"[플레이어 소멸]"<<name << endl;
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

void Player::Loot(unique_ptr<Item> item)
{
    if (!item) return;
    cout << "\n[System] Looting Items...\n";
    cout << "[획득] "<< item->name <<"\n";
    inventory.push_back(*item);
}

void Player::PrintInventory() const
{
    // 인벤토리 출력
    cout << "==================================================\n";
    cout << "||" << left << setw(46) << "          INVENTORY" << "||\n";
    cout << "==================================================\n";
    
    // count개 아이템을 vector에 추가
    for (int i = 0; i < inventory.size(); i++)
    {
        string typeStr;
        if (inventory[i].type == ItemType::Weapon) typeStr = "Weapon";
        else if (inventory[i].type == ItemType::Armor) typeStr = "Armor";
        else typeStr = "Consumable";
        cout << " > Slot " << i << " < [" << inventory[i].name <<"]\n";
    }
}