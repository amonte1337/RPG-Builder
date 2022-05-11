#include "Event.h"

Event::Event()
{
	this->numOfEvents = 2;
}

Event::~Event() //virtual deconstructor
{
	//something is supposed to go here :P
}

void Event::generateEvent(Character& character)
{
	int i = rand() % this->numOfEvents;

	switch (i)
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character);
		break;

	case 1:
		//Puzzle
		puzzleEncounter(character);
		break;
		
	default:
		break;

	}
}

//Different events
void Event::enemyEncounter(Character & character)
{
	Enemy enemy;
	//while ()
	std::cout << "No enemies yet...\n";
	std::cout << "Press anything to continue";
	system("pause>0");

}

void Event::puzzleEncounter(Character& character)
{
	bool completed = false;
	int userAnswer = 0;
	int chances = 3; //refrain from infinite guess
	int gainExp = rand() % (chances * character.getLevel() * (rand() % 10 + 1));

	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		chances--; //decrement
		std::cout << "chances: " << chances+1 << "\n\n";

		std::cout << puzzle.getAsString(); //get question and answers to choose

		std::cout << "Your answer: ";
		std::cin >> userAnswer;

		while (std::cin.fail())
		{
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
		character.gainExp(gainExp);
		system("pause>0");
	}

	else
	{
		std::cout << "You've expended all of your tries, this puzzle is loss...\n\n";
		system("pause>0");
	}
}