#include "Division.h"





Division::Division() {
	name = "unknown";
	tankQuantity = 0;
}

Division::Division(string initName, int initTankQuantity) {
	name = initName;
	if (initTankQuantity >= 0) {
		tankQuantity = initTankQuantity;
	}

	if (initTankQuantity > 0) {
		tanks = new Tank[initTankQuantity];
	}
}

void Division::setName(string initName) {
	name = initName;
}

string Division::getName() {
	return name;
}

void Division::setTankQuantity(int initTankQuantity) {
	if (initTankQuantity >= 0) {
		tankQuantity = initTankQuantity;
	}
}

int Division::getTankQuantity() {
	return tankQuantity;
}

Tank Division::getTank(int number) {
	return tanks[number];
}

void Division::setTankProps(int tankNum, string init_model, string init_country, double init_mass, string init_type, double init_cost) {

	tanks[tankNum].model = init_model;
	tanks[tankNum].country = init_country;
	tanks[tankNum].mass = init_mass;
	tanks[tankNum].type = init_type;
	tanks[tankNum].cost = init_cost;
}

void Division::copyTankProps(Tank& tank, int tankNum) {

	tanks[tankNum] = tank;

}

string Division::getInfo() {
	return "name: " + name + "\n" + "tank quantity: " + to_string(tankQuantity);
}

string Division::getMembersInfo(){
	string membersInfo = "";
	if(tankQuantity >= 0){
		for (int count = 0; count < tankQuantity; count++) {
			membersInfo += tanks[count].info() + "\n";
		}
	}
	return membersInfo;
}

void Division::add(int quantity){//quantity = quantity of tanks that u add to division

	if (quantity > 0 && tankQuantity >= 0) {

		Tank* tempTanks = new Tank[tankQuantity + quantity];

		if (tankQuantity > 0) {
			for (int count = 0; count < tankQuantity; count++) {
				tempTanks[count] = tanks[count];
			}
		}
	
		
		delete[] tanks;
		tanks = tempTanks;
		tankQuantity += quantity;
	}
	
}

void Division::remove(int place) {

	if ( tankQuantity > 0 && place < tankQuantity && place >= 0) {

	Tank* tempTanks = new Tank[tankQuantity - 1];

	if (tankQuantity > 0) {
		for (int count = 0; count < tankQuantity - 1; count++) {
			if (count != place) {
				tempTanks[count] = tanks[count];
			}
		}
	}


	delete[] tanks;
	tanks = tempTanks;
	tankQuantity -= 1;

    }
}

Division::~Division() {
	delete[] tanks;
}
