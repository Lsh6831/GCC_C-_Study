#pragma once
#include "Monster.h"
#include "Player.h"
#include "RIngbuffer.h"


class Battle
{
public:
    Player& player;
    Monster& monster;
    shared_ptr<Mercenary> mercenary; // 없는 경우 nullptr
    // string ncombatMessage;
    RIngbuffer<string> battleLog; // 링버퍼를 통해 최근 5개 전투 메시지를 저장

    Battle(Player& player, Monster& monster,shared_ptr<Mercenary> mercenary=nullptr);
    bool Run();
    void printHPBar(string name, int current, int max);
};
