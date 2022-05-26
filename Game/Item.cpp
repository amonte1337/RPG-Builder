#include "Item.h"

Item::Item()
{
	this->name = "EMPTY";
	this->buyValue = 0;
	this->sellValue = 0;
	this->stat = 0;
}

Item::Item(int stat)
{
	this->name = "random";
	this->buyValue = 50;
	this->sellValue = this->buyValue / 2;
}

Item::Item(std::string name, int buyValue, int sellValue, int stat)
{
	this->name = name;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
}

Item::~Item()
{
	//something is supposed to go here :P
}