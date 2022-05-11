#pragma once
#include "Manager.h"


string getStartScreen() {

	string startScreen = "";

	startScreen += "___________________________\n";
	startScreen += "___________________________\n";
	startScreen += "Buttons:\n";
	startScreen += "End - go to object\n";
	startScreen += "Home - go back \n";
	startScreen += "PgUp - cursor up\n";
	startScreen += "PgDn - cursor down\n";
	startScreen += "Enter - open list of actions with object/confirm action\n";
	startScreen += "A - open main action list\n";
	startScreen += "X - close all\n";
	startScreen += "___________________________\n";
	startScreen += "___________________________\n";

	return startScreen;
}


string getMembersList(Division &division, int cursorPos) {

	string out = "_____________________________________________\n";
	out += division.getInfo() + "\nMembers:\n";

	for (int count = 0; count < division.getTankQuantity(); count++) {

	    if (count == cursorPos) {
			out += "->";
		}
		else {
			out += "  ";
		}

		out += to_string(count) + ". " + division.getTank(count).getModel() + "\n";
	}

	out += "\n_____________________________________________\n\n";

	return out;
}

#define PG_UP 72
#define PG_DN 80
#define ENTER 13
#define HOME 75

int setCursorPos(int button, int cursorPos, int minCursorPos, int maxCursorPos) {

	switch (button) {
	case PG_UP:
		if (cursorPos - 1 >= minCursorPos) {
			 cursorPos -= 1;
		}
		break;
	case PG_DN:
		if (cursorPos + 1 < maxCursorPos) {
			 cursorPos += 1;
		}
		break;
	}

	return cursorPos;
}

string getActionList(string* actionsNames, int cursorPos, int actionsQuant) {

	string out = "_____________________________________________\n";

	for (int count = 0; count < actionsQuant; count++) {

		if (count == cursorPos) {
			out += "->";
		}
		else {
			out += "  ";
		}

		out += to_string(count) + ". " + actionsNames[count] + "\n";
	}

	out += "\n_____________________________________________\n\n";

	return out;
}