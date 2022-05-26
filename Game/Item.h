#pragma once

#include "STLINCLUDE.h"
#include <iostream>
#include <iomanip>
#include <string>

class Item
{
public:
	Item();
	Item(int stat);
	Item(std::string name,int buyValue, int sellValue, int stat);

	virtual ~Item(); //virtual deconstructor

	inline std::string debugPrint() const { return this->name; }
	virtual Item* clone() const = 0;
	virtual std::string toString() const = 0;

	//Accessors
	inline const std::string& getName() const { return this->name; }
	inline const int& getBuyValue() const { return this->buyValue; }
	inline const int& getSellValue() const { return this->sellValue; }
	inline const int& getStat() const { return this->stat; }

	//Modifiers
	inline void setName(std::string name) { this->name = name; }

	//Static
	static dArr<std::string> names;
	//static void initNames();

private:
	std::string name;
	int buyValue;
	int sellValue;
	int stat;
};
