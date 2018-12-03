#include"Menu.h"
#include<iostream>
#include<windows.h>
#include<stdlib.h>     /* exit, EXIT_FAILURE */

void displayMenu()
{
	// display title screen
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;   
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "                                                                                          ____ _   _ ____ ___ ___    ________   _______    _______" << std::endl;
	std::cout << "                                                                                         / ___| | | |  _ \\ __| _ \\  |        \\ |       \\  |       \\" << std::endl;
	std::cout << "                                                                                         \\__ \\| |_| |  __/ _||   /  |    _    ||    _   \\ |   __   \\" << std::endl;
	std::cout << "                                                                                         |___/ \\___/|_|  \\___|_|_\\  |   | \\   ||   | /   ||  /  \\__/_" << std::endl;
	std::cout << "                                                                                          __  _   __   ___  _  __   |   |/   / |   |/   / |  \\   /   |" << std::endl;
	std::cout << "                                                                                         |  \\/ \\ /_ \\ | _ \\| |/  \\  |   |\\   \\ |    ___/  |   \\_/   _|" << std::endl;
	std::cout << "                                                                                         | |\\/\\ \\ _  \\|   /| | () | |   | \\   \\|   |       \\        |" << std::endl;
	std::cout << "                                                                                         |_|   \\_\\ \\__|_|_\\|_|\\__/  |___|  \\__/|___|        \\___/|__|" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "                                                                                                          Legend of the Seven Stars" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "                                                                                                             .------.   .------." << std::endl;
	std::cout << "                                                                                                         _  _|_  _  |   |  _  _|_  _" << std::endl;
	std::cout << "                                                                                                        | ||   || ||     || ||   || |" << std::endl;
	std::cout << "                                                                                                        |         ||_____||         |                                    ___________________" << std::endl;
	std::cout << "                                                        _____.------._______      ___                   \\         /       \\         /    ____          __     ____.----\"\"" << std::endl;
	std::cout << "                                                       /                    \\    |   `---__.------.______\\  _   _/         \\_   _  /-.__/    \\________/  |_  / " << std::endl;
	std::cout << "                                                                             \\  /                         || |_| |_________| |_| ||                        \/" << std::endl;
	std::cout << "                                                                              |/                          |\\     /         \\     /|" << std::endl;
	std::cout << "                                                                                                       |\\ | |   |    ___    |   | | /|" << std::endl;
	std::cout << "                                                                                                       \\ `-.|   |   |   |   |   |.-\' /" << std::endl;
	std::cout << "                                                                                                        \\   `---. .-------. .---\'   /" << std::endl;
	std::cout << "                                                                                                    ___  `-.__   \"         \"   __.-\'      __" << std::endl;
	std::cout << "                                                                                                   |   \\ __/ `-\"--.__   __.--\"-\' \\__   ,-' /" << std::endl;
	std::cout << "                                                                                                   /    |     `------\' \'------\'     |-\'   /" << std::endl;
	std::cout << "                                                                                                ,-\'    /                            \\    /\\" << std::endl;
	std::cout << "                                                                                             ,-\'       \\       .___.--\"--.___.      /      `-." << std::endl;
	std::cout << "                                                                                            /           `-.     |/         \\|    .-\'          `-." << std::endl;
	std::cout << "                                                                                           /               \"-.    \\_______/   .-\"                \\" << std::endl;
	std::cout << "                                                                                          |                   \"--------------\"                    \\" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;

	// display option
	std::cout << "                                                                                                       [------SELECT AN OPTION------]" << std::endl;
	std::cout << "                                                                                                            .------------------." << std::endl;;
	std::cout << "                                                                                                            | [1] START        |" << std::endl;
	std::cout << "                                                                                                            |------------------|" << std::endl;;
	std::cout << "                                                                                                            | [2] EXIT         |" << std::endl;
	std::cout << "                                                                                                            \'------------------\'" << std::endl;;
	std::cout << "                                                                                                                (\\_/)|| " << std::endl;
	std::cout << "                                                                                                                ('^')||" << std::endl;
	std::cout << "                                                                                                                /   \\7 " << std::endl;

	// declare input to store input
	int input;
	// declare "accept" to control the loop
	bool accept = false;
	// loop while "accept" is false
	while (accept == false)
	{
		// if "1" is pressed, continue
		if (GetKeyState('1') & 0x8000)
		{
			input = 1;
			accept = true;
		}
		// if "2" is pressed, continue
		if (GetKeyState('2') & 0x8000)
		{
			input = 2;
			exit(EXIT_FAILURE);
			accept = true;
		}
	}
}
