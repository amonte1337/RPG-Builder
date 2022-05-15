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

	//the meat and bones of a character!
	this->hpMax = 0;
	this->hp = 0;
	this->ppMax = 0;
	this->pp = 0;
	this->offense = 0;
	this->defense = 0;
	this->iq = 0;
	//this->speed = 0;
}

Character::Character(std::string name, int distanceTravelled, int currency, 
	int level, int exp, int expNext, int vitality, int psyche, int hpMax, 
	int ppMax, int offense, int defense, int iq)
{
	//positioning?
	this->distanceTravelled = distanceTravelled;

	//surface level stuff
	this->currency = currency;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = expNext;

	//invisible stats that determine the other stats
	this->vitality = vitality;
	this->psyche = psyche;

	//the meat and bones of a character!
	this->hpMax = hpMax;
	this->ppMax = ppMax;
	this->offense = offense;
	this->defense = defense;
	this->iq = iq;
	//this->speed = speed;

	this->updateStats();
}

Character::~Character()
{
	//something is supposed to go here :P
}

//Functions
void Character::initialize(const std::string name)
{
	this->distanceTravelled = 0;

	this->currency = 100;
	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>(pow(level, 3) + 5);

	this->vitality = 0;
	this->psyche = 0;
	this->strength = 0;
	this->dexterity = 0;

	this->hpMax = 30;
	this->hp = hpMax;
	this->ppMax = 10;
	this->pp = ppMax;
	this->offense = 5;
	this->defense = 5;
	this->iq = 5;
	//->speed = 5 ;
}

void Character::printStats() const
{
	std::cout << "= Character Sheet =" << '\n';
	std::cout << '\n';
	std::cout << "= Auten: " << this->currency << '\n';
	std::cout << "= Name: " << this->name << '\n';
	std::cout << "= Distance Travelled: " << this->distanceTravelled << '\n';
	std::cout << "= Level: " << this->level << '\n';
	std::cout << "= EXP: " << this->exp << '\n';
	std::cout << "= To Next Level: " << this->expNext - this->exp << '\n';
	std::cout << '\n';
	std::cout << "= HP: " << this->hp << " / " << this->hpMax << '\n';
	std::cout << "= PP: " << this->pp << " / " << this->ppMax << '\n';
	std::cout << '\n';
	std::cout << "= Vitality: " << this->vitality << '\n';
	std::cout << "= Psyche: " << this->psyche << '\n';
	std::cout << "= Offense: " << this->offense << '\n';
	std::cout << "= Defense: " << this->defense << '\n';
	std::cout << "= IQ: " << this->iq << '\n';
	//std::cout << "= Speed: " << this->speed << '\n';
	std::cout << "\n\n";

	std::cout << "= Equipment =" << '\n';
	std::cout << '\n';
	std::cout << "= Weapon: " << this->weapon.getName()
		<< ", Offense +" << this->weapon.getOffense() << '\n';

	std::cout << "= Armor piece: " << this->armor.getName()
		<< ", Defense +" << this->armor.getDefense() << '\n';

	std::cout << "Press anything to continue...";
	system("pause>0");
}

void Character::levelUp()
{
	if (this->exp >= this->expNext && this->level < 100)
	{
		int prevHp = this->hpMax;
		int prevPp = this->ppMax;
		int prevVit = this->vitality;
		int prevPsy = this->psyche;
		int prevOff = this->offense;
		int prevDef = this->defense;
		int prevIq = this->iq;
		int chance = 0;
		//int prevSpeed = this->speed;

		while (this->exp >= this->expNext && this->level < 100)
		{
			this->level++;
			this->expNext = static_cast<int>(pow(level, 3) + 5);

			//increment stats
			chance += 1 + (rand() % 100);
			if (chance > 90) //10%
			{
				this->vitality++;
				this->hpMax += 20;
			}

			else
			{
				//vitality goes up by 1
				this->vitality = prevVit;
				this->hpMax += 5;
			}

			chance += 1 + (rand() % 100);
			if (chance > 90) //10%
			{
				//psyche goes up by 1
				this->psyche++;
				this->ppMax += 8;
			}

			else
			{
				this->psyche = prevPsy;
				this->ppMax += 2;
			}

			this->offense += rand () % 8;
			this->defense += rand() % 5;
			this->iq += rand() % 5;
			//this->speed += rand() % 4;

			//update stats
			this->updateStats();
		}

		//print if character level up
		//system("CLS");
		std::cout << this->getName() << " is now level "
			<< this->getLevel() << "!" << "\n\n";
		system("pause>0");

		//these only print out if the variable actually increased at all
		if (prevHp != this->hpMax)
		{
			if (this->hpMax - prevHp >= 15)
			{
				std::cout << "Healthy AF! ";
			}
			std::cout << "HP went up by " << this->hpMax - prevHp << ".\n";
		}

		if (prevPp != this->ppMax)
		{
			if (this->ppMax - prevPp >= 8)
			{
				std::cout << "It's so big! ";
			}
			std::cout << "PP went up by " << this->ppMax - prevPp << ".\n";
		}

		if (prevOff != this->offense)
		{
			if (this->offense - prevOff >= 3)
			{
				std::cout << "Yo, stronk! ";
			}
			std::cout << "Offense went up by " << this->offense - prevOff << ".\n";
		}

		if (prevDef != this->defense)
		{
			if (this->defense - prevDef >= 3)
			{
				std::cout << "That's tuff! ";
			}
			std::cout << "Defense went up by " << this->defense - prevDef << ".\n";
		}

		if (prevIq != this->iq)
		{
			if (this->iq - prevIq >= 3)
			{
				std::cout << "Wow, smort! ";
			}
			std::cout << "IQ went up by " << this->iq - prevIq << ".\n";
		}

		/*if (prevSpeed != this->speed)
		{
			if (this->speed - prevSpeed >= 3)
			{
				std::cout << "Kachow! ";
			}
			std::cout << "Speed went up by " << this->speed - prevSpeed << ".\n";
		}*/

		std::cout << "\nPress anything to continue...";
		//system("pause>0");
	}
}

void Character::updateStats()
{
	//this is to update stats after a level up
	this->expNext = static_cast<int>(pow(level, 3) + 5);

	this->hp = hpMax;
	this->pp = ppMax;
}

std::string Character::getAsString() const
{
	return
		this->name + ' ' +
		std::to_string(this->distanceTravelled) + ' ' +
		std::to_string(this->currency) + ' ' +
		std::to_string(this->level) + ' ' +
		std::to_string(this->exp) + ' ' +
		std::to_string(this->expNext) + ' ' +
		std::to_string(this->vitality) + ' ' +
		std::to_string(this->psyche) + ' ' +
		std::to_string(this->hpMax) + ' ' +
		std::to_string(this->ppMax) + ' ' +
		std::to_string(this->offense) + ' ' +
		std::to_string(this->defense) + ' ' +
		std::to_string(this->iq);
		//std::to_string(this->speed);
} 

void Character::takeDamage(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}
