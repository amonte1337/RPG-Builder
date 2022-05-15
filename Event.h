#pragma once

#include "Character.h"
#include "dArr.h"
#include "Puzzle.h"
#include <stdlib.h>

class Event
{
public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character, dArr<Enemy>& enemies);

	//Events
	void enemyEncounter(Character& character, dArr<Enemy>& enemies);
	void puzzleEncounter(Character& character);

private:
	int numOfEvents;
};

