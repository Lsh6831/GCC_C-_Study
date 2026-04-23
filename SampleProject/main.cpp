#include <iostream>
#include <String>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;


// Call By Value : 복사본 전달 -> 원본은 변경 불가;

void PreviewCritical(float attackDamage)
{
	attackDamage *= 2; //parami
	cout << "크리티컬 예상 데미지" << attackDamage << "\n";
}

// Call By Reference: 예시) 참조자 전달 -> 실제 크리티컬 데미지 적용
void ApplyCriticalDamage(int& goblinHp, float attackDamage) {
	int critDamage = attackDamage * 2;	// 치명타는 2배 데미지 적용
	goblinHp -= critDamage;	// 원본 goblinHp를 직접 감소


	// Call By Address: 주소 전달 -> 원본 직접 수정 가능
	//void LevelUp(int* level) {
	//	(*level)++;	// 역참조로 level 원본 직접 증가
	}

// Call By Reference: 참조자 전달 -> * 없이 직접 수정
void LevelUpRef(int& level) {
	level++;
}

// const 참조자 : 복사 비용 절약 + 원본 수정 차단
void PrintLevel(const int& level) {
	cout << "현재 레벨: " << level << "\n";
	//level++; // 컴파일 오류발생, const라 원본의 수정이 불가능함
}

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

		


		/*	int lootRoll = rand() % 4;
			string itemName;

			if (lootRoll == 0) itemName = "Gold Pouch";
			else if (lootRoll == 1) itemName = "Healing Potion";
			else if (lootRoll == 2) itemName = "Steel Sword";
			else itemName = "Leather Armor";

			cout << "  * Slot [" << i << "]: " << itemName << " found!\n";*/
		

		// 포인터 순화로 인벤토리 출력 (5칸)
		cout << " --------------------------------------------\n";
		cout << " --------------------------------------------\n";
		cout << " --------------------------------------------\n";
		

		/*cout << " --------------------------------------------\n";
		cout << " [System] Adventure complete. Press [Enter] to exit.";
		cin.get();*/
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

	//인벤토리 (0=빈칸 , 1= Gold , 2= Healing Potion, 3=Wrapon, 4=Armor)
	int gameInventory[5] = { 0,1,2,3,4 };

	////Call By Value : 복사본 전달 -> 원본의 불변 확인
	//cout << "원본 attackDamage" << attackDamage << "\n";
	//PreviewCritical(attackDamage);
	//cout << "호출 attackDamage" << attackDamage << "\n";


	////Call By Address : 주소 전달 -> 원본의 불변 확인
	//cout << "After LevelUp Level : " << level << "\n";
	//LevelUp(&level);
	//cout << "Befor LevelUp Level : " << level << "\n";



	////Call By Reference : 별칭 (alias)선언 -> 원본과 같은 메모리
	//int levelRef = level;
	//levelRef++;
	//
	//cout << "levelRef++ After : " << level << "\n";
	//cout << "levelRef++ Befor : " << levelRef << "\n";

		// Call By Reference: & 없이 호출, * 없이 수정
	//cout << "levelUpRef() 호출 전 원본 level: " << level << "\n";
	//LevelUpRef(level); // & 없이 그냥 변수명
	//cout << "levelUpRef() 호출 후 원본 level: " << level << "\n";


	// const 참조자: 읽기 전용, 수정 불가
	//PrintLevel(level);

#pragma region 260421 연산자
		//// "&" 주소 연산자

		//cout << "hp변수의 값 : " << hp << "\n";
		//cout << "hp변수의 주소값 : " << &hp << "\n"; //변수의 주소값 출력 & 앰퍼샌드 연산자 사용
		////system("pause"); 이거 왜 시스템 오류 나지

		////"*" 역참조 연산자

		//int* ptr = &hp;
		//cout << "ptr ==&hp :" << ptr<<"\n";
		//cout << "ptr 값 : " << *ptr << "\n"; // 포인터를 역참조 하여 hp 값 읽기
		//
		//*ptr = 200; // 포인터를 역참조하여 hp 값 쓰기및 수정
		//cout << "hp변수의 새로운 값 : " << hp << "\n";

		////int* tprt2 = nullptr;  //nulptr 안전 초기화 
		////cout << "tprt2 값 : " << *tprt2 << "\n";

		//cout << "sizeof(int) : " << sizeof(int) << "byte\n";
		//cout << "sizeof(int*) : " << sizeof(int*) << "byte\n"; //포인터 변수는 주소를 담기 때문에 모두 8바이트로 되어있음
		//cout << "sizeof(double) : " << sizeof(double) << "byte\n";
		//cout << "sizeof(double-) : " << sizeof(double*) << "byte\n";
		//cout << "sizeof(char*) : " << sizeof(char*) << "byte\n";

		//

		//// 포인터 연산 (+1 = 자료형 메모리 크기만큼 이동)

		//cout << "ptr 1 : " << ptr << "\n";
		//cout << "ptr 2 : " << ptr +1 << "\n";
		//cout << "ptr 3 : " << ptr +2 << "\n";

		//// 배열의 
		//int scores[5] = { 85,92,78,95,88 };
		//cout << "&scores[0] : " << &scores[0] << "\n";
		//cout << "&scores[0] : " << &scores[1] << "\n";
		//cout << "&scores[0] : " << &scores[2] << "\n";
		//cout << "&scores[0] : " << &scores[3] << "\n";
		//cout << "&scores[0] : " << &scores[4] << "\n";

		//// 배열 이름이 시작 주소로 형변환 (Pointer Decay)
		//cout << "scores : " << scores << "\n"; //배열 이름
		//cout << "&scores[0] : " << &scores[0] << "\n";// 첫 원소 주소
		//cout << "scores[2] : " << &scores[2] << "\n";// 인덱스로 접근
		//cout << "*(scores+2) : " << *(scores + 2) << "\n";// 포인터 연산

		//cout << "scores[2] : " << scores[2] << "\n";// 이거랑 같은건감

		//// 현변환의 예외상황 1. sizeof()사용

		//cout << "sizeof(scores) : " << sizeof(scores) << "\n";
		//cout << "sizeof(scores 원소 개수 ) : " << sizeof(scores)/sizeof(scores[0]) << "\n";
		//

		//// 형변환의 예외상항 2 &(주소)연사자 사용
		//cout << "scores : " << scores << "\n"; // 시작 주소
		//cout << "scores+1 : " << scores+1 << "\n"; // +4원소 단위로 int 만큼
		//cout << "&scores : " << &scores << "\n"; // 시작 주소
		//cout << "&scores+11 : " << &scores + 1 << "\n"; // +20 배열 전체 단위로 이동

		//// for 반복문을 통한 배열 순환
		//int* sPtr = scores;
		//for (int i = 0;i < 5; i++)
		//{
		//	cout << "주소 : " << sPtr << " 값 : "<<*sPtr << "\n"; // 시작 주소
		//	sPtr++;//+1 다음 원소로 이동
		//}

		//// Wild Poiter 위험
		////int* wildPtr; // 초기화 안 함 => 쓰레기 주소값이 들어갈 것임
		////*wildPtr = 100; // CRASH 발생 , 잘못된 메모리에 접근하고 있음
		//// 위 상태는 안됨

		//int* wildPtr = nullptr; // 안전한 초기화를 위한 예약어 nullptr 사용
		//if (wildPtr != nullptr) // wildPtrddml null 체크 조건문
		//{
		//	*wildPtr = 100;//실행 안됨
		//}
		//cout << "wildPtr : " << wildPtr << "\n"; // wildPtr

		////허상 포인터 예시
		//int* danglePtr = new int(100); // 동적 할당
		//cout << "삭제(delete) 전 : " << *danglePtr << "\n"; 
		//delete danglePtr; // 메모리 해제 , 삭제
		////*danglePtr = 200; // 해체된 메모리에 할당하려 하고 있음. Runtime CRASH 발생
		//danglePtr = nullptr; //안전 처리
		//cout << "danglePtr : " << danglePtr << "\n";
#pragma endregion 설명_안적어도_됨


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
		cout << " |  2. Critical Attack                       |\n";
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
			PreviewCritical(attackDamage);
			ApplyCriticalDamage(gobleinHP, attackDamage);
			cout << "\n>> [YOU] Critical Hit! " << (int)attackDamage * 2 << " damage!\n";

			if (gobleinHP > 0) {
				cout << ">> [GOBLIN] counter-attacked! You lost 30 HP.\n";
				hp -= 30;
			}
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

	// 레벨업
	LevelUpRef(level);
	PrintLevel(level);

	// 전투 종료 및 엔딩 호출
	bool isVictory = (hp > 0);
	system("cls"); // 엔딩 페이지를 위해 화면 정리

	if (!isVictory) {
		cout << "  __      ______  _    _   _____ _____ ______ _____  \n";
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
		cout << "  __       _______ _____ _______  ____  _______     __ \n";
		cout << "  \\ \\    / /_   _/ ____|__   __|/ __ \\|  __ \\ \\   / / \n";
		cout << "   \\ \\  / /   | || |       | |  | |  | | |__) \\ \\_/ /  \n";
		cout << "    \\ \\/ /    | || |       | |  | |  | |  _  / \\   /   \n";
		cout << "     \\  /    _| || |____   | |  | |__| | | \\ \\  | |    \n";
		cout << "      \\/    |_____\\_____|  |_|   \\____/|_|  \\_\\ |_|    \n";
		cout << "\n [System] You defeated the Goblin!\n";
		cout << " [System] Press [Enter] to claim your rewards...";
		cin.get();

		// 여기서 전역 변수 gameInventory 등을 사용할 수 있습니다.
		cout << "\n [ LOOT WINDOW ]\n";
		cout << " --------------------------------------------\n";
		srand((unsigned int)time(NULL));

		int* invPtr = gameInventory; //invPtr -> gameInventory 시작주소 [0]

		for (int i = 1; i <= 3; i++) {
			*invPtr = rand() % 4 + 1;
			invPtr++;
		}

		invPtr = gameInventory;// 처음으로 리셋
		int slot = 0;

		/*for (int i = 1; i <= 3; i++) {
			int lootRoll = rand() % 4;
			string itemName;

			if (lootRoll == 0) itemName = "Gold Pouch";
			else if (lootRoll == 1) itemName = "Healing Potion";
			else if (lootRoll == 2) itemName = "Steel Sword";
			else itemName = "Leather Armor";

			cout << "  * Slot [" << i << "]: " << itemName << " found!\n";
		}*/
		while (invPtr < gameInventory + 5) {
			string itemName;
			if (*invPtr == 1) itemName = "Gold";
			else if (*invPtr == 2) itemName = "Healing Potion";
			else if (*invPtr == 3) itemName = "Weapon";
			else if (*invPtr == 4) itemName = "Armor";
			else itemName = "None";
			//cout << " > Slot "<< slot << setw(46) << "[" << itemName<<"]\n";
			cout << " > Slot " << slot << "[" << itemName << "]\n";
			invPtr++;
			slot++;
		}
		cout << " --------------------------------------------\n";
		cout << " [System] Adventure complete. Press [Enter] to exit.";
		cin.get();
	}
}