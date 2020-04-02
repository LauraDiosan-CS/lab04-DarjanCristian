#pragma once
#include "Spending.h"
#include <fstream>

const int MAX_SPENDINGS = 1000;

class Repository
{
public:
	Repository();
	Repository(Spending* storage, int size);
	~Repository();

	void addElement(Spending spend);
	int getSize();
	Spending* getAll();
	Spending read(Spending spend);
	void undo(Spending spend);
	void del(Spending spend);
	void setStorage(Spending* storage);
	void setSize(int size);
	Repository& operator=(const Repository& s);

	void undo();
	void remember();
private:
	Spending* storage;
	Spending* savedStorage;
	int nbSpendings, savedSize;
};