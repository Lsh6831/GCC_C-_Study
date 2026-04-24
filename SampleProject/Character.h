#pragma once

class Character
{	
protected:
	
    //기본 늘력치
    int strength,dexterity,vitality,energy;
	
    // 파생 능력치
    int level;
    int hp,maxhp;
    int mp,maxmp;
    float attackDamage;
    float attackSpeed;
    double movingSpeed;
	
    // 저항 능력치
    int fireResist,coldResist,lightResist,poisonResist;
	
	public:
	// Constructor
	Character(int str,int dex,int vit, int eng , int lv= 1);
	virtual ~Character() {} // 가상 소멸자 : 자식 소멸자까지 안전하게 호출
	
	int getStrength() const{return strength;}
	int getDexterity() const{return dexterity;}
	int getVitality() const{return vitality;}
	int getEnergy() const{return energy;}
	int getLevel() const{return level;}
	int getHP() const{return hp;}
	int getMaxHP() const{return maxhp;}
	int getMP() const{return maxmp;}
	int getMaxMP() const{return maxmp;}
	int getfireResist() const{return fireResist;}
	int getColdResist() const{return coldResist;}
	int getLightResist() const{return lightResist;}
	int getPoisonResist() const{return poisonResist;}
	float getattackDamage() const{return attackDamage;}
	float getattackspeed() const{return attackSpeed;}
	float getMovingspeed() const{return movingSpeed;}
	bool isAlive() const{return hp>0;}
	
	void TakeDamage(int damage);
	virtual	 int Attack() const;
};
