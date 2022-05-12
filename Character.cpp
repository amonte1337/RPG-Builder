#include "Character.h"

Character::Character()
{
	//positioning
	//this->distanceTravelled = 0;

	//surface level stuff
	this->currency = 0;
	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	//invisible stats that determine the other stats
	this->vitality = 0;
	this->psyche = 0;
	this->strength = 0;
	this->dexterity = 0;

	//the meat and bones of a character!
	this->hpMax = 0;
	this->hp = 0;
	this->ppMax = 0;
	this->pp = 0;
	this->offense = 0;
	this->defense = 0;
	this->iq = 0;
	this->speed = 0;
}

Character::Character(std::string name, int currency, int level, 
	int exp, int expNext,int vitality, int psyche, int strength, int dexterity, 
	int hp, int pp, int offense,int defense, 
	int iq, int speed)
{
	//positioning?
	//this->distanceTravelled = distanceTravelled;

	//surface level stuff
	this->currency = currency;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = expNext;

	//invisible stats that determine the other stats
	this->vitality = vitality;
	this->psyche = psyche;
	this->strength = strength;
	this->dexterity = dexterity;

	//the meat and bones of a character!
	this->hp = hp;
	this->pp = pp;
	this->offense = offense;
	this->defense = defense;
	this->iq = iq;
	this->speed = speed;

	this->updateStats();
}

Character::~Character()
{
	//something is supposed to go here :P
}

//Functions
void Character::initialize(const std::string name)
{
	//this->distanceTravelled = 0;

	this->currency = 100;
	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>(pow(level, 3) + 5);

	this->vitality = 5;
	this->psyche = 3;
	this->strength = 3;
	this->dexterity = 2; 

	this->hpMax = (this->vitality * 2) + 30;
	this->hp = hpMax;
	this->ppMax = (this->vitality * 1.5) + 10;
	this->pp = ppMax;
	this->offense = (this->strength * 2) + 5;
	this->defense = (this->strength * 2);
	this->iq = (this->psyche * 1.5) + 5;
	this->speed = (this->dexterity * 1.5) + 2;
}

void Character::printStats() const
{
	std::cout << "= Character Sheet =" << '\n';
	std::cout << '\n';
	std::cout << "= Auten: " << this->currency << '\n';
	std::cout << "= Name: " << this->name << '\n';
	std::cout << "= Level: " << this->level << '\n';
	std::cout << "= EXP: " << this->exp << '\n';
	std::cout << "= To Next Level: " << this->expNext - this->exp << '\n';
	std::cout << '\n';
	std::cout << "= HP: " << this->hp << " / " << this->hpMax << '\n';
	std::cout << "= PP: " << this->pp << " / " << this->ppMax << '\n';
	std::cout << '\n';
	std::cout << "= Offense: " << this->offense << '\n';
	std::cout << "= Defense: " << this->defense << '\n';
	std::cout << "= IQ: " << this->iq << '\n';
	std::cout << "= Speed: " << this->speed << '\n';
	std::cout << '\n';
	std::cout << "Press anything to continue...";
	system("pause>0");
}

void Character::levelUp()
{
	if (this->exp >= this->expNext && this->level < 100)
	{
		int prevHp = this->hpMax;
		int prevPp = this->ppMax;
		int prevOff = this->offense;
		int prevDef = this->defense;
		int prevIq = this->iq;
		int prevSpeed = this->speed;

		while (this->exp >= this->expNext && this->level < 100)
		{
			this->exp -= this->expNext;
			this->level++;
			this->expNext = static_cast<int>(pow(level, 3) + 5);

			//increment stats
			this->vitality += rand() % 5;
			this->psyche += rand() % 5;
			this->strength += rand() % 5;
			this->dexterity += rand() % 5;

			//update stats
			this->updateStats();
		}

		//print if character level up
		system("CLS");
		std::cout << this->getName() << " is now level "
			<< this->getLevel() << "!" << "\n\n";

		//these only print out if the variable actually increased at all
		if (prevHp != this->hpMax)
		{
			std::cout << "HP went up by " << this->hpMax - prevHp << ".\n";
		}

		if (prevPp != this->ppMax)
		{

			std::cout << "PP went up by " << this->ppMax - prevPp << ".\n";
		}

		if (prevOff != this->offense)
		{
			std::cout << "Offense went up by " << this->offense - prevOff << ".\n";
		}
		
		if (prevDef != this->defense)
		{
			std::cout << "Defense went up by " << this->defense - prevDef << ".\n";
		}
		
		if (prevIq != this->iq)
		{
			std::cout << "IQ went up by " << this->iq - prevIq << ".\n";
		}
		
		if (prevSpeed != this->speed)
		{
			std::cout << "Speed went up by " << this->speed - prevSpeed << ".\n";
		}

		std::cout << "\nPress anything to continue...";
		system("pause>0");
	}
}

void Character::updateStats()
{
	//this is to update stats after a level up
	this->expNext = static_cast<int>(pow(level, 3) + 5);

	this->hpMax = (this->vitality * 2) + 30;
	this->hp = hpMax;
	this->ppMax = (this->vitality * 1.5) + 10;
	this->pp = ppMax;
	this->offense = (this->strength * 2) + 5;
	this->defense = (this->strength * 2);
	this->iq = (this->psyche * 1.5) + 5;
	this->speed = (this->dexterity * 1.5) + 2;
}

std::string Character::getAsString() const
{
	return
		this->name + ' ' +
		std::to_string(this->currency) + ' ' +
		std::to_string(this->level) + ' ' +
		std::to_string(this->hpMax) + ' ' +
		std::to_string(this->ppMax) + ' ' +
		std::to_string(this->offense) + ' ' +
		std::to_string(this->defense) + ' ' +
		std::to_string(this->iq) + ' ' +
		std::to_string(this->speed);
}
