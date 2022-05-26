#include "Game.h"

Game::Game()
{
	choice = 0; //initialize choice
	playing = true;	//runs while playing is true
	activeCharacter = 0; //for vector value
	fileName = "characters.txt"; //obligatory file name ;)
}

Game::~Game() //virtual deconstructor 
{
	//something is supposed to go here :P
}

//Functions

bool is_empty(std::ifstream& infile)
{
	while(infile.peek() == '\n')
	{
		infile.clear();
		infile.ignore(1000, '\n');
	}
	return infile.peek() == std::ifstream::traits_type::eof();
}

void Game::initGame()
{
	std::ifstream infile;
	infile.open("characters.txt");

	Weapon::initNames();
	Armor::initNames();

	//if file opens and isnt empty
	//load characters from file
	if (infile.is_open() && !is_empty(infile))
		this->loadCharacters();

	//if file doesnt open, print it out
	else if (!infile.is_open())
		std::cout << "File can't open!";

	//if file opens but is empty
	//create new character
	else if(infile.is_open() && is_empty(infile))
	{
		createNewCharacter();
		this->saveCharacters();
	}

	infile.close();
}


void Game::mainMenu()
{
	system("pause>0");
	system("CLS");

	if (this->characters[activeCharacter].isAlive())
	{
		//print menu
		std::cout << "= MAIN MENU =" << "\n\n";

		std::cout << "= Active Character: " << this->characters[activeCharacter].getName()
			<< " =" << "\n\n";
		std::cout << "= Current number of characters: " << this->characters.size()
			<< " =" << "\n\n";

		std::cout << "0: Quit" << '\n';
		std::cout << "1: Travel" << '\n';
		std::cout << "2: Shop" << '\n';
		std::cout << "3: Character sheet" << '\n';
		std::cout << "4: View Inventory" << '\n';
		std::cout << "5: Create new character" << '\n';
		std::cout << "6: Save characters" << '\n';
		std::cout << "7: Load characters" << '\n';
		std::cout << "8: Select character" << '\n';
		std::cout << '\n';

		std::cout << "\nChoice: ";
		std::cin >> this->choice;

		while (std::cin.fail())
		{
			std::cout << "Faulty input.\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');

			std::cout << "\nChoice: ";
			std::cin >> this->choice;
		}
		std::cin.ignore(100, '\n');
		std::cout << '\n';

		//switch case
		switch (this->choice)
		{
			//QUIT
		case 0:
			playing = false;
			this->saveCharacters();
			break;

			//TRAVEL
		case 1:
			this->Travel();
			break;

			//SHOP
		case 2:
			std::cout << "We're closed." << '\n';
			std::cout << "Press anything to continue...";
			system("pause>0");
			break;

			//CHARACTER SHEET
		case 3:
			system("CLS");
			//this->characters[this->activeCharacter].printStats();
			this->characterMenu();
			break;

			//INVENTORY
		case 4:
			system("CLS");
			std::cout << this->characters[this->activeCharacter].getInventoryAsString();
			break;

			//NEW CHARACTER
		case 5:
			this->createNewCharacter();
			this->saveCharacters();
			break;

			//SAVE CHARACTER(S)
		case 6:
			this->saveCharacters();
			system("pause>0");
			break;

			//LOAD CHARACTER(S)
		case 7:
			this->loadCharacters();
			system("pause>0");
			break;

			//SWITCH CHARACTER(S)
		case 8:
			this->selectCharacter();
			break;

			//INVALID INPUT
		default:
			std::cout << "Try again, kid." << '\n';
			std::cout << "Press anything to continue...";
			system("pause>0");
			break;
		}
	}

	else
	{
		std::cout << "Oh no, it looks like you really got your head handed to ya.\n";
		std::cout << "Would ya like to try again? (1) Yes, (2) No\n";
		std::cin >> this->choice;

		while (std::cin.fail() || this->choice < 1 || this->choice > 2)
		{
			std::cout << "Faulty input.\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');

			std::cout << "\nChoice: ";
			std::cin >> this->choice;
		}
		std::cin.ignore(100, '\n');
		std::cout << '\n';

		if (this->choice == 1)
		{
			std::cout << "Get back out there, champ!\n";
			system("pause>0");
			this->loadCharacters();
		}

		else
		{
			system("CLS");
			std::cout << "And so, the world fell into darkness....";
			system("pause>0");
			playing = false;
		}
	}
}

void Game::createNewCharacter()
{
	std::string name = "";
	std::cout << "Enter your character name: ";
	getline(std::cin, name);

	while (name == "" || name == " ")
	{
		int message = rand() % 2;
		
		if (message == 1)
		{
			std::cout << "Well, you gotta have a name...";
			system("pause>0");
			system("CLS");
			std::cout << "Enter your character name: ";
			getline(std::cin, name);
		}

		else
		{
			std::cout << "Don't be shy, you can tell me...";
			system("pause>0");
			system("CLS");
			std::cout << "Enter your character name: ";
			getline(std::cin, name);
		}
		
	}

	bool exist = false;

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			exist = true;
			std::cout << "Character already exists.\n\n";
			std::cout << "Character name: ";
			getline(std::cin, name);
		}
	}

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
	
}

void Game::characterMenu()
{
	do
	{
		std::cout << "ENTER to continue...\n";
		system("pause>0");
		system("CLS");
		std::cout << "= Character Menu =\n\n";

		characters[activeCharacter].printStats();

		std::cout << "\n= MENU =\n\n";
		std::cout << "0: Exit" << '\n';
		std::cout << "1: Print Inventory" << '\n';
		std::cout << "2: Equip" << '\n';
		
		std::cout << "\nChoice: ";
		std::cin >> this->choice;
		
		while (std::cin.fail() || this->choice < 0 || this->choice > 2)
		{
			system("CLS");
			std::cout << "= Character Menu =\n\n";

			characters[activeCharacter].printStats();

			std::cout << "Faulty input.\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');

			std::cout << "\n= MENU =\n\n";
			std::cout << "0: Exit" << '\n';
			std::cout << "1: Print Inventory" << '\n';
			std::cout << "2: Equip" << '\n';

			std::cout << "\nChoice: ";
			std::cin >> this->choice;
		}

		std::cin.ignore(100, '\n');
		std::cout << '\n';

		switch (this->choice)
		{
		case 1:
			std::cout << this->characters[activeCharacter].getInventoryAsString();


			break;

		case 2:
			std::cout << this->characters[activeCharacter].getInventoryAsString();

			std::cout << "Item index: ";
			std::cin >> this->choice;

			while (std::cin.fail() || this->choice < 1 
				|| this->choice > this->characters[activeCharacter].getInventorySize())
			{
				system("CLS");
				std::cout << this->characters[activeCharacter].getInventoryAsString();
				std::cout << "Faulty input.\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');

				std::cout << "Item index: ";
				std::cin >> this->choice;
			}

			std::cin.ignore(100, '\n');
			std::cout << '\n';

			this->characters[this->activeCharacter].equipItem(this->choice - 1);
			break;


		default:
			break;
		}
	} while (this->choice > 0);

	std::cout << "See ya next year, loser";
}

void Game::inventoryEquip()
{

}

void Game::saveCharacters()
{
	std::ofstream outfile(fileName);

	if (outfile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outfile << characters[i].getAsString() << '\n';
			std::cout << characters[i].getName() << " saved.\n";
		}
	}

	outfile.close();
}

void Game::loadCharacters()
{
	std::ifstream infile(fileName);

	//this->characters.clear();

	std::string name = "";
	int distanceTravelled = 0;
	int currency = 0;
	int level = 0;
	int exp = 0;
	int expNext = 0;
	int vitality = 0;
	int psyche = 0;
	int hpMax = 0;
	int ppMax = 0;
	int offense = 0;
	int defense = 0;
	int iq = 0;
	//int speed = 0;

	std::string line = "";
	std::stringstream str;

	if (infile.is_open() && !is_empty(infile))
	{
		while (getline(infile, line))
		{
			if (line.empty())
			{
				str.clear();
				str.ignore(1000, '\n');
			}

			else
			{
				str.str(line);
				str >> name;
				str >> distanceTravelled;
				str >> currency;
				str >> level;
				str >> exp;
				str >> expNext;
				str >> vitality;
				str >> psyche;
				str >> hpMax;
				str >> ppMax;
				str >> offense;
				str >> defense;
				str >> iq;
				//str >> speed;

				Character temp(name, distanceTravelled, currency, level, exp, expNext,
					vitality, psyche, hpMax, ppMax, offense, defense, iq);

				this->characters.push_back(Character(temp));

				std::cout << "Character " << name << " loaded!\n";
				str.clear();
			}
		}
	}

	else if (infile.is_open() && is_empty(infile))
	{
		std::cout << "File is empty. No characters loaded!\n";
		str.clear();
	}

	infile.close();

	if (this->characters.size() <= 0)
	{
		throw "Error. No characters loaded, or it's an empty file.";
	}
}

void Game::selectCharacter()
{
	for (size_t i = 0; i < this->characters.size(); i++)
	{
		std::cout << i+1 << ": " << this->characters[i].getName()
			<< ", Level: " << this->characters[i].getLevel() << "\n\n";
	}
	std::cout << "Select character: ";
	std::cin >> this->choice;
	this->choice -= 1;

	while (std::cin.fail() || this->choice >= this->characters.size() || this->choice < 0)
	{
		std::cout << "Faulty input.\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "\nSelect character: ";
		std::cin >> this->choice;
	}
	std::cin.ignore(100, '\n');
	std::cout << '\n';

	this->activeCharacter = this->choice;

	std::cout << this->characters[this->activeCharacter].getName()
		<< " has been selected.\n\n";
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event event;

	event.generateEvent(this->characters[activeCharacter], this->enemies);
}