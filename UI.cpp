#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

/*
displys the menu
in:-
out:-
*/
void UI::displayMenu()
{
	cout << "1. Scrie \"add {{id}} {{apartment}} {{Price}} {{type}}\" pentru a adauga o cheltuiala\n";

	cout << "2. Scrie \"show_all\" pentru a afisa totate cheltuielile\n";

	cout << "3. Scrie \"update {{id}} {{newApartment}} {{newPrice}} {{newType}}\" pentru a updata cheltuiala cu id-ul {{id}}\n";

	cout << "4. Scrie \"delete_id {{id}}\" pentru a sterge cheltuiala cu id-ul {{id}}\n";

	cout << "5. Scrie \"delete_apartment {{apartment}}\" pentru a sterge cheltuielile apartamentului {{apartment}}\n";

	cout << "6. Scrie \"delete_aps {{apartment1}} {{apartment2}}\" pentru a sterge cheltuielile apartamentelor de la {{apartment1}} la {{apartment2}}\n";

	cout << "7. Scrie \"delete_type {{type}}\" pentru a sterge cheltuielile de tipul {{type}}\n";

	cout << "8. Scrie \"show_ap {{apartment}}\" pentru a afisa toate cheltuielile apartamentului {{apartment}}\n";

	cout << "8. Scrie \"show_prices {{ '>' or '<' or '=' }} {{price}}\" pentru a afisa toate cheltuielile cu pretul {{ '>' or '<' or '=' }} decat {{price}}\n";

	cout << "9. Scrie \"filter_type {{type}}\" pentru a afisa toate cheltuielile de tip {{type}}\n";

	cout << "10. Scrie \"filter_price {{price}}\" pentru a afisa toate cheltuielile mai mici decat {{price}}\n";

	cout << "9. Scrie \"sort_type {{type}}\" pentru a afisa toate cheltuielile de tip {{type}} sortate\n";

	cout << "10  Scrie \"auto_show \" pentru a afisa toate cheltuielile automat dupa fiecare comanda\n";

	cout << "x. Scrie\"exit\" pentru a inchide aplicatia\n\n";

	cout << "\nGive option: \n";

}

/*
handles adding a new element
in:the command
out:-
*/
void UI::uiAddSpending(string cmd)
{
	this->service.remember();
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int id = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int price = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.add(id, apartment, price, type);
	delete[] type;
}

/*
shows all elements of the repository
in:the command
out:-
*/
void UI::uiShowAll()
{
	Spending* spend = this->service.getAll();
	int size = this->service.getSize();
	for (int i = 0; i < size; i++)
	{
		cout << spend[i] << "\n";
	}
	cout << "\n";
}

/*
handles updateing a element
in:the command
out:-
*/
void UI::uiUpdate(string cmd)
{
	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int id = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int price = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.update(id, apartment, price, type);
	delete[] type;
}

/*
handles deleting all elements that have the same apartment
in:the command
out:-
*/
void UI::uiDeleteByApartment(string cmd)
{
	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment = stoi(token);

	this->service.deleteByApartment(apartment);
}

/*
handles deleting a Spending form repository by the id
in:the command
out:-
*/
void UI::uiDeleteId(string cmd)
{

	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int id = stoi(cmd);

	this->service.remove(id);
}

void UI::uiDeleteAps(string cmd)
{
	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment1 = stoi(token);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment2 = stoi(token);

	for (int i = apartment1; i <= apartment2; i++)
	{
		this->service.deleteByApartment(i);
	}
}

void UI::uiDeleteType(string cmd)
{
	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.deleteByType(type);
	delete[] type;
}

void UI::uiShowAp(string cmd)
{
	Spending* spend = this->service.getAll();
	int size = this->service.getSize();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment = stoi(token);

	for (int i = 0; i < size; i++)
	{
		if(spend[i].getApartment() == apartment)
			cout << spend[i] << "\n";
	}
	cout << "\n";
}

void UI::uiShowRulePrice(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* rule = new char[token.length() + 1];
	strcpy_s(rule, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int price = stoi(token);

	Spending* spend = this->service.getAll();
	int size = this->service.getSize();

	if ( !( strcmp(rule, ">") ) )
	{
		for (int i = 0; i < size; i++)
		{
			if (spend[i].getPrice() > price)
				cout << spend[i] << "\n";
		}
		cout << "\n";
	}

	if (!(strcmp(rule, "=")))
	{
		for (int i = 0; i < size; i++)
		{
			if (spend[i].getPrice() == price)
				cout << spend[i] << "\n";
		}
		cout << "\n";
	}

	if (!(strcmp(rule, "<")))
	{
		for (int i = 0; i < size; i++)
		{
			if (spend[i].getPrice() < price)
				cout << spend[i] << "\n";
		}
		cout << "\n";
	}
	delete[] rule;
}

void UI::uiSumType(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	int sum = this->service.sumByType(type);
	cout << "Suma : " << sum << "\n";
	delete[] type;
}

void UI::uiSumApartment(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment = stoi(token);

	int sum = this->service.sumByAp(apartment);
	cout << "Suma : " << sum << "\n";
}

void UI::uiMaxApartment(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int apartment = stoi(token);

	cout << "Cela mai mare cheltuiala :" << this->service.maxAp(apartment).toString();
}

void UI::uiFilterType(string cmd)
{
	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	Spending* spend = this->service.getAll();

	for (int i = 0; i < this->service.getSize(); i++)
	{
		if (!(strcmp(spend[i].getType(), type) == 0))
		{
			this->service.remove(spend[i].getId());
			if (i > 0)
			{
				i--;
			}
		}
	}
	delete[] type;
}

void UI::uiSortedType(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	int size = 0;
	Spending* spends = this->service.sortedType(type, size);

	for (int i = 0; i < size; i++)
	{
		cout << spends[i] << "\n";
	}
	delete[] type;
}

void UI::uiFilterPrice(string cmd)
{
	this->service.remember();

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int price = stoi(token);

	Spending* spends = this->service.getAll();

	for (int i = 0; i < this->service.getSize(); i++)
	{
		if (!(spends[i].getPrice() < price))
		{
			this->service.remove(spends[i].getId());
			if (i > 0)
			{
				i--;
			}
		}
	}
}

void UI::runUI()
{
	bool shouldRun = true, auto_print = false;
	string cmd;
	while (shouldRun)
	{
		cout << "\nGive option: \n";
		getline(cin, cmd);
		cout << "\n";
		if (cmd.find("info") != string::npos)
		{
			this->displayMenu();
		}
		if (cmd.find("add") != string::npos)
		{
			this->uiAddSpending(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("show_ap") != string::npos)
		{
			this->uiShowAp(cmd);
		}
		if (cmd.find("show_all") != string::npos)
		{
			this->uiShowAll();
		}
		if (cmd.find("show_prices") != string::npos)
		{
			this->uiShowRulePrice(cmd);
		}
		if (cmd.find("update") != string::npos)
		{
			this->uiUpdate(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("delete_apartment") != string::npos)
		{
			this->uiDeleteByApartment(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("delete_id") != string::npos)
		{
			this->uiDeleteId(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("exit") != string::npos)
		{
			shouldRun = false;
		}
		if (cmd.find("delete_aps") != string::npos)
		{
			this->uiDeleteAps(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("delete_type") != string::npos)
		{
			this->uiDeleteType(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("sum_type") != string::npos)
		{
			this->uiSumType(cmd);

		}
		if (cmd.find("sum_ap") != string::npos)
		{
			this->uiSumApartment(cmd);
		}
		if (cmd.find("max_ap") != string::npos)
		{
			this->uiMaxApartment(cmd);
		}
		if (cmd.find("filter_type") != string::npos)
		{
			this->uiFilterType(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("filter_price") != string::npos)
		{
			this->uiFilterPrice(cmd);
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("sort_type") != string::npos)
		{
			this->uiSortedType(cmd);
		}
		if (cmd.find("undo") != string::npos)
		{
			this->service.undo();
			if (auto_print)
			{
				this->uiShowAll();
			}
		}
		if (cmd.find("auto") != string::npos)
		{
			auto_print = !auto_print;
		}
	}
}