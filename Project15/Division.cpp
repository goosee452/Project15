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

void Division::add(int quantity){
	if (quantity > 0 && tankQuantity >= 0) {

		Tank* tempTanks = new Tank[tankQuantity + quantity];
		for (int count = 0; count < tankQuantity; count++) {
			tempTanks[count] = tanks[count];
		}
		Tank* tanksRemove = tanks;
		tanks = tempTanks;
		delete[] tanksRemove;
		delete tempTanks;
	}
	
}

void Division::remove(int quantity, int place){}

Division::~Division() {
	delete[] tanks;
}