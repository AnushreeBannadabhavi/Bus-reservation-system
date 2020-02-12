#pragma once
#include <vector>
#include <string>
#include "Bus.h"

class Route
{
private:
	std::vector<std::string> m_stops;
	Bus* m_bus;
public:
	Route();
	std::vector<std::string> getStops();
	bool isRouteAvailable(std::string startPoint, std::string EndPoint);
	const std::string getBusFilepathForRoute();
	void setStops(std::vector<std::string> newStops);
	void setBusForRoute(Bus* newBus);
	bool doesRouteExist(std::string start, std::string end);
};

