#include <iostream>
#include "ui.h"
#include "Reservation_system.h"

using namespace std;

int main()
{
	Reservation_system system;
	system.configSystem();
	system.process();
}
