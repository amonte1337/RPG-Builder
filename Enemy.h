#pragma once

#include <stdlib.h>
#include <string>

class Enemy
{
public:
	Enemy(std::string name = "NONE.", int level = 0);
	virtual ~Enemy(); //virtual deconstructor

	inline bool isAlive() { return this->hp > 0; }
	std::string getAsString() const;
	inline void takeDamage(int damage) { this->hp -= damage; }
	inline int getDamage() const { return (rand() % 10) + this->offense; }
	inline int getExp() const { return this->level * 43; }

private:
	std::string name;
	int level;
	int exp;
	int hp;
	int hpMax;
	int pp;
	int ppMax;
	int offense;
	int defense;
	int iq;
	float dropChance;
	int speed;
};

