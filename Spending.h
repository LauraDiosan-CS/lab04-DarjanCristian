#pragma once



class Spending
{
private:
	int apartment;
	int price;
	char* type;
public:
	Spending();
	Spending(int apartment, int price, char* type);
	Spending(Spending& s);
	~Spending();
	Spending& operator=(const Spending& s);

	int getApartment();
	int getPrice();
	char* getType();
	void setApartment(int apartment);
	void setPrice(int price);
	void setType(char* type);
	char* toString();
	bool compare(Spending& s);
};