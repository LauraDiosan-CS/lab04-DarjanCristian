#include "Tests.h"
#include "Spending.h"
#include "Repo.h"
#include <assert.h>

using namespace std;

/*
Tests Spending Class
*/
void tests_Spending()
{
	Spending Sp;
	Sp.setApartment(10);
	Sp.setPrice(29);
	Sp.setType((char*)"Apa");

	Spending Sp2 = Sp;
	Spending Sp3;
	Sp3 = Sp;
	Sp = Sp;
}

/*
Tests Repository Class
*/
void tests_Repo()
{
	Spending Sp1, Sp2, Sp3;
	Spending* Spendings = new Spending[3];
	Sp1.setApartment(10);
	Sp1.setPrice(29);
	Sp1.setType((char*)"Apa");

	Sp2.setApartment(11);
	Sp2.setPrice(124);
	Sp2.setType((char*)"Gaz");

	Sp3.setApartment(10);
	Sp3.setPrice(23);
	Sp3.setType((char*)"Curent");

	Repository repo;

	repo.addElement(Sp1);
	repo.addElement(Sp2);
	repo.addElement(Sp3);

	assert(repo.getSize() == 3);
	Spendings = repo.getAll();

	assert(Spendings[0].compare(Sp1));
	assert(Spendings[1].compare(Sp2));
	assert(Spendings[2].compare(Sp3));
}
