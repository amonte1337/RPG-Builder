#pragma once
#include "Item.h"

class Armor : public Item
{
public:

	Armor(int defense = 0, std::string name = "NONE", int level = 0,
		int buyValue = 0, int sellValue = 0, int rarity = 0);

	virtual ~Armor(); //virtual deconstructor

	//Pure virtual
	virtual Armor* clone() const;

	//Functions
	std::string toString();

	//Accessors
	inline int getDefense() const { return this->defense; }

	//Modifers


private:
	int defense;
};
