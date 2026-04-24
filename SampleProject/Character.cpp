#include "Character.h"


Character::Character(int str, int dex, int vit, int eng, int lv)
    : strength(str), dexterity(dex), vitality(vit), energy(eng), level(lv),
    fireResist(0), coldResist(0), lightResist(0), poisonResist(0)
{
    maxhp = vitality * 10; // 기본 체력 설정 (필요에 따라 조절)
    hp = maxhp;
    maxmp = (int)(energy * 1.5f);
    mp = maxmp;
    attackDamage = strength * 0.2f;
    attackSpeed = dexterity / 10.0f;
    movingSpeed = 1.0; // 기본 이동 속도
}

void Character::TakeDamage(int damage)
{
    hp -= damage;
    if (hp <= 0) hp=0;
}

int Character::Attack() const
{
    return (int)attackDamage;
}
