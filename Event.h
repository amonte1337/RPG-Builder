#pragma once

#include "Character.h"
#include "Puzzle.h"
#include <stdlib.h>

class Event
{
public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character);

	//Events
	void enemyEncounter(Character& character);
	void puzzleEncounter(Character& character);

private:
	int numOfEvents;
};

