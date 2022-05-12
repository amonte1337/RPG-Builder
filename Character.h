#pragma once

#include "Inventory.h"
#include "Enemy.h"

class Character
{
public:
	Character();
	Character(std::string name, int currency, int level,
		int exp, int expNext, int vitality, int psyche, int strength, int dexterity,
		int hp, int pp, int offense, int defense,
		int iq, int speed);
	virtual ~Character(); //virtual deconstructor

	//Functions
	void initialize(const std::string name);
	void printStats() const;
	void levelUp();
	void updateStats();
	std::string getAsString() const;

	//Accessors
	//inline const int& getDistTravel() const { return this->distanceTravelled; }
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getPpMax() const { return this->ppMax; }
	inline const int& getPp() const { return this->pp; }
	inline const int& getOffsense() const { return this->offense; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getIQ() const { return this->iq; }
	inline const int& getSpeed() const { return this->speed; }

	//Modifiers
	//inline void setDistTravel(const int& distance) { this->distanceTravelled += distance; }
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int& exp) { this->exp += exp; levelUp(); }
	inline void gainCurrency(const int& currency) { this->currency += currency; }

private:
	int distanceTravelled;

	Inventory inventory;
	Weapon weapon;
	Armor armor;
	int currency;

	std::string name;
	int level;
	int exp;
	int expNext;

	int vitality;
	int psyche;
	int strength;
	int dexterity;

	int hpMax;
	int hp;
	int ppMax;
	int pp;
	int offense;
	int defense;
	int iq;
	int speed;
};
