#pragma once
#include <string>
#include <vector>

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
	vector<int> inventory;

	public:
	// 외부 입력을 통한 값 초기화
		Player(const string name, const string& characterClass,bool isHardcore);
			
protected:
	// 자식 클랙스(바바리안,소서러스 등) 이 스태을 직접 지정할떄 사용되는 생성자 
	Player(const string& name, const string& characterClass,bool isHardcore,
		int str, int dex, int vit, int eng);
	
public:
	
	// Getters
	string GetName() const{return name;}
	string GetCharacterClass() const{return characterClass;}
	bool GetisHardcore() const{return isHardcore;}
	int GetExp() const{return exp;}
	int GetExptoNextLevel() const{return exptoNextLevel;}	
	
	// 기능 (함수)
	int CriticalAttack() const;
	virtual  string GetAttackMessage() const  {return "[Fire Enhanced Attack]";}
	void LevelUp() ;
	void GainExp(int amoudnt);
	void PreviewCritical() const;
	void PrintLevel() const;
	void Loot(int count =3); // 빈 슬롯부터 count개의 아이템 획득 -> 인벤토리에 저장 +출력
	
	
};