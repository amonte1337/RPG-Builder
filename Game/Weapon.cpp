#include "Weapon.h"

dArr<std::string> Weapon::names;

void Weapon::initNames()
{
	Weapon::names.push("Stick");
	Weapon::names.push("Butter Knife");
	Weapon::names.push("Yo-yo");
	Weapon::names.push("Gloves");
	Weapon::names.push("Durable Shoes");
	Weapon::names.push("Cheddar Shredder");
	Weapon::names.push("Smash Box");
}

Weapon::Weapon()
	:Item()
{
	this->offense = 0;
}

Weapon::Weapon(int stat)
	: Item(stat)
{
	this->offense = stat;
	this->setName(Weapon::names[rand() % Weapon::names.size()]);
}
//first error with debugging - forgot to pass inheritance :P
Weapon::Weapon(int offense, std::string name, int buyValue, int sellValue)
	: Item(name, buyValue, sellValue, offense)
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

std::string Weapon::toString() const
{
	std::string str =
		this->getName() + ' ' + "| Offense: " + std::to_string(this->getOffense());

	return str;
}