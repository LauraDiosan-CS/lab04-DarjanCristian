#include <iostream>
#include "Repo.h"

using namespace std;


/*
Creates a repository
In: -
Out: an instance of a repository
*/
Repository::Repository()
{
	this->storage = new Spending[MAX_SPENDINGS];
	this->nbSpendings = 0;
	this->savedSize = 0;
	this->savedStorage = new Spending[MAX_SPENDINGS];
}

/*
Creates a repository from given dated
In: Spending* storage, int size of the storage;
Out: an instance of a spending
*/
Repository::Repository(Spending* storage, int size)
{
	this->storage = storage;
	this->nbSpendings = size;
}

/*
Distroys a repository
in : -
out: Destructor
*/
Repository::~Repository()
{
	if (this->storage != NULL)
	{
		delete[] this->storage;
		this->storage = NULL;
	}
}

/*
Adds a element to the repository
In: Spending :: Spend
Out: -
*/
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

/*
Gets the Size of the Repository
in: -
Out: Int :: size of repository
*/
int Repository::getSize()
{
	return this->nbSpendings;
}


/*
Gets all Spendings
in: -
Out: Spending* :: All Spendings
*/
Spending* Repository::getAll()
{
	return this->storage;
}

Spending Repository::read(Spending spend)
{

	for (int i = 0; i < this->nbSpendings; i++)
	{
		if (spend.getId() == this->storage[i].getId())
		{
			return this->storage[i];
		}
	}
	Spending Exception;
	return Exception;
}

/*
Updates a Sending in the repository
in: Spending
Out: -
*/
void Repository::undo(Spending spend)
{

	for (int i = 0; i < this->nbSpendings; i++)
	{
		if (spend.getId() == this->storage[i].getId())
		{
			this->storage[i] = spend;
		}
	}
}

/*
Deletes a Spending
In: Spending:: spend;
out: -
*/
void Repository::del(Spending spend)
{

	for (int i = 0; i < this->nbSpendings; i++)
	{
		if (spend.getId() == this->storage[i].getId())
		{
			for (; i < this->nbSpendings - 1; i++)
			{
				this->storage[i] = this->storage[i + 1];
			}
			this->nbSpendings--;
			i++;
		}
	}
}

/*
Sets the storafe of the repo.
in: the storage
out: -
*/
void Repository::setStorage(Spending* storage)
{
	this->storage = storage;
}

void Repository::setSize(int size)
{
	this->nbSpendings = size;
}

/*
overloads the =
in: a repository
out: modified repo	
*/
Repository& Repository::operator=(const Repository& s)
{
	this->storage = s.storage;
	this->nbSpendings = s.nbSpendings;

	return *this;
}

void Repository::undo()
{
	Spending* helper = new Spending[MAX_SPENDINGS];
	int size_helper = this->nbSpendings;

	Spending Sp;

	for (int i = 0; i < this->nbSpendings; i++)
	{
		Sp = Spending(this->storage[i].getId(), this->storage[i].getApartment(), this->storage[i].getPrice(), this->storage[i].getType());
		helper[i] = Sp;
	}

	for (int i = 0; i < savedSize; i++)
	{
		Sp = Spending(this->savedStorage[i].getId(), this->savedStorage[i].getApartment(), this->savedStorage[i].getPrice(), this->savedStorage[i].getType());
		this->storage[i] = Sp;
	}

	this->nbSpendings = this->savedSize;

	for (int i = 0; i < size_helper; i++)
	{
		Sp = Spending(helper[i].getId(),helper[i].getApartment(),helper[i].getPrice(),helper[i].getType());
		this->savedStorage[i] = Sp;
	}
	this->savedSize = size_helper;
}

void Repository::remember()
{
	Spending Sp;
	for (int i = 0; i < nbSpendings; i++)
	{
		Sp = Spending(this->storage[i].getId(), this->storage[i].getApartment(), this->storage[i].getPrice(), this->storage[i].getType());
		this->savedStorage[i] = Sp;
	}
	this->savedSize = this->nbSpendings;
}
