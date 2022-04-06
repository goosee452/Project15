#pragma once
#include "Tank.h"




class Division {
private:

	string name;
	int tankQuantity;
	Tank* tanks;

public:

	Division();
	Division(string initName, int initTankQuantity);

	void setName(string initName);
	string getName();
	void setTankQuantity(int initTankQuantity);
	int getTankQuantity();

	string getInfo();
	string getMembersInfo();

	void add(int quantity);
	void remove(int quantity, int place);

	~Division();
};