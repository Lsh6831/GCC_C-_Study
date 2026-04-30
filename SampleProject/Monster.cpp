#include "Monster.h"

#include  <iostream>


Monster::Monster(const string& name, const MonsterData& data, int lv) 
: Character(data.str, data.dex, data.vit, data.eng, lv)
, name(name), expReward(data.expReward), dropPool(data.dropPool)
{

}


int Monster::Drop() const
{
    // 50% 확률로 아이템이 드롭 되도록, 아이템 종류는 랜덤
    // if (rand() % 2 == 0) return nullptr; // 일반 몬스터는 절반 확률로 드롭 없음
    
    if (dropPool.empty() || rand() % 2 ==0) return -1; // 플이 없거나 50%확률로 드롭아이템 없음
    return dropPool[rand() % dropPool.size()]; //드롭 풀에서 랜덤으로 선택
    
    
    
    
    // int roll = rand() % 3; // 0, 1, 2 중
    // if (roll == 0) return make_unique<Item>("Short Sword", ItemType::Weapon);
    // else if (roll == 1) return make_unique<Item>("leather Armor", ItemType::Armor);
    // else return make_unique<Item>("Healing Potion", ItemType::Consumable);
}