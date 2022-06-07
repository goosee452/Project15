#include "Tank.h"
#include "Division.h"
#include "UI.h"
#include "Manager.h"

#define ClOSE_BUTTON 120
//MAIN ACTION LIST = MACTL
#define OPEN_MACTL_BUTTON 97
#define OPEN_DIVISION_LIST_MACTL_BUTTON 97
#define ENTER_BUTTON 13
#define HOME_BUTTON 75
#define END_BUTTON 77
#define NONE 0
int main() {

	cout << getStartScreen();
	system("pause");
	system("cls");

	int cursorPos = 0;
	int actionCursorPos = 0;
	int buttonSymbolValue = 0;

	const int MACTLactionNamesQuant = 3;
	string MCATLactionNames[MACTLactionNamesQuant]{ "add member", "set name", "remove tank"};

	const int tanksActionListQuant = 5;
	string tanksActionListNames[tanksActionListQuant]{ "set model", "set country", "set mass", "set type", "set cost" };

	const int divisionListMACTLnamesQuant = 2;
	string divisionListMACTLnames[divisionListMACTLnamesQuant]{ "add", "remove"};

	int divisionListCursorPos = 0;
	int divisionsQuant = 0;
	Division* divisions = NULL;

	

	while (buttonSymbolValue != ClOSE_BUTTON) {
		
		cout << getMembersList(divisions, divisionsQuant, divisionListCursorPos);
		buttonSymbolValue = _getch();
		divisionListCursorPos = setCursorPos(buttonSymbolValue, divisionListCursorPos, 0, divisionsQuant);
		system("cls");

		actionCursorPos = 0;

		if (buttonSymbolValue == OPEN_DIVISION_LIST_MACTL_BUTTON) {
			while (buttonSymbolValue != ClOSE_BUTTON && buttonSymbolValue != HOME_BUTTON) {

				cout << getMembersList(divisions, divisionsQuant, divisionListCursorPos);
				cout << getActionList(divisionListMACTLnames, actionCursorPos, divisionListMACTLnamesQuant);
				buttonSymbolValue = _getch();
				actionCursorPos = setCursorPos(buttonSymbolValue, actionCursorPos, 0, divisionListMACTLnamesQuant);
				system("cls");

				if (buttonSymbolValue == ENTER_BUTTON) {
					switch (actionCursorPos) {
					case 0: {
						int quantity;
						cout << "\nenter quantity: ";
						cin >> quantity;
						if (quantity > 0) {
							divisions = addDivisions(quantity, divisions, divisionsQuant);
						}
						divisionsQuant += quantity;
						break;
					}
					case 1: {
						int place;
						cout << "\nenter place: ";
						cin >> place;
						if (divisionsQuant > 0 && place < divisionsQuant && place >= 0) {
							divisions = removeDivision(place, divisionsQuant, divisions);
							divisionsQuant -= 1;
						}
						break;
					}
					}
					system("cls");
				}
			}
		}

		else if (buttonSymbolValue == END_BUTTON && divisionsQuant > 0) {
			while (buttonSymbolValue != ClOSE_BUTTON && buttonSymbolValue != HOME_BUTTON) {

				cout << getMembersList(divisions[divisionListCursorPos], cursorPos);
				buttonSymbolValue = _getch();
				cursorPos = setCursorPos(buttonSymbolValue, cursorPos, 0, divisions[divisionListCursorPos].getTankQuantity());
				system("cls");

				actionCursorPos = 0;

				if (buttonSymbolValue == OPEN_MACTL_BUTTON) {
					while (buttonSymbolValue != ClOSE_BUTTON && buttonSymbolValue != HOME_BUTTON) {

						cout << getMembersList(divisions[divisionListCursorPos], cursorPos);
						cout << getActionList(MCATLactionNames, actionCursorPos, MACTLactionNamesQuant);
						buttonSymbolValue = _getch();
						actionCursorPos = setCursorPos(buttonSymbolValue, actionCursorPos, 0, MACTLactionNamesQuant);
						system("cls");

						if (buttonSymbolValue == ENTER_BUTTON) {
							switch (actionCursorPos) {
							case 0: {
								int quantity;
								cout << "\nenter quantity: ";
								cin >> quantity;
								divisions[divisionListCursorPos].add(quantity);
								break;
							}
							case 1: {
								string name;
								cout << "\nenter name: ";
								cin >> name;
								divisions[divisionListCursorPos].setName(name);
								break;
							}
							case 2: {
								int place;
								cout << "\nenter place: ";
								cin >> place;
								divisions[divisionListCursorPos].remove(place);
								break;
							}
							}
						}
						system("cls");
					}
					buttonSymbolValue = NONE;
				}

				else if (buttonSymbolValue == ENTER_BUTTON && divisions[divisionListCursorPos].getTankQuantity() != 0) {
					while (buttonSymbolValue != ClOSE_BUTTON && buttonSymbolValue != HOME_BUTTON) {

						cout << getMembersList(divisions[divisionListCursorPos], cursorPos);
						cout << getActionList(tanksActionListNames, actionCursorPos, tanksActionListQuant);
						buttonSymbolValue = _getch();
						actionCursorPos = setCursorPos(buttonSymbolValue, actionCursorPos, 0, tanksActionListQuant);
						system("cls");


						if (buttonSymbolValue == ENTER_BUTTON) {
							Tank tempTank;
							tempTank = divisions[divisionListCursorPos].getTank(cursorPos);

							switch (actionCursorPos) {
							case 0: {
								string model;
								cout << "enter model: ";
								cin >> model;
								tempTank.setModel(model);
								break;
							}
							case 1: {
								string country;
								cout << "enter country: ";
								cin >> country;
								tempTank.setCountry(country);
								break;
							}
							case 2: {
								double mass;
								cout << "enter mass: ";
								cin >> mass;
								tempTank.setMass(mass);
								break;
							}
							case 3: {
								string type;
								cout << "enter type: ";
								cin >> type;
								tempTank.setType(type);
								break;
							}
							case 4: {
								double cost;
								cout << "enter cost: ";
								cin >> cost;
								tempTank.setCost(cost);
								break;
							}
							}
							divisions[divisionListCursorPos].copyTankProps(tempTank, cursorPos);
							system("cls");
						}


					}
					buttonSymbolValue = NONE;
				}

				else if (buttonSymbolValue == END_BUTTON && divisions[divisionListCursorPos].getTankQuantity() > 0) {

					system("cls");
					cout << divisions[divisionListCursorPos].getTank(cursorPos).info() << "\n\n";

				}

			}
		}

	}


	delete[] divisions;

	return 0;
}
