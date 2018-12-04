#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

typedef struct _CharacterStateInfo
{
	int health;
	int healthBar;

	int flower;
	int flowerBar;

	int experience;
	int experienceBar;

	int level;

	std::string ascii[9]; // 9 rows, 18 columns
};

typedef struct _InventoryInfo
{
	std::string itemInventory[10][3];
};

class Game
{
public:
	void initializeGame();

	/* Mushroom Way A */
	bool boundaryMariosPad(int, int);
	void drawMariosPad(int, int);
	void displayMariosPad(int&);

	/* Mushroom Way A */
	bool boundaryMushroomWayA(int, int);
	void drawMushroomWayA(int, int);
	void displayMushroomWayA(int&);
	
	/* Mushroom Way B */
	bool boundaryMushroomWayB(int, int);
	void drawMushroomWayB(int, int);
	void displayMushroomWayB(int&);

	/* Mushroom Way C */
	bool boundaryMushroomWayC(int, int);
	void drawMushroomWayC(int, int);
	void displayMushroomWayC(int&);

	/* Mushroom Kingdom */
	bool boundaryMushroomKingdom(int, int);
	void drawMushroomKingdom(int, int);
	void displayMushroomKingdom(int&);

	/* Bandit's Way */
	bool boundaryBanditsWay(int, int);
	void drawBanditsWay(int, int);
	void displayBanditsWay(int&);

	/* Game */
	void displayGame();

	/* Battle */
	void drawBattle();
	void displayBattle();

	/*********************************/
	/* SET CHARACTER STATE INFO */
	/*********************************/

	void setHealth(_CharacterStateInfo& _char, int newHealth)
	{
		_char.health = newHealth;
	}

	void setHealthBar(_CharacterStateInfo& _char, int newHealthBar)
	{
		_char.healthBar = newHealthBar;
	}

	void setFlower(_CharacterStateInfo& _char, int newFlower)
	{
		_char.flower = newFlower;
	}

	void setFlowerBar(_CharacterStateInfo& _char, int newFlowerBar)
	{
		_char.flowerBar = newFlowerBar;
	}

	void setExperience(_CharacterStateInfo& _char, int newExperience)
	{
		_char.experience = newExperience;
	}

	void addExperience(_CharacterStateInfo& _char, int newExperience)
	{
		_char.experience += newExperience;
	}

	void setExperienceBar(_CharacterStateInfo& _char, int newExperienceBar)
	{
		_char.experienceBar = newExperienceBar;
	}

	void setLevel(_CharacterStateInfo& _char, int newLevel)
	{
		_char.level = newLevel;
	}

	void setMarioASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = "     ______       ";
		_char.ascii[1] = "    /      \\_     ";
		_char.ascii[2] = "   /__      |     ";
		_char.ascii[3] = "   \\_____.-\')     ";
		_char.ascii[4] = "    (____)_/      ";
		_char.ascii[5] = "     /||_| |\\     ";
		_char.ascii[6] = "    /|     |_\\    ";
		_char.ascii[7] = "   (_|__|__(__)   ";
		_char.ascii[8] = "     |__|___)     ";
	}

	void setMarioDeadASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = R"(                  )";
		_char.ascii[1] = R"(     _____        )";
		_char.ascii[2] = R"(   .'     '-.     )";
		_char.ascii[3] = R"(   '._______|     )";
		_char.ascii[4] = R"( __\_____/  )___  )";
		_char.ascii[5] = R"((_/.--""--.__(__) )";
		_char.ascii[6] = R"(  .'__    .'      )";
		_char.ascii[7] = R"( /_)(__).'        )";
		_char.ascii[8] = R"((_//\__)          )";
	}

	void setMallowASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = "                  ";
		_char.ascii[1] = "                  ";
		_char.ascii[2] = "      _.-\'\\__     ";
		_char.ascii[3] = "    .\' |/    \'.   ";
		_char.ascii[4] = "   (           )  ";
		_char.ascii[5] = "  (             ) ";
		_char.ascii[6] = " / (__________\\ \\ ";
		_char.ascii[7] = "(__|_________(___)"; 
		_char.ascii[8] = "    |___|_____)   "; 
	}

	void setMallowDeadASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = R"(                  )";
		_char.ascii[1] = R"(                  )";
		_char.ascii[2] = R"(                  )";
		_char.ascii[3] = R"(     _______      )";
		_char.ascii[4] = R"(  .-'_____  '.__  )";
		_char.ascii[5] = R"( /  /   / `. ( _) )";
		_char.ascii[6] = R"(/ __ __     `/.'  )";
		_char.ascii[7] = R"(|/_/|__|    /     )";
		_char.ascii[8] = R"((_//|__)---'      )";
	}


	void setGoombaASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = "       __         ";
		_char.ascii[1] = "     .\'  `.       ";
		_char.ascii[2] = "   .\"\"-.   \'.     ";
		_char.ascii[3] = "  / ( .) .-\"\".    ";
		_char.ascii[4] = " |   _  (. )  \\   ";
		_char.ascii[5] = "  `-. `-._     |  ";
		_char.ascii[6] = "    _|`-._____/   ";
		_char.ascii[7] = "   [__`-._/ \\     ";
		_char.ascii[8] = "        \\___/     ";
	}

	void setKoopaASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = R"(          ___   )";
		_char.ascii[1] = R"( ()().   / _/___)";
		_char.ascii[2] = R"(/     \ /_/_/ _/)";
		_char.ascii[3] = R"(\_.'_ /.'  /_/	)";
		_char.ascii[4] = R"(     \ \      \ )";
		_char.ascii[5] = R"(    /_/ '-.____\)";
		_char.ascii[6] = R"(        /_/ /_/ )";
		_char.ascii[7] = R"(                )";
		_char.ascii[8] = R"(                )";
	}

	void setSpinyASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = "                  ";
		_char.ascii[1] = "                  ";
		_char.ascii[2] = "    |\\_/\\__/|     ";
		_char.ascii[3] = "   .------.  \\    ";  
		_char.ascii[4] = "  /        |  \\   ";
		_char.ascii[5] = " |.------./ _ /   ";
		_char.ascii[6] = "  |!!__.\'/ (_\\    ";
		_char.ascii[7] = "  \\___.\'___(__)   ";
		_char.ascii[8] = "  {__/ {___/      ";
	}

	void setBlankASCII(_CharacterStateInfo& _char)
	{
		_char.ascii[0] = "                  ";
		_char.ascii[1] = "                  ";
		_char.ascii[2] = "                  ";
		_char.ascii[3] = "                  ";
		_char.ascii[4] = "                  ";
		_char.ascii[5] = "                  ";
		_char.ascii[6] = "                  ";
		_char.ascii[7] = "                  ";
		_char.ascii[8] = "                  ";
	}

	/*********************************/
	/* DATA */
	/*********************************/

	/* character state info */
	_CharacterStateInfo Mario;
	_CharacterStateInfo Mallow;
	//_CharacterStateInfo Geno;
	_CharacterStateInfo EnemyA;
	_CharacterStateInfo EnemyB;
	_CharacterStateInfo EnemyC;

	/* Mario's Pad */
	char MariosPad [17][46]= { { ' ', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	' ,' ', ' ' ,' ', '	', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '\'', '\'', '.', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	' ,' ', ' ' ,' ', '	', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '\'', ' ', ' ', ' ', ' ', '\'', '.', ' ', '	', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	' ,' ', ' ' ,' ', '	', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', '.', ' ', ' ', ' ', '	', ' ', ' ', ' ', '	' ,' ', ' ' ,' ', '	', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '\'', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '\'', '.', ' ', '	', ' ', ' ', ' ', '	' ,' ', ' ' ,' ', '	', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'P', 'I', 'P', 'E', ' ', 'H', 'O', 'U', 'S', 'E', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '	' ,' ', ' ' ,' ', '	', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', '_', '_', ' ', ' ', ' ', ' ', ' ', '|', ' ', '_', '_', ' ', ' ', '_', '_' ,' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ' },           
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ' ,'|', '_' ,'_', ' ', ' ', ' ', ' ', ' ', ' ' },       
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', '_', '_', '_', '_', '|', '_', '_', '|', '_', '_', '_', '_', '|', '|', '\\', '/', '|', '|', '=', '=' ,'|', ' ' ,' ', '|', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', '|', ' ', ' ', 'Z', '_', '_', '_', '_', 'Z', ' ', ' ', '|', '|', '|', '/', '\\', '|', '|', '_', '_' ,'|', ' ' ,' ', '|', ' ', ' ', ' ', '	', ' ' },
							   { ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', '|', '|', ' ', ' ', ' ', 'Z', '_', '_', '_', '_', 'Z', ' ', '|', '|', '|', '_', '_', '|', ' ', ' ', ' ' ,' ', ' ' ,' ', '|', ' ', ' ', ' ', ' ', ' ' },                              
							   { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' ,' ', ' ' ,' ', '|', ' ', ' ', ' ', '	', ' ' },
							   { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' ,' ', ' ' ,' ', '|', ' ', ' ', ' ', ' ', ' ' },    
							   { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' ,' ', ' ' ,' ', '|', '_', '_', '_', '_', ' ' },       
							   { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' ,' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ' },    
							   { ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_' ,'_', '_' ,'_', '_', '_', '_', '_', '_', ' ' },      
							   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' ,' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ' }};
	/* Mushroom Way A */
	char MushroomWayA[13][26] = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								  { ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								  { ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								  { ' ', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '|', ' ' },
								  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
								  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' } };
	/* Mushroom Way B */
	char MushroomWayB[18][45] = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '~', '-', '-', '-', '-', '-', '~', '\\', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '{', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '}', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '_', ' ', ' ', ' ', ' ', ' ', '_', '/', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '\\', ' ', '/', '/', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }};
	/* Mushroom Way B */
	char MushroomWayC[15][46] = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '_', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', '\\', ' ', '_', '_', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '/', '_', '_', '_', '_', '_', '_', '_', '\\', '_', '_', '\\', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
							 {' ', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' '},
							 {' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '/', '\\', ' ', ' ', ' ', ' ', ' ', ' ', '(', ' ', ')', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '/', '_', '_', '\\', ' ', ' ', ' ', ' ', '(', '_', 'X', '_', ')', ' ', ' '},
							 {' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', '/', ' ', ' ', ' ', ' ', '\\', '/', '\\', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} }; 
	/* Mushroom Kingdom */
	char MushroomKingdom[27][66] = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', '|', ' ', ' ', ' ', ' ', '.', '-', '.', ' ', ' ', ' ', ' ', '|', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '_', '_', '^', '_', '_', '_', '_', '_', '^', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', '/', '\\', ' ', '/', '_', '^', '_', '\\', ' ', '.', '-', '-', '-', '-', '-', '.', ' ', '/', '_', '^', '_', '\\', ' ', '/', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '/', '_', '_', '\\', '|', ' ', ' ', ' ', '|', '/', ' ', ' ', ' ', 'P', ' ', ' ', ' ', '\\', '|', ' ', ' ', ' ', '|', '/', '_', '_', '\\', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '|', ' ', '|', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', ' ', ' ', '|', '|', '[', ' ', ']', '|', ' ', ' ', '.', '-', '-', '-', '.', ' ', ' ', '|', '[', ' ', ']', '|', '|', ' ', ' ', '|', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', '\\', '|', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', '[', ']', '|', '|', ' ', ' ', ' ', '|', '_', '_', '|', ' ', ' ', ' ', '|', '_', '_', '|', ' ', ' ', ' ', '|', '|', '[', ']', '|', ' ', ' ', '/', '_', '^', '_', '_', '_', '_', '^', '_', '\\', ' ', ' ', ' ', ' ', ' ', '/', '_', '^', '_', '_', '_', '_', '^', '_', '\\', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', ' ', ' ', '|', '|', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '|', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '-', '-', '-', '.', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '-', '-', '-', '-', '-', '.', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '|', '_', '_', '|', ' ', '[', ']', ' ', ' ', '[', ']', ' ', '|', 'I', 'N', 'N', '|', ' ', '|', ' ', '[', ']', ' ', ' ', '[', ']', ' ', '|', 'I', 'T', 'E', 'M', 'S', '|', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '.', '-', '-', '.', ' ', ' ', '|', '-', '-', '-', '\'', ' ', '|', ' ', ' ', '.', '-', '-', '.', ' ', ' ', '|', '-', '-', '-', '-', '-', '\'', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '|', ' ', ' ', '|', '_', '_', '|', '_', '_', '_', '_', '_', '|', '_', '_', '|', ' ', ' ', '|', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', ' '},
								  {' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},    
								  {' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', ' '},
								  {' ', '|', ' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', '/', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '/', '_', '_', '_', '_', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '_', '_', '_', '_', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', '/', '_', '_', '_', '_', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', '[', ']', ' ', ' ', '[', ']', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', '|', '_', '_', '_', '_', '_', '_', '|', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '[', ']', ' ', ' ', '[', ']', '|', ' ', ' ', ' ', ' ', ' ', '|', '[', ']', ' ', ' ', '[', ']', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '_', '_', '|', '_', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} };
		/* Bandit's Way */
	char BanditsWay [11][28] = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
								 {' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ' },
								 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
								 {' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' ' },
								 {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, };
};


#endif