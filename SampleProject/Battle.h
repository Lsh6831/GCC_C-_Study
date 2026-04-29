#pragma once
#include "Monster.h"
#include "Player.h"


class Battle
{
public:
    Player& player;
    Monster& monster;
    shared_ptr<Mercenary> mercenary; // 없는 경우 nullptr
    string ncombatMessage;
    

    Battle(Player& player, Monster& monster,shared_ptr<Mercenary> mercenary=nullptr);
    bool Run();
    void printHPBar(string name, int current, int max);
};
