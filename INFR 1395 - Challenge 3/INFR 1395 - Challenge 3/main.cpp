#include"Menu.h"
#include"Game.h"
#include<Windows.h>

void maximizeWindow()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void removeScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	// maximize window
	maximizeWindow();

	// remove scrollbar
	removeScrollbar();

	// remove console cursor
	ShowConsoleCursor(false);

	// display menu
	displayMenu();
	// clear system
	system("cls");
	// display game
	Game MarioIsDead;
	MarioIsDead.initializeGame();
	MarioIsDead.displayGame();

	// return 0
	return 0;
}