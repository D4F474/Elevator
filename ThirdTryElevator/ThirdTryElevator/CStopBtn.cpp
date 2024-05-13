#include "CStopBtn.h"

void CStopBtn::showTextOnDisplay(CElevator*& elevator)
{
	std::cout << '+' << std::setfill('-') << std::setw(20) << '+';
	std::cout << std::setfill(' ') << std::endl << '|' << "Elevator is stopped" << '|' << std::endl;
	std::cout << '|' << "Waiting to start..." << '|' << std::endl;
	std::cout << '+' << std::setfill('-') << std::setw(20) << '+';
}

void CStopBtn::stopElev()
{

}