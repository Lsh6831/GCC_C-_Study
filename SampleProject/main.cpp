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


// Monset 클래스
class Monster
{
	private:
	
	int hp,maxhp;
	int attackDamage;
	
	public:
		Monster(int inithp,int atk) : hp(inithp), maxhp(inithp),attackDamage(atk)
		{
			cout << "[몬스터 등장!] HP : " << hp << "/ ATK :"<<attackDamage<< "\n";
		}
	~Monster()
		{
			cout << "[몬스터 소멸!] \n"; // 소멸자 확인용 로그
		}
	int GetHp() const{return hp;}
	int GetMaxHp() const{return maxhp;}
	bool isAlive() const{return hp>0;}
	void TakeDamage(int damage)
		{
			hp -= damage;
			if (hp<0) hp = 0;
		}
	int Attack() const{return attackDamage;} // 몬스터가 플레이어를 공격
};

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
	int action;
	Monster goblin(50,10);
	
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

	while (goblin.isAlive() > 0 && hp > 0)
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
		printHPBar("GOBLIN", goblin.GetMaxHp(), 30);
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
			goblin.TakeDamage((int)attackDamage); // 객체 스스로가 데미지를 처리하고 있음
			cout << " => You swung your weapon! [ -" << (int)attackDamage << " Damage ]\n";

			if (goblin.isAlive())
			{
				hp -= goblin.Attack(); 
				cout << " => The Goblin counterattacks! [ -30 Damage ]\n";
			}
		}
		else if (action == 2)
		{
			PreviewCritical(attackDamage);
			goblin.TakeDamage((int)attackDamage * 2);
			cout << "\n>> [YOU] Critical Hit! " << (int)attackDamage * 2 << " damage!\n";

			if (goblin.isAlive()) {
				cout << ">> [GOBLIN] counter-attacked! You lost 30 HP.\n";
				hp -= goblin.Attack();
			}
		}
		else
		{
			cout << " => You panicked! The Goblin seized the opening!\n";
			hp -= goblin.Attack();
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