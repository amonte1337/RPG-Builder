#pragma once

#include "STLINCLUDE.h"

class Enemy
{
public:
	Enemy();
	Enemy(std::string name, int level, int hpMax, int ppMax, int offense,
		int defense, int iq, int exp, int currency, int dropChance);
	virtual ~Enemy(); //virtual deconstructor
	inline bool isAlive() { return this->hp > 0; }
	std::string getAsString() const;
	void takeDamage(int damage);

	inline const int& getDamage() const { return this->offense + rand() % 10; }
	inline int getExp() const { return this->exp; }
	inline int getCurrency() const { return this->currency; }
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getPpMax() const { return this->ppMax; }
	inline const int& getPp() const { return this->pp; }
	inline const int& getOffsense() const { return this->offense; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getIQ() const { return this->iq; }
	//inline const int& getSpeed() const { return this->speed; }


private:
	std::string name;
	int level;
	int exp;
	int currency;
	int hp;
	int hpMax;
	int pp;
	int ppMax;
	int offense;
	int defense;
	int iq;
	float dropChance;
	//int speed;
};

