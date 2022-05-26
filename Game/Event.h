#pragma once

#include "STLINCLUDE.h"
#include "Character.h"
#include "Enemy.h"
#include "dArr.h"
#include "Puzzle.h"


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

