#include "Service.h"
#include "Repo.h"
#include "Spending.h"
#include <iostream>

using namespace std;

Service::Service()
{
	this->spends = new Spending[MAX_SPENDINGS];
	this->size = 0;
}
Service::~Service()
{
	delete[] this->spends;
	this->spends = NULL;
}

/*
Adds a element to the repository
In: int:: id, apartment, price;
	Char*:: type
Out: -
*/
void Service::add(int id, int apartment, int price, char* type)
{

	Spending newSpending;
	newSpending.setId(id);
	newSpending.setApartment(apartment);
	newSpending.setPrice(price);
	newSpending.setType(type);
	this->repo.addElement(newSpending);
}

/*
Updates a Sending in the repository
in: int:: identity, apartment, price;
	Char*:: type;
Out: -
*/
void Service::update(int identity, int apartment, int price, char* type)
{
	Spending* spendings = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (spendings[i].getId() == identity)
		{
			Spending Spend;
			Spend = spendings[i];

			Spend.setApartment(apartment);
			
			Spend.setPrice(price);
			
			Spend.setType(type);
			
			repo.undo(Spend);
		}
	}
}
/*
Deletes a Spending
In: int:: identity;
out: -
*/
void Service::remove(int identity)
{
	Spending* spendings = this->repo.getAll();
	int lenght = this->repo.getSize();
	for (int i = 0; i < lenght; i++)
	{
		if (spendings[i].getId() == identity)
		{
			this->repo.del(spendings[i]);
			i = lenght;
		}
	}
}

/*
Gets all Spendings from repo
in: - 
out: All spendings
*/
Spending* Service::getAll()
{
	return this->repo.getAll();
}
/*
Gets the size of the repo
in: -
out: int :: the size
*/
int Service::getSize()
{
	return this->repo.getSize();
}

/*
deletes all spendings of a apartment
in: the apartment
out:-
*/
void Service::deleteByApartment(int apartment)
{
	Spending* spendings = this->repo.getAll();

	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (spendings[i].getApartment() == apartment)
		{
			this->repo.del(spendings[i]);
		}
	}
}

/*
deletes all spendings that have this type;
in: type
out: -
*/
void Service::deleteByType(char* type)
{
	Spending* spendings = this->repo.getAll();

	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (strcmp(spendings[i].getType(), type) == 0)
		{
			this->repo.del(spendings[i]);
			if (i > 0)
			{
				i--;
			}
		}
	}
}
/*
calculates the sum of all Spendings that have this type;
in: the type
out: int: the sum;
*/
int Service::sumByType(char* type)
{
	Spending* spend = this->repo.getAll();
	int sum = 0;

	for (int i = 0; i < this->getSize(); i++)
	{
		if (!(strcmp(spend[i].getType(), type)))
		{
			sum += spend[i].getPrice();
		}
	}
	return sum;
}

/*
calculates the sum of all Spendings that have this apartment;
in: the type
out: int: the sum;
*/
int Service::sumByAp(int apartment)
{
	Spending* spend = this->repo.getAll();
	int sum = 0;

	for (int i = 0; i < this->getSize(); i++)
	{
		if (spend[i].getApartment() == apartment)
		{
			sum += spend[i].getPrice();
		}
	}
	return sum;
}

/*
gets the most expensive Spending that have this apartment
in: the apartment
out: Spending 
*/
Spending Service::maxAp(int apartment)
{
	Spending* spend = this->repo.getAll();
	Spending max;

	for (int i = 0; i < this->getSize(); i++)
	{
		if (spend[i].getApartment() == apartment)
		{
			if (spend[i].getPrice() > max.getPrice())
			{
				max = spend[i];
			}
		}
	}
	return max;
}

Spending* Service::getType(char* type, int& size)
{
	Spending* spendings_type = new Spending[MAX_SPENDINGS];
	Spending* spends = this->getAll();
	size = 0;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (!strcmp(spends[i].getType(), type))
		{
			spendings_type[size++] = spends[i];
		}
	}
	return spendings_type;
}

Spending* Service::sortedType(char* type, int& size)
{
	Spending* spends = this->getType(type, size);
	Spending helper;
	int rmbSize = size;
	bool sorted = true;

	while (sorted)
	{
		sorted = false;
		for (int i = 0; i < size-1 ; i++)
		{
			if (spends[i].getPrice() < spends[i + 1].getPrice())
			{
				helper = spends[i];
				spends[i] = spends[i + 1];
				spends[i + 1] = helper;

				sorted = true;
				size--;
			}
		}
	}
	size = rmbSize;
	return spends;
}

Spending* Service::getPrice(int price, int& size)
{
	Spending* spendings_price = new Spending[MAX_SPENDINGS];
	Spending* spends = this->getAll();
	size = 0;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (spends[i].getPrice() < price)
		{
			spendings_price[size++] = spends[i];
		}
	}
	return spendings_price;
}

void Service::undo()
{
	this->repo.undo();
}

void Service::remember()
{
	this->repo.remember();
}
