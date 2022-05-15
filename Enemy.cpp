#include "Enemy.h"

Enemy::Enemy(std::string name, int level)
{
	//initialize for debug
	//surface level stuff
	this->currency = this->level * 10;
	this->name = name;
	this->level = level;
	this->exp = static_cast<int>(pow(level, 3) + 11);
	this->hpMax = this->level * 8;
	this->hp = this->hpMax;
	this->ppMax = this->level * 5;
	this->pp = this->ppMax;
	this->offense = this->level * 2;
	this->defense = this->level * 2;
	this->iq = this->level * 2;
	this->dropChance = rand() % 100;
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