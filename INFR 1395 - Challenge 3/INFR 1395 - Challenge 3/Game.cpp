#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

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

/* Battle */
void Game::displayBattle()
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

	/*for (int ctrA = 0; ctrA < x; ctrA++)
		for (int ctrB = 0; ctrB < x; ctrB++)
			if (b[ctrA][ctrB] = 1)
			{
				b[ctrA][ctrB] = 0;
				b[ctrA][ctrB + 1] = 1;
			}*/
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

	// clear system
	system("cls");
	// draw area
	drawMushroomWayA(coord_x, coord_y);

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

	// clear system
	system("cls");
	// draw area
	drawMushroomWayB(coord_x, coord_y);

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
		coord_x = 44;
		coord_y = 1;
	}
	else {
		coord_x = 8;
		coord_y = 1;
	}

	// clear system
	system("cls");
	// draw area
	drawMushroomWayC(coord_x, coord_y);

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
		}
	}

	std::cout << "GAME THEORY: MARIO IS DEAD " << std::endl;
	system("pause");
}

