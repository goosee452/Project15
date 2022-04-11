#include "Tank.h"





Tank::Tank() {

	model = "unknown";
	country = "unknown";
	mass = 0;
	type = "unknown";
	cost = 0;

}

Tank::Tank(string init_model, string init_country, double init_mass, string init_type, double init_cost) {

	model = init_model;
	country = init_country;
	mass = init_mass;
	type = init_type;
	cost = init_cost;

}

Tank::Tank(Tank& tank) {

	model = tank.model;
	country = tank.country;
	mass = tank.mass;
	type = tank.type;
	cost = tank.cost;

}

void Tank::extraConstructor() {

	model = "unknown";
	country = "unknown";
	mass = 0;
	type = "unknown";
	cost = 0;

}

string Tank::info() {

	return "model: " + model + "\n" + "country: " + country + "\n" + "mass: " + to_string(mass) + "\n" + "type: " + type + "\n" + "cost in dollars: " + to_string(cost);
}

void Tank::setModel(string init_model) {
	model = init_model;
}

string Tank::getModel() {
	return model;
}

void Tank::setCountry(string init_country) {
	country = init_country;
}

string Tank::getCountry() {
	return country;
}

void Tank::setMass(double init_mass) {
	if (init_mass > 0) {
		mass = init_mass;
	}
}

double Tank::getMass() {
	return mass;
}

void Tank::setType(string init_type) {
	type = init_type;
}

string Tank::getType() {
	return type;
}

void Tank::setCost(double init_cost) {
	cost = init_cost;
}

double Tank::getCost() {
	return cost;
}

Tank::~Tank() {

}