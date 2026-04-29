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
    
}

Player::Player(const string& name, const string& characterClass, bool isHardcore, 
    int str, int dex, int vit, int eng)
        : Character(str,dex,vit,eng,1),exp(0),exptoNextLevel(100)
{
    inventory.reserve(6);  // 재할당에 따른 복사 (Reallocation)를 방지하기 위해서 미리 capacity 확보
}

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

void Player::Loot(Item item)
{
    
    cout << "[획득] "<< item.name <<"\n";
    inventory.emplace_back(std::move(item)); // Item을 인벤토리 안으로 직접 이동 
    
    cout<< "[인벤토리] size = " << inventory.size() << "capacity = "  <<inventory.size()<<"\n";
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

bool Player::UseItem(const string& itemName)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it->name == itemName)
        {
            if (it->type == ItemType::Consumable)
            {
                Heal(maxhp); //전체회복
            }
            it = inventory.erase(it);//erase 후 유효한 iterator 반환 
            cout<< "[인벤토리] 아이템 사용 후 size = "<<inventory.size()<<"capacity"<<inventory.capacity()<<"\n";
            return true;
        }
    }
    return false;
}
