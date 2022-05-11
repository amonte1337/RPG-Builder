#include "Armor.h"

//first error with debugging - forgot to pass inheritance :P
Armor::Armor(int defense, std::string name, int level, int buyValue,
	int sellValue, int rarity)
	: Item(name, level, buyValue, sellValue, rarity)
{
	this->defense = defense;
}

Armor::~Armor() //virtual deconstructor
{
	//something is supposed to go here :P
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}

std::string Armor::toString()
{
	std::string str = std::to_string(this->defense);

	return str;
}