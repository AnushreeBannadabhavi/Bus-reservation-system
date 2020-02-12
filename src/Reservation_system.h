#pragma once
#include <vector>
#include <string>
#include "Route.h"
#include "Bus.h"

class Reservation_system
{
private:
	std::vector<Route*> m_listOfRoutes;
	std::vector<Bus*> m_listOfBuses;
	int m_numOfRoutes;
	int m_numOfBuses;
public:
	void configSystem();
	const std::string getBusInfoFilepathforRoute(std::string start, std::string end, int& busID);
	void process();
	bool endSession();
};

