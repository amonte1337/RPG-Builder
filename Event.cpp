#include "Event.h"

Event::Event()
{
	this->numOfEvents = 2;
}

Event::~Event() //virtual deconstructor
{
	//something is supposed to go here :P
}

void Event::generateEvent(Character& character, dArr<Enemy>& enemies)
{
	int i =  rand() % 2 + 1;

	switch (i)
	{
	case 1:
		//Enemy encounter
		std::cout << "Enemy encountered!\n";
		system("pause>0");
		system("CLS");
		enemyEncounter(character, enemies);
		break;

	case 2:
		//Puzzle
		std::cout << "Puzzle encounter!\n";
		system("pause>0");
		system("CLS");
		puzzleEncounter(character);
		break;
		
	default:
		break;
	}
}

//Different events
void Event::enemyEncounter(Character& character, dArr<Enemy>& enemies)
{
	//condition to simulate a turn-changing battle
	bool playerTurn = false;
	int choice;

	//coin toss for turn
	int coinToss = rand() % 5;

	if (coinToss >= 3)
		playerTurn = true;

	else
		playerTurn = false;

	//end conditions
	int gainExp = 0;
	int gainCurrency = 0;
	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;
	//battleOver = false; //used for while loop //while (!battleOver)

	int numOfEnemies;

	if (character.getLevel() < 4)
	{
		numOfEnemies = 1;
	}

	else if (character.getLevel() >= 4 && character.getLevel() < 7)
	{
		numOfEnemies = rand() % 2 + 1;
	}

	else 
	{
		numOfEnemies = rand() % 3 + 1;
	}


	for (size_t i = 0; i < numOfEnemies; i++)
	{
		enemies.push(Enemy("Return of Starman, Jr.", character.getLevel()));
	}

	//gainExp = enemies.size() * 

	//Battle variables
	int accuracyRoll = 0;
	int attack = 0;

	int playerAccurancy = 0;


	while (!escape && !playerDefeated && !enemiesDefeated)
	{

		if (!playerDefeated)
		{
			//UI
			std::cout << "= Player Turn =\n\n";
			std::cout << "Player: " << character.getName()
				<< ", HP: " << character.getHp() << "/" << character.getHpMax() << '\n';
			std::cout << "\n= Battle Menu =" << "\n\n";

			std::cout << "1: Bash" << '\n';
			std::cout << "2: ESP" << '\n';
			std::cout << "3: Item" << '\n';
			std::cout << "4: Defend" << '\n';
			std::cout << "5: Escape" << '\n';

			std::cout << "\nChoice: ";
			std::cin >> choice;

			while (std::cin.fail() || choice > 5 || choice < 1)
			{
				system("CLS");
				std::cout << "Faulty input.\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');

				std::cout << "= Battle Menu =" << "\n\n";

				std::cout << "1: Bash" << '\n';
				std::cout << "2: ESP" << '\n';
				std::cout << "3: Item" << '\n';
				std::cout << "4: Defend" << '\n';
				std::cout << "5: Escape" << '\n';

				std::cout << "\nChoice: ";
				std::cin >> choice;
			}

			std::cin.ignore(100, '\n');
			std::cout << '\n';

			//player's move
			switch (choice)
			{
				case 1:
					//ATTACKING
					
					//select enemy
					std::cout << "\nSelect enemy: " << "\n\n";

					for (size_t i = 0; i < enemies.size(); i++)
					{
						std::cout << i+1 << ": "
							<< enemies[i].getName() << " - "
							<< "HP: "
							<< enemies[i].getHp() << "/" << enemies[i].getHpMax()
							<< '\n';
					}
					std::cout << "\nChoice: ";
					std::cin >> choice;

					while (std::cin.fail() || choice > enemies.size() || choice < 1)
					{
						system("CLS");
						std::cout << "Faulty input.\n";
						std::cin.clear();
						std::cin.ignore(100, '\n');

						std::cout << "\nSelect enemy: " << "\n\n";

						for (size_t i = 0; i < enemies.size(); i++)
						{
							std::cout << i + 1 << ": "
								<< enemies[i].getName() << ' ' << i+1 << '\n';
						}
						std::cout << "\nChoice: ";
						std::cin >> choice;
					}

					std::cin.ignore(100, '\n');
					std::cout << '\n';

					//accuracy for hit or miss
					accuracyRoll = 1 + (rand() % 100);

					if (accuracyRoll >= 20 ) // 80% chance to hit
					{
						attack = character.getDamage() - (enemies[choice - 1].getDefense() / 2);
						if (character.getDamage() < enemies[choice - 1].getDefense())
							attack = ((character.getDamage() * 3) - enemies[choice - 1].getDefense()) / 4;

						std::cout << character.getName() << " hit the enemy for "
							<< attack << " damage.\n";
						//system("pause>0");

						enemies[choice - 1].takeDamage(attack);

						//if targeted enemy's HP hits 0
						if (!enemies[choice - 1].isAlive())
						{
							std::cout << enemies[choice - 1].getName() 
								<< " was tamed.";

							//gets values from enemy that was tamed
							gainExp = enemies[choice - 1].getExp();
							gainCurrency = enemies[choice - 1].getCurrency();

							//removes enemy from battle
							enemies.remove(choice - 1);
						}
						system("pause>0");
						system("ClS");
						
					}

					else if (accuracyRoll < 20) // 20% chance to miss
					{
						//we do a little trolling
						int message = rand() % 2;
						
						if (message == 1)
						{
							std::cout << "Just missed...\n";
							system("pause>0");
							system("ClS");
						}
						else
						{
							std::cout << character.getName() << " narrowly missed.\n";
							system("pause>0");
							system("CLS");
						}
					}

					break;

				case 2:
					//ESP
					std::cout << "No ESP skills right now...";
					system("pause>0");
					system("CLS");
					break;

				case 3:
					//ITEM
					std::cout << "Inventory is empty...";
					system("pause>0");
					system("CLS");
					break;

				case 4:
					//DEFENDING
					std::cout << "What are you defending from?";
					system("pause>0");
					system("CLS");
					break;

				case 5:
					escape = true;
					std::cout << "Ran away successfully.\n";
					system("pause>0");
					system("CLS");
					//RUNNING
					break;

				default:
					break;
			}
		}

		//Leave Turn
		playerTurn = false;

		if(!escape && !playerTurn && !enemiesDefeated)
		{
			//enemies' attack
			for (size_t i = 0; i < enemies.size(); i++)
			{
				accuracyRoll = 1 + (rand() % 100);

				if (accuracyRoll >= 20) // 80% chance to hit
				{
					std::cout << "= Enemy Turn =\n\n";

					attack = enemies[i].getDamage() - (character.getDefense() / 2);
					if (enemies[i].getDamage() < character.getDefense())
						attack = ((enemies[i].getDamage() * 3) - character.getDefense()) / 4;

					std::cout << enemies[i].getName() << ' ' << i + 1 << " hit the player for "
						<< attack << " damage.\n";
					//system("pause>0");

					character.takeDamage(attack);

					if (!character.isAlive())
					{
						std::cout << character.getName() << " fell unconscious!\n\n";
						//system("pause>0");
					}

					system("pause>0");
					system("ClS");
				}

				else if (accuracyRoll < 20) //20% chance to miss
				{
					std::cout << "= Enemy Turn =\n\n";

					int message = rand() % 2;

					if (message == 1)
					{
						std::cout << enemies[i].getName() << ' ' << i + 1 << " just missed...\n";
						system("pause>0");
						system("ClS");
					}
					else
					{
						std::cout << enemies[i].getName() << ' ' << i+1 << " narrowly missed.\n";
						system("pause>0");
						system("CLS");

					}
				}
			}

			//Leave Turn
			playerTurn = true;
		}
		//Conditions


		if (!character.isAlive())
		{
			playerDefeated = true;
			std::cout << "The battle was lost...\n";
			system("pause>0");

			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies.remove(i);

			}
			character.updateStats();
		}


		else if (enemies.size() <= 0)
		{
			enemiesDefeated = true;
			std::cout << "YOU WON!\n";
			system("pause>0");
			std::cout << "You gained " << gainExp << " exp. points!\n";
			std::cout << "You gained " << gainCurrency << " Auten!\n\n";
			character.gainCurrency(gainCurrency);
			character.gainExp(gainExp);
			system("pause>0");

			character.updateStats();
		}
	}
}

void Event::puzzleEncounter(Character& character)
{
	bool completed = false;
	int userAnswer = 0;
	int chances = 3; //refrain from infinite guesses

	//determine gains
	int gainCurrency = (chances * character.getLevel() * (rand() % 10 + 1) / 3);
	int gainExp = (chances * character.getLevel() * (rand() % 10 + 1) / 3);

	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		chances--; //decrement
		std::cout << "chances left: " << chances << "\n\n";

		std::cout << puzzle.getAsString(); //get question and answers to choose

		std::cout << "Your answer: ";
		std::cin >> userAnswer;

		if(std::cin.fail())
		{
			chances--;
			std::cout << "Faulty input.\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');

			std::cout << "Choice: ";
			std::cin >> userAnswer;
		}

		std::cin.ignore(100, '\n');
		std::cout << '\n';

		if (puzzle.getCorrectAnswer() == userAnswer)
		{
			completed = true;
		}

	}
	if (completed)
	{
		std::cout << "Congrats, you answered correctly!\n\n";
		//give user exp, gold, etc
		std::cout << "You gained " << gainExp << " exp. points!\n";
		std::cout << "You gained " << gainCurrency << " Auten!\n";
		character.gainCurrency(gainCurrency);
		system("pause>0");
		character.gainExp(gainExp);
		system("pause>0");
	}

	else
	{
		std::cout << "You've expended all of your tries, this puzzle was loss...\n\n";
		system("pause>0");
	}
}