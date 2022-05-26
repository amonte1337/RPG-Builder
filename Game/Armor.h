#pragma once

#include "STLINCLUDE.h"
#include "Item.h"

class Armor : public Item
{
public:
	Armor();
	Armor(int stat);
	Armor(int defense, std::string name, int buyValue, int sellValue);
	virtual ~Armor(); //virtual deconstructor

	//Pure virtual
	virtual Armor* clone() const;

	//Functions
	std::string toString() const;

	//Accessors
	inline int getDefense() const { return this->defense; }

	//Modifers

	//Static
	static dArr<std::string> names;
	static void initNames();

private:
	int defense;
};
