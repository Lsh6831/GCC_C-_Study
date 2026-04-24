#pragma once
using namespace std;


class Monster
{
private:
	
    int hp,maxhp;
    int attackDamage;
	
public:
    Monster(int inithp,int atk);
    ~Monster();
    
    
    int GetHp() const{return hp;}
    int GetMaxHp() const{return maxhp;}
    bool isAlive() const{return hp>0;}
    void TakeDamage(int damage);
    int Attack() const{return attackDamage;} // 몬스터가 플레이어를 공격
};