#pragma once
#include "Header.h"

class Tank {
private:
	friend class Division;
	string model;
	string country;
	double mass;
	string type;
	double cost;

public:

	    Tank();
	    Tank(string init_model, string init_country, double init_mass, string init_type, double init_cost);
		Tank(Tank &tank);
		void extraConstructor();

	    string info();

		void setModel(string init_model);
		string getModel();
		void setCountry(string init_country);
		string getCountry();
		void setMass(double init_mass);
		double getMass();
		void setType(string init_type);
		string getType();
		void setCost(double init_cost);
		double getCost();

		~Tank();

};
