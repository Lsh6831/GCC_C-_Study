#include "Battle.h"
#include  <iostream>
#include  <cstdlib>
#include <iomanip>

Battle::Battle(Player& player, Monster& monster)
    :player(player), monster(monster), ncombatMessage("[System] Battle Started") {}

void Battle::printHPBar(string name, int current, int max)
{
    int barWidth = 20;
    float ratio = (max > 0) ? (float)current / max : 0;
    int pos = (int)(barWidth * ratio);

    cout << " " << name << " [";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << current << " / " << max << "\n";
}

bool Battle::Run()
{
    int action;

    while (monster.isAlive() && player.isAlive())
    {
        system("cls");
        // 스테이터스 상단 유지
        cout << " /================== CHARACTER STATUS ===================\\\n";
        cout << " |  Class    : " << player.GetCharacterClass() << "\t\t Level : " << player.getLevel() << "\t |\n";
        cout << " |  HP       : " << player.getHP() << "\t\t MP    : " << player.getMP() << "\t |\n";
        cout << " \\=======================================================/\n\n";

        cout << "      _---_\n";
        cout << "     /     \\\n";
        cout << "    | () () |   <--- [ GOBLIN ]\n";
        cout << "     \\  ^  /\n";
        cout << "      |||||\n\n";

        // 시각적 체력바 출력
        printHPBar("GOBLIN", monster.getHP(), 50); // 고블린 최대 HP 50으로 가정 (main.cpp 참고)
        printHPBar("PLAYER", player.getHP(), player.getMaxHP());

        cout << "\n +---------------- COMMANDS ----------------+\n";
        cout << " |  1. Physical Attack                      |\n";
        cout << " |  2. Critical Attack                       |\n";
        cout << " +------------------------------------------+\n";
        cout << " Select Action : ";
        cin >> action;

        cout << "\n [ Battle Log ]\n";
        cout << " --------------------------------------------\n";
        if (action == 1)
        {
            int damage = player.Attack();
            monster.TakeDamage(damage);
            cout << " => You swung your weapon! [ -" << damage << " Damage ]\n";

            if (monster.isAlive())
            {
                int mDamage = monster.Attack();
                player.TakeDamage(mDamage);
                cout << " => The Goblin counterattacks! [ -" << mDamage << " Damage ]\n";
            }
        }
        else if (action == 2)
        {
            int damage = player.CriticalAttack();
            monster.TakeDamage(damage);
            cout << "\n>> [YOU] Critical Hit! " << damage << " damage!\n";

            if (monster.isAlive()) {
                int mDamage = monster.Attack();
                player.TakeDamage(mDamage);
                cout << ">> [GOBLIN] counter-attacked! You lost " << mDamage << " HP.\n";
            }
        }
        else
        {
            cout << " => You panicked! The Goblin seized the opening!\n";
            int mDamage = monster.Attack();
            player.TakeDamage(mDamage);
        }

        cout << "\n Press [Enter] to continue...";
        cin.ignore(1000, '\n');
        cin.get();
    }
    return player.isAlive();
}

