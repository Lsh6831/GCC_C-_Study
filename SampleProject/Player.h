#pragma once
#include <string>
using namespace std;


//Player 클래스
class Player
{
	private:
	//기본 정보	
	string name;
	string characterClass;
	bool isHardcore;
	
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
	
	// 이벤토리
	int inventory[5];

	public:
		Player(const string name, const string& characterClass,bool isHardcore);// 외부 입력을 통한 값 초기화
			
	
	// Getters
	string GetName() const{return name;}
	string GetCharacterClass() const{return characterClass;}
	bool GetisHardcore() const{return isHardcore;}
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
	
	
	int*GetInventory(){return inventory;}
	
	// 기능 (함수)
	bool isAlive() const{return hp>0;}
	void TakeDamage(int damage);
	int Attack() const;
	int CriticalAttack() const;
	void LevelUp() ;
	
	void PreviewCritical() const;
	void PrintLevel() const;
	
};