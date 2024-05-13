#include "CDoorBtn.h"
void CDoorBtn::showTextOnDisplay(CElevator*& elevator)
{
	std::cout << '+' << std::setfill('-') << std::setw(10) << '+';
	std::cout << std::setfill(' ') << std::endl << '|' << "Door is:" << std::setw(2) << '|' << std::endl;
	if (elevator->checkDoorIsOpen())
	{
		std::cout << '|' << std::setw(5) << "Open" << std::setw(5) << '|' << std::endl;
	}
	else 
	{
		std::cout << '|' << std::setw(5) << "Closed" << std::setw(4) << '|' << std::endl;
	}
	std::cout << '+' << std::setfill('-') << std::setw(10) << '+';
}

void CDoorBtn::openOrCloseDoor() 
{

}