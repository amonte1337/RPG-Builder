#include "Armor.h"

dArr<std::string> Armor::names;

void Armor::initNames()
{
	Armor::names.push("Mini-Mini Charm");
	Armor::names.push("Unisex Bandana");
	Armor::names.push("Red Ribbon");
	Armor::names.push("Good Kid Shirt");
	Armor::names.push("Cow Hat");
}

Armor::Armor()
	:Item()
{
	this->defense = 0;
}

//first error with debugging - forgot to pass inheritance :P
Armor::Armor(int defense, std::string name, int buyValue, int sellValue)
	: Item(name, buyValue, sellValue, defense)
{
	this->defense = defense;
}

Armor::Armor(int stat)
	: Item(stat)
{
	this->defense = stat;
	this->setName(Armor::names[rand() % Armor::names.size()]);
}

Armor::~Armor() //virtual deconstructor
{
	//something is supposed to go here :P
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}

std::string Armor::toString() const
{
	std::string str = 
		this->getName() + ' ' + "| Defense: " + std::to_string(this->getDefense());

	return str;
}