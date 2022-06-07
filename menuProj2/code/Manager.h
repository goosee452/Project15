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
