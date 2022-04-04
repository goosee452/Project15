#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tank {

private:

	string model;
	string country;
	double mass;
	string type;
	double cost;

public:

	Tank() {

		model = "unknown";
		country = "unknown";
		mass = 0;
		type = "unknown";
		cost = 0;

	}

	Tank(string init_model, string init_country, double init_mass, string init_type, double init_cost) {

		model = init_model;
		country = init_country;
		mass = init_mass;
		type = init_type;
		cost = init_cost;

	}

	string info() {

		return "model: " + model + "\n" + "country: " + country + "\n" + "mass: " + to_string(mass) + "\n" + "type: " + type + "\n" + "cost in dollars: " + to_string(cost);
	}

	void setModel(string init_model) {
		model = init_model;
	}

	void setCountry(string init_country) {
		country = init_country;
	}

	void setMass(double init_mass) {
		if (init_mass > 0) {
			mass = init_mass;
		}
	}

	void setType(string init_type) {
		type = init_type;
	}

	void setCost(double init_cost) {
		cost = init_cost;
	}

	~Tank() {

	}
};
