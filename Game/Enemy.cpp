#include "Enemy.h"

Enemy::Enemy()
{
	//positioning
	//this->distanceTravelled = 0;

	//surface level stuff
	this->currency = 0;
	this->name = "";
	this->level = 0;
	this->exp = 0;

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

Enemy::Enemy(std::string name, int level, int hpMax, int ppMax, int offense, 
	int defense, int iq, int exp, int currency, int dropChance)
{
	//surface level stuff
	this->currency = currency;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->hpMax = hpMax;
	this->hp = this->hpMax;
	this->ppMax = ppMax;
	this->pp = this->ppMax;
	this->offense = offense;
	this->defense = defense;
	this->iq = iq;
	this->dropChance = dropChance;
	//this->speed = this->level * 2;
}

Enemy::~Enemy() //virtual deconstructor
{
	//something is supposed to go here :P
}

std::string Enemy::getAsString() const
{
	//print
	return "Name: " + this->name + '\n' +
		"Level: " + std::to_string(this->level) + '\n' +
		"HP: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + '\n' +
		"PP: " + std::to_string(this->pp) + " / " + std::to_string(this->ppMax) + '\n' +
		"Offense: " + std::to_string(this->offense) + '\n' +
		"Defense: " + std::to_string(this->defense) + '\n' +
		"IQ: " + std::to_string(this->iq) + '\n' +
		//"Speed: " + std::to_string(this->speed) + '\n' +
		"Drop chance: " + std::to_string(this->dropChance) + '%' + '\n';
}

void Enemy::takeDamage(int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}