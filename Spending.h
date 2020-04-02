#pragma once
#include <iostream>

using namespace std;

class Spending
{
private:
	int id;
	int apartment;
	int price;
	char* type;
public:
	Spending();
	Spending(int identity, int apartment, int price, char* type);
	Spending(Spending& s);
	~Spending();
	Spending& operator=(const Spending& s);
	friend ostream& operator<<(ostream& os, Spending& s);
	int getId();
	int getApartment();
	int getPrice();
	char* getType();
	void setApartment(int apartment);
	void setPrice(int price);
	void setType(char* type);
	void setId(int identity);
	char* toString();
	bool compare(Spending& s);
};