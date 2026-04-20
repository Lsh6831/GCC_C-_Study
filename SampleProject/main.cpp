#include <iostream>
#include <String>
using namespace std;



int main()
{

	char userName[50];
	//char charactorClass[50];
	string charactorClass;
	int classChoiceInput;

	//스탯 시스템
	int strength = 50;
	int dexterity = 50;
	int vitallity = 50;
	int energy = 50;

	// 1. 다양한 자료형의 변수 선언 및 초기값 할당
	int level = 1;
	int hp = 100;
	int mp = 100;
	float attackSpeed = dexterity / 10.0;
	float attckDamage = strength * 0.2f;
	double movingSpeed = dexterity / 30.0;
	
	//
	char hardcoreInput = true;



	//Ressist
	int fireResist = 0;
	int lightingRessist = 0;
	int coldRessist = 0;
	int poisonRessist = 0;




	// 하드코어 모드 여부 변수
	bool isHardcore = true;

	cout << "[ Character Creation ]\n";
	cout << "Input your name : ";
	cin >> userName;

	cout << "Select your Class : \n";
	cout << "1. Amazon\n2. Assassin\n3. Barbarian\n4. Druid\n";
	cout << "4. Necromancer\n6. Paladin\n7. Socreress\n8. Warlcock\n";
	cout << "Input Class Number : ";
	cin >> classChoiceInput;

	switch (classChoiceInput)
	{
	case 1: charactorClass = "Amazon"; break;
	case 2: charactorClass = "Assassin"; break;
	case 3: charactorClass = "Barbarian"; break;
	case 4: charactorClass = "Druid"; break;
	case 5: charactorClass = "Necromancer"; break;
	case 6: charactorClass = "Paladin"; break;
	case 7: charactorClass = "Socreress"; break;
	case 8: charactorClass = "Warlcock"; break;
	default: charactorClass = "UnKnown";
		cout << " [System] Invalid class selection. Default to 'Unknown'\n";
		break;
	}




	//cin >> charactorClass;
	cout << "Enable Hardcore Mode ? (1) Yes / (2) NO : \n";
	cin >> hardcoreInput;

	if (hardcoreInput == '1')
	{
		isHardcore = true;
		cout << "[System] Hardcore mode enable. Death is permanvent.\n";
	}
	else if(hardcoreInput =='2')
	{
		isHardcore = false;
		cout << "[System] Standard mode Enable.\n";
	}
	else
	{
		isHardcore = false;
		cout << "[System] Invalid input . Defaulting to Standard.\n";
	}


	
	cout << "\n:::::::Welcom to the SCancuart ::::::\n";
	cout << "user Name : {" << userName << "\n}";

	//2. 변수에 저장된 데이터 출력
	cout << "------------Character Status----------\n";
	cout << "Class : " << charactorClass << "\n";
	cout << "Level : " << level<<"\n";
	cout << "HP : " << hp << "\n";
	cout << "Attck Damage : " << attckDamage << "\n";
	cout << "Attack Speed : " << attackSpeed << "\n";
	cout << "MovingSpeed : " << movingSpeed << "\n";
	cout << "Strength : " << strength << "\n";	
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitalty : " << vitallity << "\n";
	cout << "Energy : " << energy << "\n";
	cout << "Hardcore Mode : " << isHardcore << "(1: true, 0: flase)\n";

	cout << "Fire Resistance : " << fireResist << "\n";
	cout << "LightingRessist : " << lightingRessist << "\n";
	cout << "ColdRessist : " << coldRessist << "\n";
	cout << "PoisonRessist : " << poisonRessist << "\n";


	// 3. siezof 연사자를 이용한 메모리 크기 확인
	cout << "[Memory Check] int type size : " << sizeof(hp) << "bytes\n";
	cout << "[Memory Check] vool type size : " << sizeof(isHardcore) << " bytes\n";


	
	return 0;
}