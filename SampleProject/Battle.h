#pragma once
#include "Monster.h"
#include "Player.h"


class Battle
{
public:
    Player& player;
    Monster& monster;
    string ncombatMessage;

    Battle(Player& player, Monster& monster);
    bool Run();
    void printHPBar(string name, int current, int max);
};
