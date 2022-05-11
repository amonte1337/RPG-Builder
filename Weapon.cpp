#include "Weapon.h"

//first error with debugging - forgot to pass inheritance :P
Weapon::Weapon(int offense, std::string name, int level, int buyValue,
	int sellValue, int rarity)
	: Item(name, level, buyValue, sellValue, rarity)
{
	this->offense = offense;
}

Weapon::~Weapon() //virtual deconstructor
{
	//something is supposed to go here :P
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}

std::string Weapon::toString()
{
	std::string str = std::to_string(this->offense);

	return str;
}