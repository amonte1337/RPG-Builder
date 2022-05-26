#pragma once

#include "STLINCLUDE.h"
#include "Character.h"
#include "Functions.h"
#include "Event.h"


class Game
{
public:
	Game();
	virtual ~Game(); //virtual deconstructor

	//Operators

	//Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void characterMenu();
	void inventoryEquip();
	void saveCharacters();
	void loadCharacters();
	void selectCharacter();
	void Travel();

	//Accessors
	inline bool getPlaying() const { return this->playing; }

	//Modifiers


private:
	int choice;
	bool playing;

	//Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;

	//Enemies
	dArr<Enemy> enemies;
};


