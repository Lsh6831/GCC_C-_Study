#include "ItemData.h"


// 아이템 추가시 이 파일만 수정하면 됨

unordered_map<int, ItemData> createItemDB()
{
    unordered_map<int, ItemData> db;
    
    // 100번대 : Consumable /200번대 Weapon / 300 번대 Armor / 400번대 ETC
    db[101] = {"Healing_Potion",ItemType::Consumable};
    db[102] = {"Mana Potion",ItemType::Consumable};
    db[103] = {"Rejuvenation Potion",ItemType::Consumable};
    db[201] = {"Healing_Potion",ItemType::Weapon};
    db[201] = {"Healing_Potion",ItemType::Weapon};
    db[301] = {"Healing_Potion",ItemType::Armor};
    db[301] = {"Healing_Potion",ItemType::Armor};
    db[401] = {"Healing_Potion",ItemType::ETC};
    db[401] = {"Healing_Potion",ItemType::ETC};
    
    return db;
}
