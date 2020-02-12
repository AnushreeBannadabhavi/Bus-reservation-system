#pragma once
#include <vector>
#include <string>
#include <map>

struct BusInfo {
	int busID = -1;
	int arrivalTime = 0;
	int departureTime = 0;
	std::vector<std::string> stops;
};

class Bus
{
private:
	BusInfo m_busInfo;
	std::string m_busInfofilePath{ "../BusInfo/" };
	std::map<int, bool> m_seats;
	int m_numOfSeats;

public:
	Bus();
	BusInfo getBusInfo();
	void setBusInfo(int busID, int arrivalTime, int departureTime, std::vector<std::string> stops);
	void writeBusInfoinFile();
	bool setPassengerInformation(int seatNum); // TODO: contact
	std::map<int, bool> getSeatInfo();
	const std::string getBusInfofilePath();
	void setBusInfofilePath();
};

