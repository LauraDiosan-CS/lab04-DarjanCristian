#pragma once
#include <iostream>
#include "Spending.h"
#include "Repo.h"

class Service
{
public:
	Service();
	~Service();

	void add(int id, int apartment, int price, char* type);
	void update(int identity, int apartment, int price, char* type);
	void remove(int identity);
	Spending* getAll();
	int getSize();
	void deleteByApartment(int apartment);
	void deleteByType(char* type);
	int sumByType(char* type);
	int sumByAp(int apartment);
	Spending maxAp(int apartment);
	Spending* getType(char* type, int& size);
	Spending* sortedType(char* type, int& size);
	Spending* getPrice(int price, int& size);

	void setSpends(Spending* s);
	Spending* getSpends();

	void undo();
	void remember();
private:
	Repository repo;
	Spending* spends;
	int size;
};