#include <iostream>
#include <String>
#include <ctime>
#include <windows.h>
#include  <vector>
#include "Battle.h"
#include "FireGoblin.h"
#include "Monster.h"
#include "Player.h"


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
	cout << " \\======================"
		 "=================================/\n";

	//기본 전투 시작 (고블린 등장)
	int pandingExp =0;
	vector<Monster*> monsters= 
	{
		new Monster("Goblin",50,0,1,0,50),
		new FireGoblin("Goblin",50,0,1,0,50),
		new Monster("Skeloton",60,0,2,0,70),
		new Monster("Wraith",50,0,3,0,80),
		new Monster("Ghoul",70,0,4,0,120),
		new Monster("Andariel",200,0,8,0,500),
	};
	for (Monster*& monster : monsters)
	{
		if (!player.isAlive()) break; 	
		
	//생성자 호출
			
		cout <<"====================================\n";
		cout << " [System] "+monster->GetName()+"\n";
		cout <<"====================================\n";
		
		// 전투 가능 클래스 구현
		Battle battle(player,*monster);
		battle.Run();

		// --- 시각적 HP 바 출력 함수 대체 로직 ---
		auto printHPBar = [](string name, int current, int max) 
		{
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
		pandingExp = monster->GetExpReward();
		// 레벨업
		player.GainExp(pandingExp);
		player.PrintLevel();
		
		
	}
	
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
		
		// 아이템 루팅
		player.Loot();
		player.PrintLevel();
	}
}