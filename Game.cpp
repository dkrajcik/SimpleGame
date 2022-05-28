#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Shortcuts

void clear() {
	system("CLS");
}

void pause() {
	system("pause");
}

//enemy class

class Enemy
{
public:
	string GetEnemyName();
	int GetHealth();
	int GetDefense();
	int GetAttack();
protected:
	string name;
	int Defense;
	int Health;
	int Attack;
};

string Enemy::GetEnemyName() {
	return name;
}

int Enemy::GetDefense() {
	return Defense;
}

int Enemy::GetHealth() {
	return Health;
}

int Enemy::GetAttack() {
	return Attack;
}


//Goblin


class Goblin : public Enemy {
	public:
		Goblin();
	private:

};

Goblin::Goblin() {
	name = "Goblin";
	Defense = 5;
	Health = 14;
	Attack = 6;
}



//Skeleton


class Skeleton : public Enemy {
public:
	Skeleton();
private:

};

Skeleton::Skeleton() {
	name = "Skeleton";
	Defense = 6;
	Health = 15;
	Attack = 8;
}

//Ninja

class Ninja : public Enemy {
public:
	Ninja();
private:

};

Ninja::Ninja() {
	name = "Ninja";
	Defense = 8;
	Health = 12;
	Attack = 11;
}

//Dark Wizard

class DarkWizard : public Enemy {
public:
	DarkWizard();
private:

};

DarkWizard::DarkWizard() {
	name = "Dark Wizard";
	Defense = 10;
	Health = 16;
	Attack = 13;
}


class Covid : public Enemy {
public:
	Covid();
private:

};

Covid::Covid() {
	name = "Coe-Vidd XIX";
	Defense = 10;
	Health = 25;
	Attack = 15;
}

void printIntro() {
	cout << endl << endl << endl << "Greetings traveler! Welcome to 'PoCS 2'! A wonderfully real place that is in terrible trouble!" << endl << endl << endl;
	pause();
	clear();
	cout << endl << endl << endl << "The terrible Quore Entine Forest is spreading its dark magic across our small realm!" << endl << endl << endl;
	pause();
	clear();
	cout << endl << endl << endl << "We believe the treacherous Coe-Vidd XIX is behind the forest's spread!" << endl << endl << endl;
	pause();
	clear();
	cout << endl << endl << endl << "BLAH BLAH BLAH *you tune out because you're bored*" << endl << endl << endl;
	pause();
	clear();
	cout << endl << endl << endl << "Please, dear traveler, won't you help save the realm? (y/n): ";
}

void printMap() {
	cout << "x---0" << endl << endl;
}

void printKey() {
	cout << "'-' is a path, '0' is the final space before the game ends, and 'x' is you.";
}

//print stats

void printPlayerStats(int playerHealth, int playerDefense, int playerAttack) {
	cout << "Here are your current stats:" << endl;
	cout << "Player Health: " << playerHealth << endl;
	cout << "Player Attack: " << playerAttack << endl;
	cout << "Player Defense: " << playerDefense << endl;
}

//player actions

int playerAttacking(int playerAttack, int enemyHealth, int enemyDefense, int damageDealt) { //PLAYER ATTACK
	if (playerAttack > enemyDefense) {
		damageDealt = playerAttack - enemyDefense;

		cout << endl << "Enemy hit! You did " << damageDealt << " points of damage!" << endl << endl << endl;
		enemyHealth = enemyHealth - damageDealt;

		if (enemyHealth < 0) {
			enemyHealth = 0;
		}

		cout << "Your enemy has " << enemyHealth << " health remaining!" << endl << endl << endl;
	}
	else {
		cout << "Your attack is too low to damage this enemy! FLEE!" << endl << endl << endl;
	}

	return enemyHealth;
}

//Enemy Attack Turn

int enemyAttacking(int enemyAttack, int playerHealth, int playerDefense, int damageDealt) { //PLAYER ATTACK
	cout << "The enemy chooses to attack this turn!" << endl << endl << endl;
	
	if (enemyAttack > playerDefense) {
		damageDealt = enemyAttack - playerDefense;

		cout << "You've been hit! Enemy did " << damageDealt << " points of damage!" << endl << endl << endl;
		playerHealth = playerHealth - damageDealt;

		cout << "You have " << playerHealth << " health remaining!" << endl << endl << endl;
	}
	else {
		cout << "The enemy's attack is too low to damage you! You will surely win this fight!" << endl << endl << endl;
	}

	return playerHealth;
}


//ACTUAL BATTLE

//--------------------------------------------------------------------------------------------------------------------------------------------//


int battleMode(int playerAttack, int playerHealth, int playerDefense, int enemyAttack, int enemyHealth, int enemyDefense, int damageDealt, string enemyName) {
	
	int turn = 0;
	string playerIn;
	int ResultOfBattle = 0;

	cout << "Welcome to Battle Dome!" << endl << endl;
	cout << "Enemy Name: " << enemyName << endl << endl;
	cout << "Here are your current enemy's stats:" << endl;
	cout << "Enemy Health: " << enemyHealth << endl;
	cout << "Enemy Attack: " << enemyAttack << endl;
	cout << "Enemy Defense: " << enemyDefense << endl;

	cout << endl << endl << endl;

	void printPlayerStats(int playerHealth, int playerDefense, int playerAttack);

	cout << endl << endl;

	while (enemyHealth > 0) {
		
		cout << "Press 'a' to attack enemy, press 'r' to run from battle, press 'h' to heal, press 's' for stats!" << endl << endl << "Input: ";
		cin >> playerIn;

		cout << endl << endl;

		while (turn == 0) {
			if (playerIn == "s") {
				cout << "Enemy Name: " << enemyName << endl << endl;
				cout << "Here are your current enemy's stats:" << endl;
				cout << "Enemy Health: " << enemyHealth << endl;
				cout << "Enemy Attack: " << enemyAttack << endl;
				cout << "Enemy Defense: " << enemyDefense << endl;

				printPlayerStats(playerHealth, playerDefense, playerAttack);

				cout << endl << endl << "What is your next move?: ";
				cin >> playerIn;
			}
			else if (playerIn == "a") {
				enemyHealth = playerAttacking(playerAttack, enemyHealth, enemyDefense, damageDealt);

				//cout << enemyHealth << endl << endl << endl;

				turn = 1;
			}
			else if (playerIn == "h") {
				playerHealth = playerHealth + 5;
				if (playerHealth > 20) {
					playerHealth = 20;
				}
				turn = 1;
			}
			else if (playerIn == "r") {
				ResultOfBattle = 3;
				break;
			}
			else {
				cout << "Invalid Input!!" << endl << endl;
				cout << endl << endl << "What is your next move?: ";
				cin >> playerIn;
			}

		}

		if (ResultOfBattle == 3) {
			break;
		}

		if (enemyHealth <= 0) {
			break;
		}

		//ENEMY ATTACK TURN

		playerHealth = enemyAttacking(enemyAttack, playerHealth, playerDefense, damageDealt);

		//Reset Turn

		turn = 0;

		//Test if player is dead

		if (playerHealth > 0) {
			continue;
		}
		else {
			ResultOfBattle = 2;
			break;
		}

	}

	//Determine Battle Results

	if (ResultOfBattle == 3) {
		cout << "You have successfully escaped!" << endl << endl << endl;
		ResultOfBattle = 3;
	}
	else if (ResultOfBattle == 2) {
		cout << "You have DIED!" << endl << endl << endl;
	}
	else {
		cout << "Congratulations! The " << enemyName << " has been defeated!" << endl << endl << endl;
		ResultOfBattle = 1;
	}
	return playerHealth;
}



//--------------------------------------------------------------------------------------------------------------------------------------------//

//MAP POSITION

string MapPosition(int TURN) {
	string Map = "----0";
	int position = TURN - 1;

	Map.at(position) = 'x';

	return Map;
}




int main() {
	bool game = true; //game is running

	string Map;
	int TURN = 1;

	int playerHealth = 20;
	int playerDefense = 6;
	int playerAttack = 10;

	string userInput;


	//game intro

	printIntro();

	cin >> userInput;
	system("CLS");

	if (userInput != "y") {
		cout << endl << endl << endl << "Too bad, you're helping.";
	}

	cout << endl << endl << endl << "Please, take this map for your journey! Good luck traveler!" << endl << endl << endl;
	printMap();
	cout << endl << endl;
	printKey();
	cout << endl << endl << endl;
	system("pause"); 
	system("CLS");

	printPlayerStats(playerHealth, playerDefense, playerAttack);
	cout << endl << endl << endl;



	while (game) {
		while (TURN < 6) {
			cout << "Enter 'm' to view your position on the map, 'b' to battle an enemy, 's' to skip to the next space (skip battle), or 'c' to clear cluttered screen!" << endl << endl << endl;
			
			cout << "What do you choose to do?: ";

			cin >> userInput;

			cout << endl << endl << endl;

			if (playerHealth <= 0) {
				break;
			}
			else if (userInput == "m") {
				Map = MapPosition(TURN);
				cout << Map << endl << endl << endl;
				TURN = TURN - 1;
			}
			else if (userInput == "b") {
				if (TURN == 1) {
					Skeleton skelly;

					string enemyName = skelly.GetEnemyName();
					int enemyDefense = skelly.GetDefense();
					int enemyAttack = skelly.GetAttack();
					int enemyHealth = skelly.GetHealth();
					int damageDealt = 0;

					playerHealth = battleMode(playerAttack, playerHealth, playerDefense, enemyAttack, enemyHealth, enemyDefense, damageDealt, enemyName);
					playerAttack++;
					playerDefense++;
				}
				else if (TURN == 2) {
					Goblin gelly;

					string enemyName = gelly.GetEnemyName();
					int enemyDefense = gelly.GetDefense();
					int enemyAttack = gelly.GetAttack();
					int enemyHealth = gelly.GetHealth();
					int damageDealt = 0;

					playerHealth = battleMode(playerAttack, playerHealth, playerDefense, enemyAttack, enemyHealth, enemyDefense, damageDealt, enemyName);
					playerAttack++;
					playerDefense++;
				}
				else if (TURN == 3) {
					Ninja nelly;

					string enemyName = nelly.GetEnemyName();
					int enemyDefense = nelly.GetDefense();
					int enemyAttack = nelly.GetAttack();
					int enemyHealth = nelly.GetHealth();
					int damageDealt = 0;

					playerHealth = battleMode(playerAttack, playerHealth, playerDefense, enemyAttack, enemyHealth, enemyDefense, damageDealt, enemyName);
					playerAttack++;
					playerDefense++;
				}
				else if (TURN == 4) {
					DarkWizard dwelly;

					string enemyName = dwelly.GetEnemyName();
					int enemyDefense = dwelly.GetDefense();
					int enemyAttack = dwelly.GetAttack();
					int enemyHealth = dwelly.GetHealth();
					int damageDealt = 0;

					playerHealth = battleMode(playerAttack, playerHealth, playerDefense, enemyAttack, enemyHealth, enemyDefense, damageDealt, enemyName);
					playerAttack = playerAttack + 2;
					playerDefense = playerDefense + 2;
				}
				else if (TURN == 5) {
					Covid celly;

					string enemyName = celly.GetEnemyName();
					int enemyDefense = celly.GetDefense();
					int enemyAttack = celly.GetAttack();
					int enemyHealth = celly.GetHealth();
					int damageDealt = 0;

					playerHealth = battleMode(playerAttack, playerHealth, playerDefense, enemyAttack, enemyHealth, enemyDefense, damageDealt, enemyName);
				}


				cout << endl << endl << "You have " << playerHealth << " health remaining after this battle!" << endl << endl;
			}
			else if (userInput == "c") {
				system("CLS");
				TURN = TURN - 1;
			}
			else if (userInput == "s") {
				int i = 0; //not used
			}
			else {
				cout << "Invalid Input!!" << endl << endl;
				TURN = TURN - 1;
			}

			
			TURN++;
			
		}
		game = false; //end of game
	}
	cout << endl << endl << endl << "Game Over" << endl << endl << endl;
	return 0;
}
