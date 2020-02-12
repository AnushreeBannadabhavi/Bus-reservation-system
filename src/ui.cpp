#include "ui.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

void Ui::displaySpecialChar(char ch)
{
	for (int i = 80; i > 0; i--)
		cout << ch;
}

void Ui::displayWelcomeInfo()
{
	cout << "\n\n";

	cout << "\tWELCOME!! \n"

		 << "\n\tHere is a list of Stops with their respective city code \n\t\t"

		 << "1.Bangalore - BLR \n\t\t"

		 << "2.Chennai - CHN \n\t\t"

		 << "3.Mumbai - BOM \n\t\t"

		 << "4.Delhi - DEL\n\n";
}

void Ui::displayBusInfo(const std::string busInfoFilePath)
{
	std::string line;
	std::string temp;
	std::string val;
	std::vector<std::string> firstFiveContents;
	std::ifstream filestream(busInfoFilePath);
	if (filestream.is_open()) {
		for (int i = 0; i < 5; i++) {
			std::getline(filestream, line);
			std::istringstream linestream(line);
			linestream >> temp >> val;
			firstFiveContents.push_back(val);
		}
	}
	displaySpecialChar('*');
	cout << "\nBus ID: \t" << firstFiveContents[0]

		<< "\nArrival time: \t" << firstFiveContents[1] << "\t\tDeparture time: "

		<< firstFiveContents[2]

		<< "\nFrom: \t\t" << firstFiveContents[3] << "\t\tTo: \t\t" <<

		firstFiveContents[4] << "\n";

	displaySpecialChar('*');
}

void Ui::displayBusLayout(std::map<int, bool> seatInfo)
{
	cout << "\n";
	int seatsInRow = 6;
	for (int i = 0; i < 4; i++) {
		cout << "\n";
		if (i == 2) {
			cout << "\n";
		}
		for (int j = 0; j < 6; j++) {
			cout << ((seatsInRow * i + j) + 1) << ".";
			if (seatInfo[((seatsInRow * i + j) + 1)] == true)
				cout << "OCCUPIED";
			else
				cout << "VACANT";
			cout << "\t";
		}
	}
	cout << "\n";
}

void Ui::displayUserInfoTobeEntered()
{
	cout << "\n\n";

	cout << "\tEnter the following:\n\t\t"

		 << "1.Starting Point city code\n\t\t"

		 << "2.End Point city code\n\t\t"

		 << "3.Passenger Name \n\t\t"

		 << "4.Contact number \n";
}

void Ui::displayNoBusErrorMessage()
{
	cout << "\tNo Buses available for the requested route";
}

void Ui::displayEndSessionInfo()
{
	cout << "\n\n\tDo you want to end the session? ";
}
