#include "Division.h"





Division::Division() {
	name = "unknown";
	tankQuantity = 0;
	tanks = NULL;
}

Division::Division(string initName, int initTankQuantity) {
	name = initName;
	if (initTankQuantity >= 0) {
		tankQuantity = initTankQuantity;
	}

	if (initTankQuantity > 0) {
		tanks = new Tank[initTankQuantity];
	}
	else {
		tanks = NULL;
	}
}

Division::Division(Division& division) {
	if (division.getTankQuantity() > 0) {
		Tank* tempTanks = new Tank[division.getTankQuantity()];
		for (int count = 0; count < division.getTankQuantity(); count++) {
			tempTanks[count] = division.getTank(count);
		}
		if (tankQuantity > 0) {
			delete[] tanks;
		}
		tanks = tempTanks;
	}
	else if (division.getTankQuantity() == 0 && tankQuantity > 0) {
		delete[] tanks;
	}

	name = division.getName();
	tankQuantity = division.getTankQuantity();
}


void Division::extraCopyConstr(Division& division) {
	if (division.getTankQuantity() > 0) {
		Tank* tempTanks = new Tank[division.getTankQuantity()];
		for (int count = 0; count < division.getTankQuantity(); count++) {
			tempTanks[count] = division.getTank(count);
		}
		if (tankQuantity > 0) {
			delete[] tanks;
		}
		tanks = tempTanks;
	}
	else if (division.getTankQuantity() == 0 && tankQuantity > 0) {
		delete[] tanks;
	}

	name = division.getName();
	tankQuantity = division.getTankQuantity();
}


void Division::setName(string initName) {
	name = initName;
}

string Division::getName() {
	return name;
}

int Division::getTankQuantity() {
	return tankQuantity;
}

Tank Division::getTank(int number) {
	return tanks[number];
}

void Division::copyTankProps(Tank& tank, int tankNum) {

	tanks[tankNum] = tank;

}

string Division::getInfo() {
	return "name: " + name + "\n" + "tank quantity: " + to_string(tankQuantity);
}

string Division::getMembersInfo(){
	string membersInfo = "";
	if(tankQuantity > 0){
		for (int count = 0; count < tankQuantity; count++) {
			membersInfo += tanks[count].info() + "\n";
		}
	}
	return membersInfo;
}

void Division::add(int quantity){//quantity = quantity of tanks that u add to division

	if (quantity > 0 && tankQuantity > 0) {

		Tank* tempTanks = new Tank[tankQuantity + quantity];

		if (tankQuantity > 0) {
			for (int count = 0; count < tankQuantity; count++) {
				tempTanks[count] = tanks[count];
			}
		}
	
		delete[] tanks;
		tanks = tempTanks;
	}
	else if (quantity > 0 && tankQuantity == 0) {
		tanks = new Tank[quantity];
	}
	tankQuantity += quantity;
}


void Division::remove(int place) {

	if (tankQuantity > 0 && place < tankQuantity && place >= 0) {

		Tank* tempTanks = new Tank[tankQuantity - 1];
		int tempTankNum = 0;

		for (int count = 0; count < tankQuantity; count++) {
			if (count != place) {
				tempTanks[tempTankNum] = tanks[count];
				tempTankNum++;
			}
		}

		delete[] tanks;
		tanks = tempTanks;
		tankQuantity -= 1;

	}
}

Division::~Division() {
	if (tankQuantity > 0) {
      delete[] tanks;
	}
	/*else {
		delete tanks;
	}*/
}