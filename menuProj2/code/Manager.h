#pragma once
#include "Division.h"

Division *addDivisions(int quantity, Division* divisions, int divisionsQuant) {//quantity = quantity of divisions that u add to division

	if (quantity > 0 && divisionsQuant > 0) {

		Division* tempDivisions = new Division[divisionsQuant + quantity];
		for (int count = 0; count < divisionsQuant; count++) {
			//tempDivisions[count] = divisions[count];
			tempDivisions[count].extraCopyConstr(divisions[count]);
		}

		delete[] divisions;
		return tempDivisions;
	}
	else if(quantity > 0 && divisionsQuant == 0) {
		Division* tempDivisions = new Division[quantity];
		return tempDivisions;
	}
}


Division *removeDivision(int place, int divisionsQuant, Division* divisions) {

	if (place >= 0 && place < divisionsQuant && divisionsQuant > 0) {

		Division* tempDivisions = new Division[divisionsQuant - 1];
		int tempDivisionsNum = 0;

		for (int count = 0; count < divisionsQuant; count++) {
			if (count != place) {
				tempDivisions[tempDivisionsNum].extraCopyConstr(divisions[count]);
				tempDivisionsNum++;
			}
		}

		delete[] divisions;
		return tempDivisions;
	}
	return divisions;
}


Division* findByName(string name, Division* divisions, int divisionsQuant) {
	if (divisionsQuant > 0) {

		Division* temp = new Division[divisionsQuant];
		int currNum = 0;

		for (int i = 0; i < divisionsQuant; i++) {
			if (divisions[i].getName() == name) {
				temp[currNum].extraCopyConstr(divisions[i]);
				currNum++;
			}
		}
		int b = 0;
		for (int i = currNum; i < divisionsQuant; i++) {
			if (divisions[b].getName() != name) {
				temp[i].extraCopyConstr(divisions[b]);
				b++;
			}
			else {
				i--;
				b++;
			}
		}

		delete[]divisions;
		return temp;
	}
	return divisions;
}

void sortTanksByCost(Division &division) {

	if (division.getTankQuantity() > 0) {
		Tank temp;
		int min = division.getTank(0).getCost();
		int tankWithMinCostNumber = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {
			min = division.tanks[i].getCost();
			for (int b = i; b < division.getTankQuantity(); b++) {
				if (division.tanks[b].getCost() < min) {
					min = division.tanks[b].getCost();
					tankWithMinCostNumber = b;
				}
			}
			temp = division.tanks[i];
			division.tanks[i] = division.tanks[tankWithMinCostNumber];
			division.tanks[tankWithMinCostNumber] = temp;
		}
	}
}


void sortTanksByMass(Division& division) {

	if (division.getTankQuantity() > 0) {
		Tank temp;
		int min = division.getTank(0).getMass();
		int tankWithMinMassNumber = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {
			min = division.tanks[i].getMass();
			for (int b = i; b < division.getTankQuantity(); b++) {
				if (division.tanks[b].getMass() < min) {
					min = division.tanks[b].getMass();
					tankWithMinMassNumber = b;
				}
			}
			temp = division.tanks[i];
			division.tanks[i] = division.tanks[tankWithMinMassNumber];
			division.tanks[tankWithMinMassNumber] = temp;
		}
	}
}


void findTanksByModel(string model, Division &division) {
	if (division.getTankQuantity() > 0) {

		Tank temp;
		int currNum = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {

			if (division.tanks[i].getModel() == model) {
				temp = division.tanks[currNum];
				division.tanks[currNum] = division.tanks[i];
				division.tanks[i] = temp;
				currNum++;
			}
		}
	}
}

void findTanksByCountry(string country, Division& division) {
	if (division.getTankQuantity() > 0) {

		Tank temp;
		int currNum = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {

			if (division.tanks[i].getCountry() == country) {
				temp = division.tanks[currNum];
				division.tanks[currNum] = division.tanks[i];
				division.tanks[i] = temp;
				currNum++;
			}
		}
	}
}

void findTanksByType(string type, Division& division) {
	if (division.getTankQuantity() > 0) {

		Tank temp;
		int currNum = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {

			if (division.tanks[i].getType() == type) {
				temp = division.tanks[currNum];
				division.tanks[currNum] = division.tanks[i];
				division.tanks[i] = temp;
				currNum++;
			}
		}
	}
}

void findTanksByCostDiapason(double minBorder, double maxBorder, Division& division) {
	if (division.getTankQuantity() > 0) {

		Tank temp;
		int currNum = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {

			if (division.tanks[i].getCost() >= minBorder && division.tanks[i].getCost() <= maxBorder) {
				temp = division.tanks[currNum];
				division.tanks[currNum] = division.tanks[i];
				division.tanks[i] = temp;
				currNum++;
			}
		}
	}
}

void findTanksByMassDiapason(double minBorder, double maxBorder, Division& division) {
	if (division.getTankQuantity() > 0) {

		Tank temp;
		int currNum = 0;

		for (int i = 0; i < division.getTankQuantity(); i++) {

			if (division.tanks[i].getMass() >= minBorder && division.tanks[i].getMass() <= maxBorder) {
				temp = division.tanks[currNum];
				division.tanks[currNum] = division.tanks[i];
				division.tanks[i] = temp;
				currNum++;
			}
		}
	}
}