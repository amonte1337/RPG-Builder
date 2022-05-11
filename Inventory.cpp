#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 12;
	this->numOfItems = 0;
	this->itemArr = new Item*[capacity];
	this->initialize();
}

Inventory::~Inventory() //virtual deconstructor
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

Inventory::Inventory(const Inventory& obj) //copy constructor
{
	this->capacity = obj.capacity;
	this->numOfItems = obj.numOfItems;
	this->itemArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->numOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initialize(this->numOfItems);
}

Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->numOfItems)
		throw("Bad Index.");

	return *this->itemArr[index];
}

void Inventory::addItem(const Item& item)
{
	if (this->numOfItems >= this->capacity)
	{
		expand();
	}

	this->itemArr[this->numOfItems++] = item.clone();
}

void Inventory::removeItem(int index)
{

}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArr[i] = nullptr;
	}
}


void Inventory::expand()
{
	//if inventory reaches maximum capacity, 
	//and an item is suddenly added
	//the inventory will expand and double in size

	this->capacity *= 2;

	Item** tempArr = new Item* [this->capacity];

	for (size_t i = 0; i < numOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;

	//returns back to number of items
	this->initialize(this->numOfItems);
}
