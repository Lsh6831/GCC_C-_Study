#pragma once
#include <string>

#include "Character.h"
using namespace std;


// Character 클래스 상속 받음Player 클래스
class Player : public  Character
{
	private:

	//Player 고유 정보
	string name;
	string characterClass;
	bool isHardcore;
	
	// 경험치
	int exp, exptoNextLevel;
	
	
	
	// 이벤토리
	int inventory[5];

	public:
		Player(const string name, const string& characterClass,bool isHardcore);// 외부 입력을 통한 값 초기화
			
	
	// Getters
	string GetName() const{return name;}
	string GetCharacterClass() const{return characterClass;}
	bool GetisHardcore() const{return isHardcore;}
	int GetExp() const{return exp;}
	int GetExptoNextLevel() const{return exptoNextLevel;}	
	int*GetInventory(){return inventory;}
	
	// 기능 (함수)
	int CriticalAttack() const;
	void LevelUp() ;
	void GainExp(int amoudnt);
	void PreviewCritical() const;
	void PrintLevel() const;
	
};