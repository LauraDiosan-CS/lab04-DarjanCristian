#include <fstream>
#include <iostream>
#include "Repo.h"

using namespace std;

Repository::Repository()
{
	this->storage = new Spending[MAX_SPENDINGS];
	this->nbSpendings = 0;
}

Repository::~Repository()
{
	if (this->storage != NULL)
	{
		delete[] this->storage;
		this->storage = NULL;
	}
}

void Repository::addElement(Spending spend)
{
	if (this->nbSpendings == MAX_SPENDINGS)
	{
		Spending* auxStorage = new Spending[2 * MAX_SPENDINGS];
		for (int i = 0; i < this->nbSpendings; i++)
		{
			auxStorage[i] = this->storage[i];
		}
		this->storage = auxStorage;
	}
	this->storage[nbSpendings++] = spend;
}

int Repository::getSize()
{
	return this->nbSpendings;
}

Spending* Repository::getAll()
{
	return this->storage;
}