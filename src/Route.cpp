#include "Route.h"

Route::Route()
{
	m_bus = nullptr;
}

std::vector<std::string> Route::getStops()
{
	return std::vector<std::string>();
}

bool Route::isRouteAvailable(std::string startPoint, std::string EndPoint)
{
	return false;
}

const std::string Route::getBusFilepathForRoute()
{
	return m_bus->getBusInfofilePath();
}

void Route::setStops(std::vector<std::string> newStops)
{
	m_stops = newStops;
}

void Route::setBusForRoute(Bus* newBus)
{
	m_bus = newBus;
}

bool Route::doesRouteExist(std::string start, std::string end)
{
	int count = 0;
	for (auto stop : m_stops)
	{
		if (start == stop || end == stop) {
			count++;
		}
	}
	if (count == 2)
		return true;
	else
		return false;
}

