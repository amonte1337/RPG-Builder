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
void Game::initGame()
{
	//std::string playerName;

	//std::cout << "Enter your name: ";
	//std::cin >> playerName;

	
	//debug
	Inventory inv;
	inv.addItem(Weapon(0, "Wep"));
	inv.addItem(Weapon(0, "Wep"));
	inv.addItem(Weapon(0, "Wep"));

	inv.addItem(Armor(0, "Amr"));
	inv.addItem(Armor(0, "Amr"));
	inv.addItem(Armor(0, "Amr"));

	for (size_t i = 0; i < inv.size(); i++)
	{
		std::cout << inv[i].debugPrint() << '\n';
	}
	

	//debug
	/*Puzzle puzzle("Puzzles/1.txt");
	std::cout << puzzle.getAsString() << '\n';*/

	createNewCharacter();
}


void Game::mainMenu()
{
	system("CLS");
	//print menu
	std::cout << "= MAIN MENU =" << '\n' << '\n';

	std::cout << "0: Quit" << '\n';
	std::cout << "1: Travel" << '\n';
	std::cout << "2: Shop" << '\n';
	std::cout << "3: Rest" << '\n';
	std::cout << "4: Character sheet" << '\n';
	std::cout << "5: Create new character" << '\n';
	std::cout << "6: Save characters" << '\n';
	std::cout << "7: Load characters" << '\n';
	std::cout << '\n';
	
	std::cout << "\nChoice: ";
	std::cin >> choice;
	
	while (std::cin.fail())
	{
		std::cout << "Faulty input.\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "\nChoice: ";
		std::cin >> choice;
	}
	std::cin.ignore(100, '\n');
	std::cout << '\n';
	
	//switch case
	switch(choice)
	{
		//QUIT
	case 0:
		playing = false;
		break;
		
		//TRAVEL
	case 1:
		Travel();
		break;

		//SHOP
	case 2:
		std::cout << "Not done yet." << '\n';
		std::cout << "Press anything to continue...";
		system("pause>0");
		break;

		//REST(?)
	case 3:
		std::cout << "Not done yet." << '\n';
		std::cout << "Press anything to continue...";
		system("pause>0");
		break;

		//CHARACTER SHEET
	case 4:
		system("CLS");
		characters[activeCharacter].printStats();
		break;

		//NEW CHARACTER
	case 5:
		createNewCharacter();
		saveCharacters();
		break;

		//SAVE CHARACTER(S)
	case 6:
		saveCharacters();
		break;

		//LOAD CHARACTER(S)
	case 7:
		loadCharacters();
		break;

		//INVALID INPUT
	default:
		std::cout << "Try again, nerd." << '\n';
		std::cout << "Press anything to continue...";
		system("pause>0");
		break;
	}
}

void Game::createNewCharacter()
{
	std::string name = "";
	std::cout << "Character name: ";
	getline(std::cin, name);
	//std::cin.sync();

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}

void Game::levelUpCharacter()
{
	this->characters[activeCharacter].levelUp();

	std::cout << "Stat to upgrade: ";
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
}

void Game::saveCharacters()
{
	std::ofstream outfile(fileName);

	if (outfile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outfile << characters[i].getAsString() << '\n';
		}
	}
	outfile.close();
}

void Game::loadCharacters()
{
	//something is supposed to go here :P
	std::ifstream infile(fileName);

	//this->characters.clear();

	std::string name = "";
	int currency = 0;
	//int distanceTravelled = 0;
	int level = 0;
	int exp = 0;
	int expNext = 0;
	int vitality = 0;
	int psyche = 0;
	int strength = 0;
	int dexterity = 0;
	int hp = 0;
	int pp = 0;
	int offense = 0;
	int defense = 0;
	int iq = 0;
	int speed = 0;
	int statPoints = 0;
	int skillPoints = 0;

	std::string line = "";
	std::stringstream str;

	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			str.str(line);
			str >> name;
			str >> currency;
			str >> level;
			str >> exp;
			str >> expNext;
			str >> vitality;
			str >> psyche;
			str >> strength;
			str >> dexterity;
			str >> hp;
			str >> pp;
			str >> offense;
			str >> defense;
			str >> iq;
			str >> speed;
			str >> statPoints;
			str >> skillPoints;

			Character temp(name, currency, level, exp, expNext, vitality,
				psyche, strength, dexterity, hp, pp, offense, defense,
				iq, speed, statPoints, skillPoints);

			this->characters.push_back(Character(temp));
			
			std::cout << "Character " << name << " loaded!\n";
			str.clear();
		}
	}

	infile.close();

	if (this->characters.size() <= 0)
	{
		throw "Error. No characters loaded, or it's an empty file.";
	}
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event event;

	event.generateEvent(this->characters[activeCharacter]);
}