#pragma once

#include "STLINCLUDE.h"
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(int stat);
	Weapon(int offense, std::string name, int buyValue, int sellValue);
	virtual ~Weapon(); //virtual deconstructor

	//Pure virtual
	virtual Weapon* clone() const;

	//Functions
	std::string toString() const;


	//Accessors
	inline int getOffense() const { return this->offense; }

	//Modifers

	//Static
	static dArr<std::string> names;
	static void initNames();

private:
	int offense;
};

