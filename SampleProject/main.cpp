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
		Player(const string name, const string& characterClass,bool isHardcore)// 외부 입력을 통한 값 초기화
			: name(name), characterClass(characterClass), isHardcore(isHardcore),
	strength(50), dexterity(50), vitality(50), energy(50),
	level(1),
	fireResist(0), coldResist(0), lightResist(0), poisonResist(0)
		{
			maxhp = vitality *2 ;//계산이 필요한 값 세팅
			hp = maxhp;
			maxmp = (int)energy *1.5f ;
			mp = maxmp;
			attackDamage = strength*0.2f;
			attackSpeed = dexterity / 10.0f;
			movingSpeed = movingSpeed / 30.f;
			
			for (int i = 0; i < 5; i++) inventory[i] = 0;
		}
	
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
	void TakeDamage(int damage)
		{
			hp -= damage;
			if (hp<=0) hp = 0;
		}
	int Attack() const{return (int)attackDamage;}
	int CriticalAttack() const{return (int)(attackDamage*2);}
	void LevelUp() {level++;}
	
	void PreviewCritical() const
		{
			float preview = attackDamage*2;
			cout << "크리티컬 예상 데미지 : "<<preview<<"\n";
			
		}
	void PrintLevel() const
		{
			cout <<"현재레밸"<<level<<"\n";
		}
	
};


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

	string userName;
	//char charactorClass[50];
	string charactorClass;
	int classChoiceInput;
	bool isHardcore = true;
	char hardcoreInput = true;
	

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
	// Player 객체 생성 - 입력받은 값들로 초기화, 스탯은 내부에서 자동 계산됨
	Player player(userName, charactorClass, hardcoreInput);
	
	
	
	cout << " [ User Name ] : " << player.GetName() << "\n\n";
	cout << " /================== CHARACTER STATUS ===================\\\n";
	cout << " |                                                       |\n";
	cout << " |  Class    : " << player.GetCharacterClass() << "\t\t Level : " << player.getLevel() << "\t |\n";
	cout << " |  HP       : " << player.getMaxHP() << "\t\t MP    : " << player.getMaxMP() << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Combat Stats ]           [ Basic Stats ]           |\n";
	cout << " |  Damage   : " << player.getattackDamage() << "\t\t Strength : " << player.getStrength() << "\t |\n";
	cout << " |  Atk Speed: " << player.getattackspeed() << "\t\t Dexterity: " << player.getDexterity() << "\t |\n";
	cout << " |  Mov Speed: " << player.getMovingspeed() << "\t\t Vitality : " << player.getVitality() << "\t |\n";
	cout << " |                             Energy   : " << player.getEnergy() << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Resistances ]            [ Mode ]                  |\n";
	cout << " |  Fire     : " << player.getfireResist() << "\t\t Hardcore : " << (isHardcore ? "YES" : "NO") << "\t |\n";
	cout << " |  Lightning: " << player.getLightResist() << "\t\t\t\t\t |\n";
	cout << " |  Cold     : " << player.getColdResist() << "\t\t\t\t\t |\n";
	cout << " |  Poison   : " << player.getPoisonResist() << "\t\t\t\t\t |\n";
	cout << " \\=======================================================/\n";

	cout << "\n [System] Ready to start the journey? Press [Enter] to continue...";
	cin.get(); // 스테이터스 확인 후 대기

	system("cls"); // 화면 지우기

	// 스테이터스 상단 유지
	cout << " /================== CHARACTER STATUS ===================\\\n";
	cout << " |                                                       |\n";
	cout << " |  Class    : " << player.GetCharacterClass() << "\t\t Level : " << player.getLevel() << "\t |\n";
	cout << " |  HP       : " << player.getMaxHP() << "\t\t MP    : " << player.getMaxMP() << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Combat Stats ]           [ Basic Stats ]           |\n";
	cout << " |  Damage   : " << player.getattackDamage() << "\t\t Strength : " << player.getStrength() << "\t |\n";
	cout << " |  Atk Speed: " << player.getattackspeed() << "\t\t Dexterity: " << player.getDexterity() << "\t |\n";
	cout << " |  Mov Speed: " << player.getMovingspeed() << "\t\t Vitality : " << player.getVitality() << "\t |\n";
	cout << " |                             Energy   : " << player.getEnergy() << "\t |\n";
	cout << " |                                                       |\n";
	cout << " |  [ Resistances ]            [ Mode ]                  |\n";
	cout << " |  Fire     : " << player.getfireResist() << "\t\t Hardcore : " << (isHardcore ? "YES" : "NO") << "\t |\n";
	cout << " |  Lightning: " << player.getLightResist() << "\t\t\t\t\t |\n";
	cout << " |  Cold     : " << player.getColdResist() << "\t\t\t\t\t |\n";
	cout << " |  Poison   : " << player.getPoisonResist() << "\t\t\t\t\t |\n";
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

	while (goblin.isAlive() > 0 && player.isAlive() > 0)
	{
		system("cls");
		// 스테이터스 상단 유지
		cout << " /================== CHARACTER STATUS ===================\\\n";
		cout << " |  Class    : " << charactorClass << "\t\t Level : " << player.getLevel() << "\t |\n";
		cout << " |  HP       : " << player.getHP() << "\t\t MP    : " << player.getMP() << "\t |\n";
		cout << " \\=======================================================/\n\n";

		cout << "      _---_\n";
		cout << "     /     \\\n";
		cout << "    | () () |   <--- [ GOBLIN ]\n";
		cout << "     \\  ^  /\n";
		cout << "      |||||\n\n";

		// 시각적 체력바 출력
		printHPBar("GOBLIN", goblin.GetMaxHp(), 30);
		printHPBar("PLAYER", player.getHP(), 100);

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
			goblin.TakeDamage(player.Attack()); // 객체 스스로가 데미지를 처리하고 있음
			cout << " => You swung your weapon! [ -" << player.Attack() << " Damage ]\n";

			if (goblin.isAlive())
			{
				player.TakeDamage(goblin.Attack());
				cout << " => The Goblin counterattacks! [ -30 Damage ]\n";
			}
		}
		else if (action == 2)
		{
			goblin.TakeDamage(player.CriticalAttack());
			cout << "\n>> [YOU] Critical Hit! " << player.CriticalAttack() << " damage!\n";

			if (goblin.isAlive()) {
				cout << ">> [GOBLIN] counter-attacked! You lost 30 HP.\n";
				player.TakeDamage(goblin.Attack());
			}
		}
		else
		{
			cout << " => You panicked! The Goblin seized the opening!\n";
				player.TakeDamage(goblin.Attack());
			
		}
		cout << " --------------------------------------------\n";
		cout << " Press [Enter] for next turn...";
		cin.ignore(1000, '\n');
		cin.get();
	}

	// 레벨업
	player.LevelUp();
	player.PrintLevel();

	// 전투 종료 및 엔딩 호출
	bool isVictory = player.isAlive();
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