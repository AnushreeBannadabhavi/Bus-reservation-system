#include <iostream>
#include "Reservation_system.h"
#include "ui.h"

using namespace std;

void Reservation_system::configSystem()
{
	m_numOfRoutes = 3;
	m_numOfBuses = 3;

	std::vector<std::string> stop1;
	std::vector<std::string> stop2;
	std::vector<std::string> stop3;

	stop1.push_back("BLR");
	stop1.push_back("CHN");
	stop2.push_back("BLR");
	stop2.push_back("BOM");
	stop3.push_back("BLR");
	stop3.push_back("DEL");

	for (int i = 0; i < m_numOfRoutes; i++) {
		m_listOfRoutes.push_back(new Route);
	}

	m_listOfRoutes[0]->setStops(stop1);
	m_listOfRoutes[1]->setStops(stop2);
	m_listOfRoutes[2]->setStops(stop3);

	for (int i = 0; i < m_numOfBuses; i++) {
		m_listOfBuses.push_back(new Bus);
	}

	m_listOfBuses[0]->setBusInfo(1, 9, 14, stop1);
	m_listOfBuses[1]->setBusInfo(2, 15, 20, stop2);
	m_listOfBuses[2]->setBusInfo(3, 18, 21, stop3);

	m_listOfBuses[0]->setBusInfofilePath();
	m_listOfBuses[1]->setBusInfofilePath();
	m_listOfBuses[2]->setBusInfofilePath();

	m_listOfBuses[0]->writeBusInfoinFile();
	m_listOfBuses[1]->writeBusInfoinFile();
	m_listOfBuses[2]->writeBusInfoinFile();


	for (int i = 0; i < m_numOfBuses; i++) {
		m_listOfRoutes[i]->setBusForRoute(m_listOfBuses[i]);
	}


}

const std::string Reservation_system::getBusInfoFilepathforRoute(std::string start, std::string end, int& busID)
{
	for (auto route : m_listOfRoutes) {
		busID++;
		bool routeExists = route->doesRouteExist(start, end);
		if (routeExists) {
			const std::string busInfoFilePath = route->getBusFilepathForRoute();
			return busInfoFilePath;
		}
	}
	busID = -1;
	return std::string();
}

void Reservation_system::process()
{
	Ui ui;
	while (1) {
		ui.displayWelcomeInfo();
		cout << "\tDo you wish to Continue? ";
		if (!endSession())
			break;

		ui.displayUserInfoTobeEntered();
		string startingPoint;
		string endPoint;
		string passengerName;
		string contactNumber;
		cin >> startingPoint;
		cin >> endPoint;
		cin >> passengerName;
		cin >> contactNumber;
		cout << "\n";

		int busIDneeded = -1;
		int selectedSeat;
		const std::string busInfoFilePath = getBusInfoFilepathforRoute(startingPoint, endPoint, busIDneeded);
		if (busInfoFilePath == "") {
			ui.displayNoBusErrorMessage();
			ui.displayEndSessionInfo();
			if (endSession())
				break;
		}
		else {
			ui.displayBusInfo(busInfoFilePath);
			ui.displayBusLayout(m_listOfBuses[busIDneeded]->getSeatInfo());
			cout << "\n\tEnter required seat: ";
			cin >> selectedSeat;
			bool isSuccesful = m_listOfBuses[busIDneeded]->setPassengerInformation(selectedSeat);
			if (isSuccesful) {
				cout << "\n\tBooking is confirmed\n";
				cout << "\tDo you wish to see the seat layout? ";
				std::string seeSeatLayout;
				cin >> seeSeatLayout;
				if (seeSeatLayout == "y" || seeSeatLayout == "Y") {
					ui.displayBusInfo(busInfoFilePath);
					ui.displayBusLayout(m_listOfBuses[busIDneeded]->getSeatInfo());
				}
			}
			else {
				cout << "\n\tOops! The selected seat is not available\n";
			}
			ui.displayEndSessionInfo();
			if (endSession()) {
				break;
			}
		}

	}

}

bool Reservation_system::endSession()
{
	std::string userInput;
	cin >> userInput;
	if (userInput == "y" || userInput == "Y")
		return true;
	else
		return false;
}


