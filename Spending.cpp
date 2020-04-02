#include "Spending.h"
#include <iostream>
#include <string>

using namespace std;

/*
Creates a spending
In: -
Out: an instance of a spending
*/
Spending::Spending()
{
	this->id = 0;
	this->apartment = 0;
	this->price = 0;
	this->type = NULL;
}

/*
Creates a spending
In: Apartment number, price of the spending, type of spending
Out: an instance of a spending with info of a spending
*/
Spending::Spending(int identity, int apartment, int price, char* type)
{
	this->id = identity;
	this->apartment = apartment;
	this->price = price;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

/*
Creates a new Spending (equal to a given spending)
in : s - Spending
out : a new spending (equal to s)
*/
Spending& Spending::operator=(const Spending& s)
{
	this->setId(s.id);
	this->setApartment(s.apartment);
	this->setPrice(s.price);
	this->setType(s.type);

	return *this;
}

/*
Creates a spending using info from another spending
In: a spending "s"
Out an instance of a spending
*/
Spending::Spending(Spending& s)
{
	this->id = s.id;
	this->apartment = s.apartment;
	this->price = s.price;
	this->type = new char[strlen(s.type) + 1];
	strcpy_s(this->type, strlen(s.type) + 1, s.type);
}

/*
Distroys a spending
In: a spending "s"
Out: - Distructor
*/
Spending::~Spending()
{
	if (type)
	{
		delete[] type;
		type = NULL;
	}
}

int Spending::getId()
{
	return this->id;
}

/*
Gets a Apartment form a spending
In: -
Out: apartment number
*/
int Spending::getApartment()
{
	return this->apartment;
}

/*
Gets the price of a spending
In: -
Out: int - Price;
*/
int Spending::getPrice()
{
	return this->price;
}

/*
Gets the Type of a spending
In: -
Out: char* - Type
*/
char* Spending::getType()
{
	return this->type;
}
/*
Sets the apartment to a given apartment
in: the given apartment
out:-
*/
void Spending::setApartment(int apartment)
{
	this->apartment = apartment;
}
/*
Sets the price to a given price
in: the given price
out:-
*/
void Spending::setPrice(int price)
{
	this->price = price;
}
/*
Sets the type to a given type
in: the given type
out:-
*/
void Spending::setType(char* t)
{
	if (this->type != NULL)
	{
		delete[] this->type;
	}
	this->type = new char[strlen(t) + 1];
	strcpy_s(this->type, strlen(t) + 1, t);
}
/*
Sets the id to a given id
in: the given id
out:-
*/
void Spending::setId(int identity)
{
	this->id = identity;
}

/*
Converts a Spending to string
in: the spending
out: char* the spending in string format
*/
char* Spending::toString()
{
	if (this->type != NULL && this->apartment > 0)
	{
		int noChars = strlen(this->type) + 1 + 5 + 5 + 5 + 4;
		char* s = new char[noChars];
		char* aux = new char[5];

		_itoa_s(this->id, aux, 5, 10);
		strcpy_s(s, noChars, aux);
		strcat_s(s, noChars, " ");

		_itoa_s(this->apartment, aux, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, " ");

		_itoa_s(this->price, aux, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, " ");

		strcat_s(s, noChars, this->type);

		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		return s;
	}
	else
	{
		return NULL;
	}
}

/*
compares 2 spendings
in: a spending
out: true or false if this == the given spending
*/
bool Spending::compare(Spending& s)
{
	return ((this->apartment == s.apartment) && (this->price == s.price) && (strcmp(this->type, s.type) == 0));
}

/*
overwrites the << operator
in: a spending
out: prints on the screen
*/
ostream& operator<<(ostream& os, Spending& s)
{
	os << s.id << " -|" << s.apartment << "|" << " -- " << s.price << " => " << s.type;
	return os;
}
