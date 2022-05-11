#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(int offense = 0, std::string name = "NONE", int level = 0,
		int buyValue = 0, int sellValue = 0, int rarity = 0);

	virtual ~Weapon(); //virtual deconstructor

	//Pure virtual
	virtual Weapon* clone() const;

	//Functions
	std::string toString();

private:
	int offense;
};

