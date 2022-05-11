#include "Tank.h"
#include "Division.h"
#include "UI.h"

#define ClOSE_BUTTON 120
//MAIN ACTION LIST = MACTL
#define OPEN_MACTL_BUTTON 97
#define ENTER_BUTTON 13
#define HOME_BUTTON 75
#define END_BUTTON 77

int main() {

	cout << getStartScreen();
	system("pause");
	system("cls");

	int cursorPos = 0;
	int actionCursorPos = 0;
	int buttonSymbolValue = 0;

	const int MACTLactionNamesQuant = 2;
	string MCATLactionNames[MACTLactionNamesQuant]{ "add member", "set name"};

	const int tanksActionListQuant = 5;
	string tanksActionListNames[tanksActionListQuant]{ "set model", "set country", "set mass", "set type", "set cost" };

	Division division1;

	while (buttonSymbolValue != ClOSE_BUTTON) {

		cout << getMembersList(division1, cursorPos);
		buttonSymbolValue = _getch();
		cursorPos = setCursorPos(buttonSymbolValue, cursorPos, 0, division1.getTankQuantity());
		system("cls");


		actionCursorPos = 0;


		if (buttonSymbolValue == OPEN_MACTL_BUTTON) {
			while (buttonSymbolValue != ClOSE_BUTTON && buttonSymbolValue != HOME_BUTTON) {

				cout << getMembersList(division1, cursorPos);
				cout << getActionList(MCATLactionNames, actionCursorPos, MACTLactionNamesQuant);
				buttonSymbolValue = _getch();
				actionCursorPos = setCursorPos(buttonSymbolValue, actionCursorPos, 0, MACTLactionNamesQuant);
				system("cls");

				if (buttonSymbolValue == ENTER_BUTTON) {
					switch (actionCursorPos) {
					case 0:
						int quantity;
						cout << "\nenter quantity: ";
						cin >> quantity;
						division1.add(quantity);
						system("cls");
						break;
					case 1:
						string name;
						cout << "\nenter name: ";
						cin >> name;
						division1.setName(name);
						system("cls");
						break;
					}
				}

			}
		}


		else if (buttonSymbolValue == ENTER_BUTTON && division1.getTankQuantity()!= 0) {
			while (buttonSymbolValue != ClOSE_BUTTON && buttonSymbolValue != HOME_BUTTON) {

				cout << getMembersList(division1, cursorPos);
				cout << getActionList(tanksActionListNames, actionCursorPos, tanksActionListQuant);
				buttonSymbolValue = _getch();
				actionCursorPos = setCursorPos(buttonSymbolValue, actionCursorPos, 0, tanksActionListQuant);
				system("cls");


				if (buttonSymbolValue == ENTER_BUTTON) {
					switch (actionCursorPos) {
					case 0: {
						string model;
						cout << "enter model: ";
						cin >> model;
						Tank tempTank;
						tempTank = division1.getTank(cursorPos);
						tempTank.setModel(model);
						division1.copyTankProps(tempTank, cursorPos);
						system("cls");
						break;
					}
					case 1: {
						string country;
						cout << "enter country: ";
						cin >> country;
						Tank tempTank;
						tempTank = division1.getTank(cursorPos);
						tempTank.setCountry(country);
						division1.copyTankProps(tempTank, cursorPos);
						system("cls");
						break;
					}
					case 2: {
						double mass;
						cout << "enter mass: ";
						cin >> mass;
						Tank tempTank;
						tempTank = division1.getTank(cursorPos);
						tempTank.setMass(mass);
						division1.copyTankProps(tempTank, cursorPos);
						system("cls");
						break;
					}
					case 3: {
						string type;
						cout << "enter type: ";
						cin >> type;
						Tank tempTank;
						tempTank = division1.getTank(cursorPos);
						tempTank.setType(type);
						division1.copyTankProps(tempTank, cursorPos);
						system("cls");
						break;
					}
					case 4: {
						double cost;
						cout << "enter cost: ";
						cin >> cost;
						Tank tempTank;
						tempTank = division1.getTank(cursorPos);
						tempTank.setCost(cost);
						division1.copyTankProps(tempTank, cursorPos);
						system("cls");
						break;
					}
					}
				}


			}
		}

		else if (buttonSymbolValue == END_BUTTON) {

		system("cls");
		cout << division1.getTank(cursorPos).info() << "\n\n";
        }


	}






	return 0;
}
