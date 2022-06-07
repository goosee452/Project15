#pragma once
#include "Tank.h"




class Division {
	friend class Tank;
private:

	string name;
	int tankQuantity;
	Tank* tanks;

public:

	Division();
	Division(string initName, int initTankQuantity);
	Division(Division& division);
	void extraCopyConstr(Division& division);

	void setName(string initName);
	string getName();
	int getTankQuantity();
	Tank getTank(int number);
	void copyTankProps(Tank &tank, int tankNum);

	string getInfo();
	string getMembersInfo();

	void add(int quantity);
	void remove( int place);

	~Division();
};