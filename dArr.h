#pragma once

template<typename T>
class dArr
{
private:
	unsigned cap;
	unsigned intialCap;
	unsigned numOfElements;
	T** arr;

	void expand();
	void initialize(unsigned from);

public:
	dArr(unsigned size = 5);
	dArr(const dArr& obj);
	~dArr();

	T& operator[] (const unsigned index);
	void operator= (const dArr & obj);

	unsigned maxCap();
	unsigned size();
	void push(const T element);
	void remove(const unsigned index, bool ordered = false);

};

template<typename T>
dArr<T>::dArr(unsigned size)
{
	this->intialCap = size;
	this->cap = size;
	this->numOfElements = 0;

	this->arr = new T* [this->cap];

	this->initialize(0);
}

template<typename T>
dArr<T>::dArr(const dArr& obj) 
{
	this->intialCap = obj.intialCap;
	this->cap = obj.cap;
	this->numOfElements = obj.numOfElements;

	this->arr = new T * [this->cap];

	for (size_t i = 0; i < this->numOfElements; i++)
	{
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->initialize(0);
}

template<typename T>
dArr<T>::~dArr()
{
	for (size_t i = 0; i < this->numOfElements; i++)
	{
		//deleting everything the fingers point to
		delete this->arr[i];
	}

	//deleting the hand
	delete[] arr;
}

template<typename T>
T& dArr<T>::operator[] (const unsigned index)
{
	if (index < 0 || index >= this->numOfElements)
	{
		throw("Out of bounds for indexing operator.");
	}

	return *this->arr[index];
}

template<typename T>
void dArr<T>::operator = (const dArr& obj)
{
	for (size_t i = 0; i < this->numOfElements; i++)
	{
		//deleting everything the fingers point to
		delete this->arr[i];
	}

	//deleting the hand
	delete[] arr;

	this->intialCap = obj.intialCap;
	this->cap = obj.cap;
	this->numOfElements = obj.numOfElements;

	this->arr = new T * [this->cap];

	for (size_t i = 0; i < this->numOfElements; i++)
	{
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->initialize(0);
}

template<typename T>
void dArr<T>::expand()
{
	this->cap *= 2;
	T** tempArr = new T * [this->cap];

	for (size_t i = 0; i < this->numOfElements; i++)
	{
		tempArr[i] = this->arr[i];
	}

	delete[] this->arr;

	this->arr = tempArr;
	this->initialize(this->numOfElements);
}

template<typename T>
void dArr<T>::initialize(unsigned from)
{
	for (size_t i = from; i < this->cap; i++)
	{
		this->arr[i] = nullptr;
	}
}

template<typename T>
unsigned dArr<T>::maxCap()
{
	return this->cap;
}

template<typename T>
unsigned dArr<T>::size()
{
	return this->numOfElements;
}

template<typename T>
void dArr<T>::push(const T element)
{
	if (this->numOfElements >= this->cap)
	{
		this->expand();
	}

	this->arr[this->numOfElements++] = new T(element);
}

template<typename T>
void dArr<T>::remove(const unsigned index, bool ordered)
{
	if (index < 0 || index >= this->numOfElements)
	{
		throw("Out of bounds remove.");
	}

	if (ordered)
	{
		delete this->arr[index];

		for (size_t i = 0; i < this->numOfElements - 1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}

		this->arr[--numOfElements] = nullptr;
	}

	else
	{
		delete this->arr[index];

		this->arr[index] = this->arr[this->numOfElements - 1];
		this->arr[--this->numOfElements] = nullptr;
	}
}