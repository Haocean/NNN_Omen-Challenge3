#include"Game.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>

/////////////////////////
/* Battle */
#include<ctime>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;

int random(int low, int high)
{
	if (low > high) return high;
	return low + (std::rand() % (high - low + 1));
}
/////////////////////////


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void ClearConsoleInputBuffer()
{
	PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
	DWORD ClearingVar2;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ClearingVar1, 256, &ClearingVar2);
	delete[] ClearingVar1;
}

void Game::initializeGame()
{
	// TESTING
	setMarioASCII(Mario);
	setMallowASCII(Mallow);
	setGoombaASCII(EnemyA);
	setSpinyASCII(EnemyB);
	setGoombaASCII(EnemyC);
}



/* Mario's Pad */
bool Game::boundaryMariosPad(int x, int y)
{
	// declare "boundary"
	bool boundary = false;

	// checks if the coordinate are inside the boundary
	if (MariosPad[y][x] != ' ') {
		boundary = true;
	}

	// return "boundary"
	return boundary;
}

void Game::drawMariosPad(int x, int y)
{
	// display area
	for (int counterA = 0; counterA < 17; counterA++) {
		for (int counterB = 0; counterB < 46; counterB++) {
			if (counterA == y && counterB == x) {
				std::cout << 'M';
			}
			else {
				std::cout << MariosPad[counterA][counterB];
			}
		}
		std::cout << std::endl;
	}
}

void Game::displayMariosPad(int &areaState)
{
	// declare "coord_x" and "coord_y" to set the party's coordinates
	int coord_x;
	int coord_y;

	if (areaState == 0) {
		coord_x = 22;
		coord_y = 13;
	}
	else if (areaState == 1) {
		coord_x = 44;
		coord_y = 14;
	}
	else {
		coord_x = 22;
		coord_y = 13;
	}

	// clear system
	system("cls");
	// draw area
	drawMariosPad(coord_x, coord_y);

	bool endArea = false;
	while (endArea == false) {
		int input = 0;

		switch (input = getch()) {
		case KEY_UP:
			// update
			if (boundaryMariosPad(coord_x, coord_y - 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_DOWN:
			// update
			if (boundaryMariosPad(coord_x, coord_y + 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_LEFT:
			// update
			if (boundaryMariosPad(coord_x - 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_RIGHT:
			// update
			if (boundaryMariosPad(coord_x + 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		}
		if (coord_x == 45 && coord_y == 14) {
			areaState = 2;
			break;
		}
	}
}

/* Mushroom Way A */
bool Game::boundaryMushroomWayA(int x, int y)
{
	// declare "boundary"
	bool boundary = false;

	// checks if the coordinate are inside the boundary
	if (MushroomWayA[y][x] != ' ') {
		boundary = true;
	}

	// return "boundary"
	return boundary;
}

void Game::drawMushroomWayA(int x, int y)
{
	// display area
	for (int counterA = 0; counterA < 13; counterA++) {
		for (int counterB = 0; counterB < 26; counterB++) {
			if (counterA == y && counterB == x) {
				std::cout << 'M';
			}
			else {
				std::cout << MushroomWayA[counterA][counterB];
			}
		}
		std::cout << std::endl;
	}
}

void Game::displayMushroomWayA(int &areaState)
{
	// declare "coord_x" and "coord_y" to set the party's coordinates
	int coord_x;
	int coord_y;

	if (areaState == 2) {
		coord_x = 1;
		coord_y = 10;
	}
	else if (areaState == 3) {
		coord_x = 3;
		coord_y = 1;
	}
	else {
		coord_x = 1;
		coord_y = 10;
	}

	//
	int enemy_coord[2][3] = { { 12, 9, 1 },{ 10, 4, 2 } };
	bool enemy_state[2] = { true, true };

	// clear system
	system("cls");
	// draw area
	drawMushroomWayA(coord_x, coord_y);

	//
	for (int counter = 0; counter < 2; counter++) {
		setCursorPosition(enemy_coord[counter][0], enemy_coord[counter][1]);
		std::cout << 'E';
	}

	bool endArea = false;
	while (endArea == false) {
		int input = 0;

		switch (input = getch()) {
		case KEY_UP:
			// update
			if (boundaryMushroomWayA(coord_x, coord_y - 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_DOWN:
			// update
			if (boundaryMushroomWayA(coord_x, coord_y + 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_LEFT:
			// update
			if (boundaryMushroomWayA(coord_x - 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_RIGHT:
			// update
			if (boundaryMushroomWayA(coord_x + 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		}
		if (coord_x > 1 && coord_x < 5 && coord_y == 0) {
			areaState = 4;
			break;
		}
		for (int counter = 0; counter < 2; counter++) {
			if (coord_x == enemy_coord[counter][0] && coord_y == enemy_coord[counter][1] && enemy_state[counter] == true) {
				//
				system("cls");
				//
				displayBattle();
				//
				system("cls");
				//
				enemy_state[counter] = false;
				// draw area
				drawMushroomWayA(coord_x, coord_y);
				//
				for (int counterA = 0; counterA < 2; counterA++) {
					if (enemy_state[counterA] == true) {
						setCursorPosition(enemy_coord[counterA][0], enemy_coord[counterA][1]);
						std::cout << 'E';
					}
				}
			}
		}
	}
}

/* Mushroom Way B */
bool Game::boundaryMushroomWayB(int x, int y)
{
	// declare "boundary"
	bool boundary = false;

	// checks if the coordinate are inside the boundary
	if (MushroomWayB[y][x] != ' ') {
		boundary = true;
	}

	// return "boundary"
	return boundary;
}

void Game::drawMushroomWayB(int x, int y)
{
	// display area
	for (int counterA = 0; counterA < 18; counterA++) {
		for (int counterB = 0; counterB < 45; counterB++) {
			if (counterA == y && counterB == x) {
				std::cout << 'M';
			}
			else {
				std::cout << MushroomWayB[counterA][counterB];
			}
		}
		std::cout << std::endl;
	}
}

void Game::displayMushroomWayB(int & areaState)
{
	// declare "coord_x" and "coord_y" to set the party's coordinates
	int coord_x;
	int coord_y;

	if (areaState == 4) {
		coord_x = 3;
		coord_y = 16;
	}
	else if (areaState == 5) {
		coord_x = 43;
		coord_y = 2;
	}
	else {
		coord_x = 3;
		coord_y = 16;
	}

	//
	int enemy_coord[3][2] = { { 20, 8},{ 15, 6}};
	bool enemy_state[2] = { true, true };

	// clear system
	system("cls");
	// draw area
	drawMushroomWayB(coord_x, coord_y);
	
	//
	for (int counter = 0; counter < 3; counter++) {
		setCursorPosition(enemy_coord[counter][0], enemy_coord[counter][1]);
		std::cout << 'E';
	}


	bool endArea = false;
	while (endArea == false) {
		int input = 0;

		switch (input = getch()) {
		case KEY_UP:
			// update
			if (boundaryMushroomWayB(coord_x, coord_y - 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_DOWN:
			// update
			if (boundaryMushroomWayB(coord_x, coord_y + 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_LEFT:
			// update
			if (boundaryMushroomWayB(coord_x - 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_RIGHT:
			// update
			if (boundaryMushroomWayB(coord_x + 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		}
		if (coord_x > 1 && coord_x < 5 && coord_y == 17) {
			areaState = 3;
			break;
		}
		else if (coord_x == 44 && coord_y == 2) {
			areaState = 6;
			break;
		}
		for (int counter = 0; counter < 2; counter++) {
			if (coord_x == enemy_coord[counter][0] && coord_y == enemy_coord[counter][1] && enemy_state[counter] == true) {
				//
				system("cls");
				//
				displayBattle();
				//
				system("cls");
				//
				enemy_state[counter] = false;
				// draw area
				drawMushroomWayB(coord_x, coord_y);
				//
				for (int counterA = 0; counterA < 2; counterA++) {
					if (enemy_state[counterA] == true) {
						setCursorPosition(enemy_coord[counterA][0], enemy_coord[counterA][1]);
						std::cout << 'E';
					}
				}
			}
		}
	}
}

/* Mushroom Way C */
bool Game::boundaryMushroomWayC(int x, int y)
{
	// declare "boundary"
	bool boundary = false;
	
	// checks if the coordinate are inside the boundary
	if (MushroomWayC[y][x] != ' ') {
		boundary = true;
	}

	// return "boundary"
	return boundary;
}

void Game::drawMushroomWayC(int x, int y)
{
	// display area
	for (int counterA = 0; counterA < 15; counterA++) {
		for (int counterB = 0; counterB < 46; counterB++) {
			if (counterA == y && counterB == x) {
				std::cout << 'M';
			}
			else {
				std::cout << MushroomWayC[counterA][counterB];
			}
		}
		std::cout << std::endl;
	}
}

void Game::displayMushroomWayC(int &areaState)
{
	// declare "coord_x" and "coord_y" to set the party's coordinates
	int coord_x;
	int coord_y;

	if (areaState == 6) {
		coord_x = 1;
		coord_y = 9;
	}
	else if (areaState == 7) {
		coord_x = 42;
		coord_y = 1;
	}
	else {
		coord_x = 8;
		coord_y = 1;
	}

	//
	int enemy_coord[3][2] = { { 10, 9 },{ 42, 2 }};
	bool enemy_state[2] = { true, true };

	// clear system
	system("cls");
	// draw area
	drawMushroomWayC(coord_x, coord_y);

	//
	for (int counter = 0; counter < 2; counter++) {
		setCursorPosition(enemy_coord[counter][0], enemy_coord[counter][1]);
		std::cout << 'E';
	}

	bool endArea = false;
	while (endArea == false) {
		int input = 0;

		switch (input = getch()) {
		case KEY_UP:
			// update
			if (boundaryMushroomWayC(coord_x, coord_y - 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_DOWN:
			// update
			if (boundaryMushroomWayC(coord_x, coord_y + 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_LEFT:
			// update
			if (boundaryMushroomWayC(coord_x - 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_RIGHT:
			// update
			if (boundaryMushroomWayC(coord_x + 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		}
		if (coord_x == 0 && coord_y == 9) {
			areaState = 5;
			break;
		}
		else if (coord_x > 40 && coord_x < 44 && coord_y == 0) {
			areaState = 8;
			break;
		}
		for (int counter = 0; counter < 2; counter++) {
			if (coord_x == enemy_coord[counter][0] && coord_y == enemy_coord[counter][1] && enemy_state[counter] == true) {
				//
				system("cls");
				//
				displayBattle();
				//
				system("cls");
				//
				enemy_state[counter] = false;
				// draw area
				drawMushroomWayC(coord_x, coord_y);
				//
				for (int counterA = 0; counterA < 2; counterA++) {
					if (enemy_state[counterA] == true) {
						setCursorPosition(enemy_coord[counterA][0], enemy_coord[counterA][1]);
						std::cout << 'E';
					}
				}
			}
		}
	}
}

/* Mushroom Kingdom */
bool Game::boundaryMushroomKingdom(int x, int y)
{
	// declare "boundary"
	bool boundary = false;

	// checks if the coordinate are inside the boundary
	if (MushroomKingdom[y][x] != ' ') {
		boundary = true;
	}

	// return "boundary"
	return boundary;
}

void Game::drawMushroomKingdom(int x, int y)
{
	// display area
	for (int counterA = 0; counterA < 27; counterA++) {
		for (int counterB = 0; counterB < 66; counterB++) {
			if (counterA == y && counterB == x) {
				std::cout << 'M';
			}
			else {
				std::cout << MushroomKingdom[counterA][counterB];
			}
		}
		std::cout << std::endl;
	}
}

void Game::displayMushroomKingdom(int &areaState)
{
	// declare "coord_x" and "coord_y" to set the party's coordinates
	int coord_x;
	int coord_y;

	if (areaState == 8) {
		coord_x = 12;
		coord_y = 25;
	}
	else if (areaState == 9) {
		coord_x = 64;
		coord_y = 14;
	}
	else {
		coord_x = 12;
		coord_y = 25;
	}

	// clear system
	system("cls");
	// draw area
	drawMushroomKingdom(coord_x, coord_y);

	bool endArea = false;
	while (endArea == false) {
		int input = 0;

		switch (input = getch()) {
		case KEY_UP:
			// update
			if (boundaryMushroomKingdom(coord_x, coord_y - 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_DOWN:
			// update
			if (boundaryMushroomKingdom(coord_x, coord_y + 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_LEFT:
			// update
			if (boundaryMushroomKingdom(coord_x - 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_RIGHT:
			// update
			if (boundaryMushroomKingdom(coord_x + 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		}
		if (coord_x > 10 && coord_x < 15 && coord_y == 26) {
			areaState = 7;
			break;
		}
		else if (coord_x == 65 && coord_y == 14) {
			areaState = 10;
			break;
		}
	}
}

/* Bandits Way */
bool Game::boundaryBanditsWay(int x, int y)
{
	// declare "boundary"
	bool boundary = false;

	// checks if the coordinate are inside the boundary
	if (BanditsWay[y][x] != ' ') {
		boundary = true;
	}

	// return "boundary"
	return boundary;
}

void Game::drawBanditsWay(int x, int y)
{
	// display area
	for (int counterA = 0; counterA < 11; counterA++) {
		for (int counterB = 0; counterB < 28; counterB++) {
			if (counterA == y && counterB == x) {
				std::cout << 'M';
			}
			else {
				std::cout << BanditsWay[counterA][counterB];
			}
		}
		std::cout << std::endl;
	}
}

void Game::displayBanditsWay(int &areaState)
{
	// declare "coord_x" and "coord_y" to set the party's coordinates
	int coord_x;
	int coord_y;

	if (areaState == 10) {
		coord_x = 1;
		coord_y = 5;
	}
	else {
		coord_x = 1;
		coord_y = 5;
	}

	// clear system
	system("cls");
	// draw area
	drawBanditsWay(coord_x, coord_y);

	bool endArea = false;
	while (endArea == false) {
		int input = 0;

		switch (input = getch()) {
		case KEY_UP:
			// update
			if (boundaryBanditsWay(coord_x, coord_y - 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_DOWN:
			// update
			if (boundaryBanditsWay(coord_x, coord_y + 1) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_y += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_LEFT:
			// update
			if (boundaryBanditsWay(coord_x - 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x -= 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		case KEY_RIGHT:
			// update
			if (boundaryBanditsWay(coord_x + 1, coord_y) == false) {
				setCursorPosition(coord_x, coord_y);
				std::cout << ' ';
				coord_x += 1;
				setCursorPosition(coord_x, coord_y);
				std::cout << 'M';
			}

			// break switch statement
			break;
		}
		if (coord_x == 0 && coord_y == 5) {
			areaState = 9;
			break;
		}
	}
}

/* Game */
void Game::displayGame()
{
	// clear keystate
	ClearConsoleInputBuffer();

	// declare "areaState"
	int areaState = 0;

	// declare "endGame" to control the game
	bool endGame = false;
	// loop while "endGame" is false
	while (endGame == false)
	{
		//drawBattle();
		switch (areaState) {
		case 0:
		case 1:
			displayMariosPad(areaState);
			break;
		case 2:
		case 3:
			displayMushroomWayA(areaState);
			break;
		case 4:
		case 5:
			displayMushroomWayB(areaState);
			break;
		case 6:
		case 7:
			displayMushroomWayC(areaState);
			break;
		case 8:
		case 9:
			displayMushroomKingdom(areaState);
			break;
		case 10:
			displayBanditsWay(areaState);
			break;
		}
	}

	std::cout << "GAME THEORY: MARIO IS DEAD " << std::endl;
	system("pause");
}

/* Battle */
void Game::drawBattle()
{
	// skip line
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// display enemies
	for (int counter = 0; counter < 9; counter++)
	{
		for (int counter = 0; counter < 36; counter++)
			std::cout << " ";
		std::cout << EnemyA.ascii[counter];
		if (counter < 4)
			std::cout << std::endl;
		else
			std::cout << EnemyB.ascii[counter - 4] << std::endl;
	}

	for (int counter = 5; counter < 9; counter++)
	{
		for (int counter = 0; counter < 54; counter++)
			std::cout << " ";

		std::cout << EnemyB.ascii[counter];

		std::cout << EnemyC.ascii[counter - 5] << std::endl;
	}

	for (int counter = 4; counter < 9; counter++)
	{
		for (int counter = 0; counter < 72; counter++)
			std::cout << " ";

		std::cout << EnemyC.ascii[counter] << std::endl;
	}

	// display party
	for (int counter = 0; counter < 9; counter++)
	{
		std::cout << Mario.ascii[counter];
		if (counter < 5)
			std::cout << std::endl;
		else
			std::cout << Mallow.ascii[counter - 4] << std::endl;
	}

	for (int counter = 5; counter < 9; counter++)
	{
		for (int counter = 0; counter < 18; counter++)
			std::cout << " ";

		std::cout << Mallow.ascii[counter] << std::endl;
	}
}
void Game::displayBattle()
{
		float playerHealth[3];//partys health
		playerHealth[0] = 20;//Mario's health 
		playerHealth[1] = 20;//Mallow's health
		float enemyHealth[5];//enemies health
		enemyHealth[0] = 16;//Goomba's health
		enemyHealth[1] = 10;//Koopa's health
		enemyHealth[2] = 20;//Spiky's health 
		int playerAct;
		int attackWho;
		//int numEni = 2;//change this to change the number of enemys in play 
		string itemInventory[9];
		//inventoryplace holder
		itemInventory[1] = "small health potion";

		///
		int numEni = random(1, 3);
		if (numEni == 1) {
			setMarioASCII(Mario);
			setMallowASCII(Mallow);
			setGoombaASCII(EnemyA);
			setBlankASCII(EnemyB);
			setBlankASCII(EnemyC);
		}
		else if (numEni == 2) {
			setMarioASCII(Mario);
			setMallowASCII(Mallow);
			setGoombaASCII(EnemyA);
			setKoopaASCII(EnemyB);
			setBlankASCII(EnemyC);
		}
		else if (numEni == 3) {
			setMarioASCII(Mario);
			setMallowASCII(Mallow);
			setGoombaASCII(EnemyA);
			setKoopaASCII(EnemyB);
			setSpinyASCII(EnemyC);
		}
		///


		int invSize = 1;//this should be 9 its 1 right now for testing 
		int whatItem;
		int marioMana;
		marioMana = 10;
		int mallowMana;
		mallowMana = 15;

		do
		{
			//
			drawBattle();
			//
			switch (numEni)
			{
			case 1:
				cout << "you are fighting a Goomba with: " << enemyHealth[0] << " Health." << endl;
				enemyHealth[1] = 0;
				enemyHealth[2] = 0;
				break;
			case 2:
				cout << "you are fighting a Goomba with: " << enemyHealth[0] << " Health." << endl;
				cout << "you are fighting a Sky Troopa with: " << enemyHealth[1] << " Health." << endl;
				enemyHealth[2] = 0;
				break;
			case 3:
				cout << "you are fighting a Goomba with: " << enemyHealth[0] << " Health." << endl;
				cout << "you are fighting a Sky Troopa with: " << enemyHealth[1] << " Health." << endl;
				cout << "you are fighting a Spikey with: " << enemyHealth[2] << " Health." << endl;
				break;
			}
			//mario is alive he gets his turn
			if (playerHealth[0] > 0)
			{
				//outputs characters stats
				cout << " " << endl;
				cout << "Mario has " << playerHealth[0] << " points of health" << endl;
				cout << "Mario has " << marioMana << " mana." << endl;
				cout << "What will Mario do?";
				//players picks what mario does
				cout << "\nAttack:1\nSpecial:2\nItem:3\nFlee:4\n" << endl;
				cin >> playerAct;

				switch (playerAct)
				{
				case 1:
					//player picks which enemy they attack
					cout << "Which enemy do you want to attack: 1(enemy 1), 2(enemy 2), 3(enemy 3)" << endl;
					cin >> attackWho;
					//checks that enemy is consider alive so the player doesn't attack a dead enemy
					if (attackWho == 1 && enemyHealth[0] > 0)
					{
						//this is the normal attack
						//player attacks the enemy dealing damage
						cout << "You use a normal attack on the Goomba it deals five damage!" << endl;
						enemyHealth[0] = enemyHealth[0] - 5;
						cout << "They have: " << enemyHealth[0] << " Points of health now." << endl;
					}

					if (attackWho == 2 && enemyHealth[1] > 0)
					{
						cout << "You use a normal attack on the Sky Troopa it deals five damage!" << endl;
						enemyHealth[1] = enemyHealth[1] - 5;
						cout << "They have: " << enemyHealth[1] << " Points of health now." << endl;
					}

					if (attackWho == 3 && enemyHealth[2] > 0)
					{
						cout << "You use a normal attack on the Spiky it deals five damage!" << endl;
						enemyHealth[2] = enemyHealth[2] - 5;
						cout << "They have: " << enemyHealth[2] << " Points of health now." << endl;
					}
					break;
				case 2:
					//Mana must be above 0 to do special attack
					if (marioMana > 0)
					{
						cout << "Which enemy do you want to attack: 1(enemy 1), 2(enemy 2), 3(enemy 3)" << endl;
						cin >> attackWho;
						//checks that enemy is consider alive so the player doesn't attack a dead enemy
						if (attackWho == 1 && enemyHealth[0] > 0)
						{
							//this is the special attack just does more damage 
							cout << "You use a special attack on the Goomba it deals ten damage!" << endl;
							enemyHealth[0] = enemyHealth[0] - 10;
							cout << "They have: " << enemyHealth[0] << " Points of health now." << endl;
							marioMana = marioMana - 5;
							//they lose mana after attack
						}

						if (attackWho == 2 && enemyHealth[1] > 0)
						{
							cout << "You use a special attack on the Sky Troopa it deals ten damage!" << endl;
							enemyHealth[1] = enemyHealth[1] - 10;
							cout << "They have: " << enemyHealth[1] << " Points of health now." << endl;
							marioMana = marioMana - 5;
						}

						if (attackWho == 3 && enemyHealth[2] > 0)
						{
							cout << "You use a special attack on the Spiky it deals ten damage!" << endl;
							enemyHealth[2] = enemyHealth[2] - 10;
							cout << "They have: " << enemyHealth[2] << " Points of health now." << endl;
							marioMana = marioMana - 5;
						}
					}
					//player is out of mana can't use special
					if (marioMana <= 0)
					{
						cout << " " << endl;
						cout << "you have no more Mana" << endl;
						cout << " " << endl;
					}
					break;
				}
				//Items 
				if (playerAct == 3)
				{
					//outputs the item array.
					for (int i = 0; i == invSize; i++)
					{
						cout << " " << endl;
						cout << itemInventory[i] << endl;
						cout << " " << endl;
					}

					cout << "What Item do you want to use?" << endl;
					cout << "1:Small Health Potion\n 2:Large Health Potion\n 3:Revive Potion\n 4: Small Flower Potion\n 5:Large Flower Potion" << endl;
					cin >> whatItem;

					switch (whatItem)
					{
					case 1:
						cout << " " << endl;
						cout << "Mario use's a small health potion. He gains +5 health." << endl;
						cout << " " << endl;
						playerHealth[0] = playerHealth[0] + 5;
						break;
					case 2:
						cout << " " << endl;
						cout << "Mario use's a large health potion. He gains +10 health." << endl;
						cout << " " << endl;
						playerHealth[0] = playerHealth[0] + 10;
						break;
					case 3:
						cout << " " << endl;
						cout << "Mario use's a revive potion.Mallow's health is restored." << endl;
						cout << " " << endl;
						playerHealth[1] = 20;
						break;
					case 4:
						cout << " " << endl;
						cout << "Mario use's a small mana potion. He gains +5 mana." << endl;
						cout << " " << endl;
						marioMana = marioMana + 5;
						break;
					case 5:
						cout << " " << endl;
						cout << "Mario use's a large mana potion. He gains +10 mana." << endl;
						cout << " " << endl;
						marioMana = marioMana + 10;
						break;
					}

				}

				//getting out of battle by wining or runing 
				if (playerAct == 4)
				{
					//tells the game the player is runing 
					cout << "You flee with you life, but not your dignity." << endl;
					break;
				}

				//all enemys need to be dead to win
				if (enemyHealth[0] <= 0 && enemyHealth[1] <= 0 && enemyHealth[2] <= 0)
				{
					//tells the game the player has betten all enemys
					cout << "You Win the Fight" << endl;
					break;
				}

			}

			if (playerHealth[0] <= 0)
			{	
				setMarioDeadASCII(Mario);
				system("cls");
				drawBattle();
				cout << " " << endl;
				cout << "Mario is dead" << endl;
				cout << " " << endl;
			}
			system("cls");
			drawBattle();
			if (playerHealth[1] > 0)
			{
				//outputs chacters stats 
				cout << " " << endl;
				cout << "Mallow has " << playerHealth[1] << " points of health" << endl;
				cout << "Mallow has " << mallowMana << " mana" << endl;
				cout << "What will Mallow do?" << endl;

				//players picks what Mallow does
				cout << "\nAttack:1\nSpecial:2\nItem:3\nFlee:4\n" << endl;
				cin >> playerAct;

				switch (playerAct)
				{
				case 1:
					//player picks which enemy they attack
					cout << "Which enemy do you want to attack: 1(enemy 1), 2(enemy 2), 3(enemy 3)" << endl;
					cin >> attackWho;
					//checks that enemy is consider alive so the player doesn't attack a dead enemy
					if (attackWho == 1 && enemyHealth[0] > 0)
					{
						//this is the normal attack
						//player attacks the enemy dealing damage
						cout << "You use a normal attack on the Goomba it deals five damage!" << endl;
						enemyHealth[0] = enemyHealth[0] - 5;
						cout << "They have: " << enemyHealth[0] << " Points of health now." << endl;
					}

					if (attackWho == 2 && enemyHealth[1] > 0)
					{
						cout << "You use a normal attack on the Sky Troopa it deals five damage!" << endl;
						enemyHealth[1] = enemyHealth[1] - 5;
						cout << "They have: " << enemyHealth[1] << " Points of health now." << endl;
					}

					if (attackWho == 3 && enemyHealth[2] > 0)
					{
						cout << "You use a normal attack on the Spicky it deals five damage!" << endl;
						enemyHealth[2] = enemyHealth[2] - 5;
						cout << "They have: " << enemyHealth[2] << " Points of health now." << endl;
					}
					break;
				case 2:
					if (mallowMana > 0)
					{
						//special attack
						cout << "Which enemy do you want to attack: 1(enemy 1), 2(enemy 2), 3(enemy 3)" << endl;
						cin >> attackWho;
						//checks that enemy is consider alive so the player doesn't attack a dead enemy
						if (attackWho == 1 && enemyHealth[0] > 0)
						{
							//this is the special attack just does more damage 
							cout << "You use a special attack on the Goomba it deals ten damage!" << endl;
							enemyHealth[0] = enemyHealth[0] - 10;
							cout << "They have: " << enemyHealth[0] << " Points of health now." << endl;
							mallowMana = mallowMana - 5;
						}

						if (attackWho == 2 && enemyHealth[1] > 0)
						{
							cout << "You use a special attack on the Sky Troopa it deals ten damage!" << endl;
							enemyHealth[1] = enemyHealth[1] - 10;
							cout << "They have: " << enemyHealth[1] << " Points of health now." << endl;
							mallowMana = mallowMana - 5;
						}

						if (attackWho == 3 && enemyHealth[2] > 0)
						{
							cout << "You use a special attack on the Spiky it deals ten damage!" << endl;
							enemyHealth[2] = enemyHealth[2] - 10;
							cout << "They have: " << enemyHealth[2] << " Points of health now." << endl;
							mallowMana = mallowMana - 5;
						}
					}
					//player is out of mana can't use special
					if (mallowMana <= 0)
					{
						cout << " " << endl;
						cout << "you have no more Mana" << endl;
						cout << " " << endl;
					}
					break;
				}

				//Items 
				if (playerAct == 3)
				{
					for (int i = 0; i == invSize; i++)
					{
						cout << " " << endl;
						cout << itemInventory[i] << endl;
						cout << " " << endl;
					}

					cout << "What Item do you want to use?" << endl;
					cout << "1:Small Health Potion\n 2:Large Health Potion\n 3:Revive Potion\n 4: Small Flower Potion\n 5:Large Flower Potion" << endl;
					cin >> whatItem;

					switch (whatItem)
					{
					case 1:
						cout << " " << endl;
						cout << "Mallow use's a small health potion. He gains +5 health." << endl;
						cout << " " << endl;
						playerHealth[1] = playerHealth[1] + 5;
						break;
					case 2:
						cout << " " << endl;
						cout << "Mallow use's a large health potion. He gains +10 health." << endl;
						cout << " " << endl;
						playerHealth[1] = playerHealth[1] + 10;
						break;
					case 3:
						cout << " " << endl;
						cout << "Mallow use's a revive potion.Mario's health is restored." << endl;
						cout << " " << endl;
						playerHealth[0] = 20;
						break;
					case 4:
						cout << " " << endl;
						cout << "Mallow use's a small mana potion. He gains +5 mana." << endl;
						cout << " " << endl;
						mallowMana = mallowMana + 5;
						break;
					case 5:
						cout << " " << endl;
						cout << "Mallow use's a large mana potion. He gains +10 mana." << endl;
						cout << " " << endl;
						mallowMana = mallowMana + 10;
						break;
					}

				}
				//getting out of battle by wining or runing 
				if (playerAct == 4)
				{
					//tells the game the player is runing 
					cout << "You flee with you life, but not your dignity." << endl;
					break;
				}

				//all enemys need to be dead to win
				if (enemyHealth[0] <= 0 && enemyHealth[1] <= 0 && enemyHealth[2] <= 0)
				{
					//tells the game the player has betten all enemys
					cout << "You Win the Fight" << endl;
					break;
				}
			}

			if (playerHealth[1] <= 0)
			{
				setMallowDeadASCII(Mario);
				system("cls");
				drawBattle();
				cout << " " << endl;
				cout << "Mallow is dead" << endl;
				cout << " " << endl;
			}

			srand(time(0));

			//this loop does this enemys turns 
			for (int j = 0; j != numEni; j++)
			{
				//rolls a random number 
				int act = random(1, 2);
				//basied of that random number enemy picks who they attack.
				switch (act)
				{
				case 1:
					//eneime attakes mario
					if (enemyHealth[j] > 0)
					{
						cout << " " << endl;
						cout << "Mario takes damage." << endl;
						cout << " " << endl;
						playerHealth[0] = playerHealth[0] - 5;
						cout << "Mario Health is: " << playerHealth[0] << endl;

						if (playerHealth[0] <= 0)
						{
							cout << " " << endl;
							cout << "Mallow takes damage." << endl;
							cout << " " << endl;
							playerHealth[1] = playerHealth[1] - 5;
							cout << "Mallow Health is: " << playerHealth[1] << endl;
						}
					}
					break;
				case 2:
					//eneime attakes mallow
					if (enemyHealth[j] > 0)
					{
						cout << " " << endl;
						cout << "Mallow takes damage." << endl;
						cout << " " << endl;
						playerHealth[1] = playerHealth[1] - 5;
						cout << "Mallow Health is: " << playerHealth[1] << endl;

						if (playerHealth[1] <= 0)
						{
							cout << " " << endl;
							cout << "Mario takes damage." << endl;
							cout << " " << endl;
							playerHealth[0] = playerHealth[0] - 5;
							cout << "Mario Health is: " << playerHealth[0] << endl;
						}
					}
					break;
				}
			}
			system("cls");
		} while (playerHealth[0] > 0 || playerHealth[1] > 0);

		if (playerHealth[0] <= 0 || playerHealth[1] <= 0)
		{
			system("cls");
			std::cout << " GAME OVER " << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}

}