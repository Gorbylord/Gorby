#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <Windows.h>
using namespace std;

int lives;
int health;
int enemykilled;
int score;
bool weapon;


int main()
{
	printf("Hello wonderer\nThe adventure begin.\n");//No sale.

	lives = 2;
	health = 2;
	enemykilled = 0;
	score = 0;
	weapon = 0;
	
		
	while (lives > 0)
	{
		if (health > 0)
		{
			srand(time(0));
			int randomNumber = rand();
			int dice = (randomNumber % 4) + 1;
			
				switch (dice)
				{
				
				case 1:
					printf("You encounter an enemy!\n");
					if (weapon)
					{
						printf("You destroy him, also your weapon.\n");
						weapon = 0;
						score += 150;
						enemykilled++;
						printf("Score:%i\n", score);
						break;
					}
					else
					{
						printf("He is bad and hits you.\n");
						health--;
						printf("Health:%i\n", health);
						break;
					}
			
				case 2:
					printf("You found a treasure, awesome!\n");
					score += 100;
					printf("Score:%i\n", score);
					break;
				
				case 3:
					printf("You found a potion\n");
					if (health != 2)
					{
						health++;
						printf("Health:%i\n", health);
						break;
					}
					else
					{
						printf("You don´t need this.\n");
						break;
					}
				
				case 4:
					printf("A marvelous sword.\n");
					if (weapon)
					{
						printf("You already have one.\n");
						break;
					}
					else
					{
						weapon = 1;
						break;
					}
					
				}
			printf("Enter to continue\n");
			cin.ignore(cin.rdbuf()->in_avail() + 1);
		}
		else
		{
			lives --;
			printf("Lives:%i\n", lives);
			health = 2;
		}
	}
		
	Sleep(50);
	printf("Enemykilled:%i\n", enemykilled);//no sale
	score *= enemykilled;//no sale
	printf("You die!!!\n");
	printf("Score:%i\n", score);

	cin.ignore(cin.rdbuf()->in_avail() + 1);
	return 0;
}
