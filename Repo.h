#pragma once
#include "Spending.h"


const int MAX_SPENDINGS = 1000;

class Repository
{
public:
	Repository();
	~Repository();
	
	void addElement(Spending spend);
	int getSize();
	Spending* getAll();
private:
	Spending* storage;
	int nbSpendings;
};