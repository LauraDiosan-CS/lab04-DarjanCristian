#include "Spending.h"
#include <string>

using namespace std;

/*
Creates a spending
In: -
Out: an instance of a spending
*/
Spending::Spending()
{
	this->apartment = 0;
	this->price = 0;
	this->type = NULL;
}

/*
Creates a spending
In: Apartment number, price of the spending, type of spending
Out: an instance of a spending with info of a spending
*/
Spending::Spending(int apartment, int price, char* type)
{
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
	if (this != &s)
	{
		this->setApartment(s.apartment);
		this->setPrice(s.price);
		this->setType(s.type);
	}

	return *this;
}

/*
Creates a spending using info from another spending
In: a spending "s"
Out an instance of a spending
*/
Spending::Spending(Spending& s)
{
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
	if (this->type != NULL)
	{
		delete[] this->type;
		this->type = NULL;
	}
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

void Spending::setApartment(int apartment)
{
	this->apartment = apartment;
}

void Spending::setPrice(int price)
{
	this->price = price;
}

void Spending::setType(char* t)
{
	if (this->type)
	{
		delete[] this->type;
	}
	this->type = new char[strlen(t) + 1];
	strcpy_s(this->type, strlen(t) + 1, t);
}

char* Spending::toString()
{
	if (this->type != NULL && this->apartment > 0)
	{
		int noChars = strlen(this->type) + 1 + 5 + 5 + 3;
		char* s = new char[noChars];
		char* aux = new char[5];

		_itoa_s(this->apartment, aux, 5, 10);
		strcpy_s(s, noChars, aux);
		strcat_s(s, noChars, ";");

		_itoa_s(this->price, aux, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, ";");
		
		strcat_s(s, noChars, this->type);

		if (aux) {
			delete[] aux;
			aux = NULL;
		}

		strcat_s(s, noChars, ";");
		
		return s;
	}
	else
	{
		return NULL;
	}
}

bool Spending::compare(Spending& s)
{
	return ((this->apartment == s.apartment) && (this->price == s.price) && (strcmp(this->type, s.type) == 0));
}

