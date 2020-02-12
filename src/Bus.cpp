#include <sstream>
#include <fstream>
#include <algorithm>
#include "Bus.h"

Bus::Bus()
{
	m_busInfo.busID = -1;
	m_busInfo.arrivalTime = 0;
	m_busInfo.departureTime = 0;
	m_numOfSeats = 24;
	for (int i = 0; i < m_numOfSeats; i++) {
		m_seats[i] = false;
	}
}

BusInfo Bus::getBusInfo()
{
	return m_busInfo;
}

void Bus::setBusInfo(int busID, int arrivalTime, int departureTime, std::vector<std::string> stops)
{
	m_busInfo.busID = busID;
	m_busInfo.arrivalTime = arrivalTime;
	m_busInfo.departureTime = departureTime;
	for (auto stop : stops) {
		m_busInfo.stops.push_back(stop);
	}
}

void Bus::writeBusInfoinFile()
{
	std::ofstream outdata(m_busInfofilePath);
	outdata << "BusID: " << m_busInfo.busID << std::endl;
	outdata << "Arrival: " << m_busInfo.arrivalTime << ":00" << std::endl;
	outdata << "Departure: " << m_busInfo.departureTime << ":00" << std::endl;
	outdata << "From: " << m_busInfo.stops[0] << std::endl;
	outdata << "To: " << m_busInfo.stops[1] << std::endl;
}

bool Bus::setPassengerInformation(int seatNum)
{
	if (m_seats[seatNum] == false && seatNum <= m_numOfSeats) {
		m_seats[seatNum] = true;
		return true;
	}
	else
		return false;
}

std::map<int, bool> Bus::getSeatInfo()
{
	return m_seats;
}


const std::string Bus::getBusInfofilePath()
{
	return m_busInfofilePath;
}

void Bus::setBusInfofilePath()
{
	std::ostringstream strBusID;
	strBusID << m_busInfo.busID;
	std::string fileName = m_busInfofilePath + "Bus_" + strBusID.str() + ".txt";
	m_busInfofilePath = fileName;
}
