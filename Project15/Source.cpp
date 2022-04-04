#include "Tank.h"


int main() {
	Tank tank0;
	cout << endl << tank0.info() << "\n\n";

	Tank tank1("Centurion 7/1", "Britain", 60, "Medium", 4000);
	cout << tank1.info() << "\n\n";

	Tank tank2;

	cout << "\nenter tank model:";
	string model;
	cin >> model;
	tank2.setModel(model);

	return 0;
}
