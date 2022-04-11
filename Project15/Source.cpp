#include "Tank.h"
#include "Division.h"


int main() {
	Division a;
	a.add(2);
	cout << a.getMembersInfo();
	a.remove(1);
	cout << a.getMembersInfo();
	return 0;
}
