/*Sean Birket
100704214
Combat*/

#include<iostream>
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


void Battle()
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
	int numEni = 3;//change this to change the number of enemys in play 

	do 
	{
		switch (numEni)
		{
		case 1:
			cout << "you are fighting a Goomba with: " << enemyHealth[0] << " Health." << endl;
			enemyHealth[1] = 0;
			enemyHealth[2] = 0;
			break;
		case 2:
			cout << "you are fighting a Goomba with: " << enemyHealth[0] << " Health." << endl;
			cout << "you are fighting a Sky Troopa with: " << enemyHealth[1] << "Health." << endl;
			enemyHealth[2] = 0;
			break;
		case 3:
			cout << "you are fighting a Goomba with: " << enemyHealth[0] << " Health." << endl;
			cout << "you are fighting a Sky Troopa with: " << enemyHealth[1] << "Health." << endl;
			cout << "you are fighting a Spikey with: " << enemyHealth[2] << "Health." << endl;
			break;
		}
		//mario is alive he gets his turn
		if (playerHealth[0] > 0)
		{
			cout << " " << endl;
			cout << "Mario has " << playerHealth[0] << " points of health" << endl;
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
				cout << "Which enemy do you want to attack: 1(enemy 1), 2(enemy 2), 3(enemy 3)" << endl;
				cin >> attackWho;
				//checks that enemy is consider alive so the player doesn't attack a dead enemy
				if (attackWho == 1 && enemyHealth[0] > 0)
				{
					//this is the special attack just does more damage 
					cout << "You use a special attack on the Goomba it deals ten damage!" << endl;
					enemyHealth[0] = enemyHealth[0] - 10;
					cout << "They have: " << enemyHealth[0] << " Points of health now." << endl;
				}

				if (attackWho == 2 && enemyHealth[1] > 0)
				{
					cout << "You use a special attack on the Sky Troopa it deals ten damage!" << endl;
					enemyHealth[1] = enemyHealth[1] - 10;
					cout << "They have: " << enemyHealth[1] << " Points of health now." << endl;
				}

				if (attackWho == 3 && enemyHealth[2] > 0)
				{
					cout << "You use a special attack on the Spiky it deals ten damage!" << endl;
					enemyHealth[2] = enemyHealth[2] - 10;
					cout << "They have: " << enemyHealth[2] << " Points of health now." << endl;
				}
				break;
			case 3:
				//items
				//still waiting on the inventry system
				break;
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
			cout << " " << endl;
			cout << "Mario is dead" << endl;
			cout << " " << endl;
		}

			if (playerHealth[1] > 0)
			{
				cout << " " << endl;
				cout << "Mallow has " << playerHealth[1] << " points of health" << endl;
				cout << "What will Mallow do?"<<endl;
				
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
					cout << "Which enemy do you want to attack: 1(enemy 1), 2(enemy 2), 3(enemy 3)" << endl;
					cin >> attackWho;
					//checks that enemy is consider alive so the player doesn't attack a dead enemy
					if (attackWho == 1 && enemyHealth[0] > 0)
					{
						//this is the special attack just does more damage 
						cout << "You use a special attack on the Goomba it deals ten damage!" << endl;
						enemyHealth[0] = enemyHealth[0] - 10;
						cout << "They have: " << enemyHealth[0] << " Points of health now." << endl;
					}

					if (attackWho == 2 && enemyHealth[1] > 0)
					{
						cout << "You use a special attack on the Sky Troopa it deals ten damage!" << endl;
						enemyHealth[1] = enemyHealth[1] - 10;
						cout << "They have: " << enemyHealth[1] << " Points of health now." << endl;
					}

					if (attackWho == 3 && enemyHealth[2] > 0)
					{
						cout << "You use a special attack on the Spiky it deals ten damage!" << endl;
						enemyHealth[2] = enemyHealth[2] - 10;
						cout << "They have: " << enemyHealth[2] << " Points of health now." << endl;
					}
					break;
				case 3:
					//items
					//still waiting on the inventry system
					break;
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

	}while(playerHealth[0] > 0 || playerHealth[1] > 0);


	system("pause");
}
