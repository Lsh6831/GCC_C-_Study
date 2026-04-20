#include <iostream>
using namespace std;


char userName[50];
char charactorClass[50];

int main()
{
	// 1. 다양한 자료형의 변수 선언 및 초기값 할당
	int level = 1;
	int hp = 100;
	int mp = 100;
	float attackspeed = 5.5f;

	//스탯 시스템
	int strength = 50;
	int dexterity = 50;
	int vitallity = 50;
	int energy = 50;

	// 하드코어 모드 여부 변수
	bool isHardcore = true;

	cout << "[ Character Creation ]\n";
	cout << "Input your name : ";
	cin >> userName;
	cout << "Input your Class : ";
	cin >> charactorClass;
	
	cout << "\n:::::::Welcom to the SCancuart ::::::\n";
	cout << "user Name : {" << userName << "\n}";

	//2. 변수에 저장된 데이터 출력
	cout << "------------Character Status----------|n";
	cout << "Class : " << charactorClass << "\n";
	cout << "Level : " << level<<"\n";
	cout << "HP : " << hp << "\n";
	cout << "Attack Speed : " << attackspeed << "\n";
	cout << "Strength : " << strength << "\n";
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitalty : " << vitallity << "\n";
	cout << "Energy : " << energy << "\n";
	cout << "Hardcore Mode : " << isHardcore << "(1: true, 0: flase)\n";

	// 3. siezof 연사자를 이용한 메모리 크기 확인
	cout << "[Memory Check] int type size : " << sizeof(hp) << "bytes\n";
	cout << "[Memory Check] vool type size : " << sizeof(isHardcore) << " bytes\n";




	
	return 0;
}