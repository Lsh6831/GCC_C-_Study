#include <iostream>
#include <String>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// --- 엔딩 장면 출력 함수 ---
void ShowEnding(bool isVictory, bool isHardcore) {
	system("cls"); // 엔딩 페이지를 위해 화면 정리

	if (!isVictory) {
		cout << "  __     ______  _    _   _____ _____ ______ _____  \n";
		cout << "  \\ \\   / / __ \\| |  | | |  __ \\_   _|  ____|  __ \\ \n";
		cout << "   \\ \\_/ / |  | | |  | | | |  | || | | |__  | |  | |\n";
		cout << "    \\   /| |  | | |  | | | |  | || | |  __| | |  | |\n";
		cout << "     | | | |__| | |__| | | |__| || |_| |____| |__| |\n";
		cout << "     |_|  \\____/ \\____/  |_____/_____|______|_____/ \n";
		cout << "\n [System] You died...\n";
		if (isHardcore) {
			cout << " [System] Hardcore Mode: Your character has been deleted forever.\n";
		}
	}
	else {
		cout << "  __      _______ _____ _______  ____  _______     __ \n";
		cout << "  \\ \\    / /_   _/ ____|__   __|/ __ \\|  __ \\ \\   / / \n";
		cout << "   \\ \\  / /  | || |       | |  | |  | | |__) \\ \\_/ /  \n";
		cout << "    \\ \\/ /   | || |       | |  | |  | |  _  / \\   /   \n";
		cout << "     \\  /   _| || |____   | |  | |__| | | \\ \\  | |    \n";
		cout << "      \\/   |_____\\_____|  |_|   \\____/|_|  \\_\\ |_|    \n";
		cout << "\n [System] You defeated the Goblin!\n";
		cout << " [System] Press [Enter] to claim your rewards...";
		cin.get();

		cout << "\n [ LOOT WINDOW ]\n";
		cout << " --------------------------------------------\n";
		srand((unsigned int)time(NULL));

		for (int i = 1; i <= 3; i++) {
			int lootRoll = rand() % 4;
			string itemName;

			if (lootRoll == 0) itemName = "Gold Pouch";
			else if (lootRoll == 1) itemName = "Healing Potion";
			else if (lootRoll == 2) itemName = "Steel Sword";
			else itemName = "Leather Armor";

			cout << "  * Slot [" << i << "]: " << itemName << " found!\n";
		}
		cout << " --------------------------------------------\n";
		cout << " [System] Adventure complete. Press [Enter] to exit.";
		cin.get();
	}
}

int main()
{
	// 콘솔 출력 인코딩을 UTF-8로 설정 (한글 깨짐 방지)
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

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
	float attackDamage = strength * 0.2f;
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


	//// "&" 주소 연산자

	//cout << "hp변수의 값 : " << hp << "\n";
	//cout << "hp변수의 주소값 : " << &hp << "\n"; //변수의 주소값 출력 & 앰퍼샌드 연산자 사용
	////system("pause"); 이거 왜 시스템 오류 나지

	//"*" 역참조 연산자

	int* ptr = &hp;
	cout << "ptr ==&hp :" << ptr<<"\n";
	cout << "ptr 값 : " << *ptr << "\n"; // 포인터를 역참조 하여 hp 값 읽기
	
	*ptr = 200; // 포인터를 역참조하여 hp 값 쓰기및 수정
	cout << "hp변수의 새로운 값 : " << hp << "\n";

	//int* tprt2 = nullptr;  //nulptr 안전 초기화 
	//cout << "tprt2 값 : " << *tprt2 << "\n";

	cout << "sizeof(int) : " << sizeof(int) << "byte\n";
	cout << "sizeof(int*) : " << sizeof(int*) << "byte\n"; //포인터 변수는 주소를 담기 때문에 모두 8바이트로 되어있음
	cout << "sizeof(double) : " << sizeof(double) << "byte\n";
	cout << "sizeof(double-) : " << sizeof(double*) << "byte\n";
	cout << "sizeof(char*) : " << sizeof(char*) << "byte\n";

	

	// 포인터 연산 (+1 = 자료형 메모리 크기만큼 이동)

	cout << "ptr 1 : " << ptr << "\n";
	cout << "ptr 2 : " << ptr +1 << "\n";
	cout << "ptr 3 : " << ptr +2 << "\n";

	int score[5] = { 85,92,78,95,88 };
	cout << "&score[0] : " << &score[0] << "\n";
	cout << "&score[0] : " << &score[1] << "\n";
	cout << "&score[0] : " << &score[2] << "\n";
	cout << "&score[0] : " << &score[3] << "\n";
	cout << "&score[0] : " << &score[4] << "\n";



	


	cout << "================================================================================\n";
	cout << "  ____ _                               _              ____                _   _ \n";
	cout << " / ___| |__   __ _ _ __ __ _  ___| |_ ___ _ __  / ___|_ __ ___  __ _| |_(_) ___  _ __ \n";
	cout << "| |   | '_ \\ / _` | '__/ _` |/ __| __/ _ \\ '__| | |   | '__/ _ \\/ _` | __| |/ _ \\| '_ \\ \n";
	cout << "| |___| | | | (_| | | | (_| | (__| ||  __/ |    | |___| | |  __/ (_| | |_| | (_) | | | |\n";
	cout << " \\____|_| |_|\\__,_|_|  \\__,_|\\___|\\__\\___|_|     \\____|_|  \\___|\\__,_|\\__|_|\\___/|_| |_|\n";
	cout << "================================================================================\n\n";

	cout << " [ Input your name ] : ";
	cin >> userName;

	cout << "\n [ Select your Class ]\n";
	cout << "  +-------------+-------------+-------------+-------------+\n";
	cout << "  | 1. Amazon   | 2. Assassin | 3. Barbarian| 4. Druid     |\n";
	cout << "  +-------------+-------------+-------------+-------------+\n";
	cout << "  | 5. Necro    | 6. Paladin  | 7. Sorceress| 8. Warlock   |\n";
	cout << "  +-------------+-------------+-------------+-------------+\n";
	cout << " Input Class Number : ";
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
	cout << "\n Enable Hardcore Mode?\n";
	cout << " (1) Yes / (2) NO : ";
	cin >> hardcoreInput;

	if (hardcoreInput == '1')
	{
		isHardcore = true;
		cout << " [System] Hardcore mode enabled. Death is permanent.\n";
	}
	else if(hardcoreInput =='2')
	{
		isHardcore = false;
		cout << " [System] Standard mode enabled.\n";
	}
	else
	{
		isHardcore = false;
		cout << " [System] Invalid input. Defaulting to Standard.\n";
	}

	cout << "\n [System] Character configuration complete!\n";
	cout << " [System] Press [Enter] to enter the Sanctuary...";
	cin.ignore(1000, '\n'); 
	cin.get();             

	system("cls"); 

	cout << " __      __      .__                                  \n";
	cout << "/  \\    /  \\ ____ |  |   ____  ____   _____   ____    \n";
	cout << "\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\   \n";
	cout << " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   \n";
	cout << "  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  \n";
	cout << "       \\/       \\/          \\/            \\/     \\/   \n";
	cout << "::::::::::::::::::::: TO SANCTUARY :::::::::::::::::::::\n\n";

	cout << " [ User Name ] : " << userName << "\n\n";
	cout << " /================== CHARACTER STATUS ===================\\\n";
	cout << " |                                                       |\n";
	cout << " |  Class    : " << charactorClass << "\t\t Level : " << level << "\t |\n";
	cout << " |  HP       : " << hp << "\t\t MP    : " << mp << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Combat Stats ]           [ Basic Stats ]           |\n";
	cout << " |  Damage   : " << attackDamage << "\t\t Strength : " << strength << "\t |\n";
	cout << " |  Atk Speed: " << attackSpeed << "\t\t Dexterity: " << dexterity << "\t |\n";
	cout << " |  Mov Speed: " << movingSpeed << "\t\t Vitality : " << vitallity << "\t |\n";
	cout << " |                             Energy   : " << energy << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Resistances ]            [ Mode ]                  |\n";
	cout << " |  Fire     : " << fireResist << "\t\t Hardcore : " << (isHardcore ? "YES" : "NO") << "\t |\n";
	cout << " |  Lightning: " << lightingRessist << "\t\t\t\t\t |\n";
	cout << " |  Cold     : " << coldRessist << "\t\t\t\t\t |\n";
	cout << " |  Poison   : " << poisonRessist << "\t\t\t\t\t |\n";
	cout << " \\=======================================================/\n";

	cout << "\n [System] Ready to start the journey? Press [Enter] to continue...";
	cin.get(); // 스테이터스 확인 후 대기

	system("cls"); // 화면 지우기

	// 스테이터스 상단 유지
	cout << " /================== CHARACTER STATUS ===================\\\n";
	cout << " |                                                       |\n";
	cout << " |  Class    : " << charactorClass << "\t\t Level : " << level << "\t |\n";
	cout << " |  HP       : " << hp << "\t\t MP    : " << mp << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Combat Stats ]           [ Basic Stats ]           |\n";
	cout << " |  Damage   : " << attackDamage << "\t\t Strength : " << strength << "\t |\n";
	cout << " |  Atk Speed: " << attackSpeed << "\t\t Dexterity: " << dexterity << "\t |\n";
	cout << " |  Mov Speed: " << movingSpeed << "\t\t Vitality : " << vitallity << "\t |\n";
	cout << " |                             Energy   : " << energy << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Resistances ]            [ Mode ]                  |\n";
	cout << " |  Fire     : " << fireResist << "\t\t Hardcore : " << (isHardcore ? "YES" : "NO") << "\t |\n";
	cout << " |  Lightning: " << lightingRessist << "\t\t\t\t\t |\n";
	cout << " |  Cold     : " << coldRessist << "\t\t\t\t\t |\n";
	cout << " |  Poison   : " << poisonRessist << "\t\t\t\t\t |\n";
	cout << " \\=======================================================/\n";

	//기본 전투 시작 (고블린 등장)
	int gobleinHP = 30;
	int action;
	cout << "\n\n      _---_\n";
	cout << "     /     \\\n";
	cout << "    | () () |\n";
	cout << "     \\  ^  /\n";
	cout << "      |||||\n";
	cout << "      |||||\n";
	cout << " [System] You encountered a GOBLIN!\n";

	// --- 시각적 HP 바 출력 함수 대체 로직 ---
	auto printHPBar = [](string name, int current, int max) {
		int barWidth = 20;
		float ratio = (float)current / max;
		int pos = barWidth * ratio;

		cout << " " << name << " [";
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos) cout << "=";
			else if (i == pos) cout << ">";
			else cout << " ";
		}
		cout << "] " << current << " / " << max << "\n";
	};

	while (gobleinHP > 0 && hp > 0)
	{
		system("cls");
		// 스테이터스 상단 유지
		cout << " /================== CHARACTER STATUS ===================\\\n";
		cout << " |  Class    : " << charactorClass << "\t\t Level : " << level << "\t |\n";
		cout << " |  HP       : " << hp << "\t\t MP    : " << mp << "\t |\n";
		cout << " \\=======================================================/\n\n";

		cout << "      _---_\n";
		cout << "     /     \\\n";
		cout << "    | () () |   <--- [ GOBLIN ]\n";
		cout << "     \\  ^  /\n";
		cout << "      |||||\n\n";

		// 시각적 체력바 출력
		printHPBar("GOBLIN", gobleinHP, 30);
		printHPBar("PLAYER", hp, 100);

		cout << "\n +---------------- COMMANDS ----------------+\n";
		cout << " |  1. Physical Attack                      |\n";
		cout << " |  2. Focus Dodge                          |\n";
		cout << " +------------------------------------------+\n";
		cout << " Select Action : ";
		cin >> action;

		cout << "\n [ Battle Log ]\n";
		cout << " --------------------------------------------\n";
		if (action == 1)
		{
			gobleinHP -= (int)attackDamage;
			cout << " => You swung your weapon! [ -" << (int)attackDamage << " Damage ]\n";

			if (gobleinHP > 0)
			{
				hp -= 30; // FIXED: 체력 감소 버그 수정
				cout << " => The Goblin counterattacks! [ -30 Damage ]\n";
			}
		}
		else if (action == 2)
		{
			cout << " => You focused on dodging! Damage received is halved.\n";
			hp -= 15;
			cout << " => The Goblin counterattacks! [ -15 Damage ]\n";
		}
		else
		{
			cout << " => You panicked! The Goblin seized the opening!\n";
			hp -= 30;
		}
		cout << " --------------------------------------------\n";
		cout << " Press [Enter] for next turn...";
		cin.ignore(1000, '\n');
		cin.get();
	}

	// 전투 종료 및 엔딩 호출
	ShowEnding(hp > 0, isHardcore);

	return 0;
}