#pragma once
#include <string>
#include <map>

using namespace std;

class Ui
{
private:
	void displaySpecialChar(char ch);
public:
	void displayWelcomeInfo();
	void displayBusInfo(const std::string busInfoFilePath);
	void displayBusLayout(std::map<int, bool> seatInfo);
	void displayUserInfoTobeEntered();
	void displayNoBusErrorMessage();
	void displayEndSessionInfo();
};

