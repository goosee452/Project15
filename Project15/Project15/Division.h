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

	void setName(string initName);
	string getName();
	void setTankQuantity(int initTankQuantity);
	int getTankQuantity();
	Tank getTank(int number);
	void setTankProps(int tankNum, string init_model, string init_country, double init_mass, string init_type, double init_cost);
	void copyTankProps(Tank &tank, int tankNum);

	string getInfo();
	string getMembersInfo();

	void add(int quantity);
	void remove( int place);

	~Division();
};