#include "FireGoblin.h"


FireGoblin::FireGoblin(const string& name, const MonsterData& data, int lv)
    : Monster(name, data, lv) {}

int FireGoblin::Attack() const
{
    return (int)attackDamage*1.5f;
}
// unique_ptr<Item> FireGoblin::Drop() const
// {
//     int roll = rand() % 2;
//     if (roll == 0) return make_unique<Item>("Fire Staff", ItemType::Weapon);
//     else return make_unique<Item>("Flame Crystal", ItemType::Consumable);
// }