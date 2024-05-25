#include "CDisplay.h"

void CDisplay::showStatus(CElevator*& Elevator)
{
	std::cout << "Status" << std::endl;
	std::cout << "People in building: " << Elevator->waiters().size() << std::endl;
	std::cout << "People in elevator: " << Elevator->getRequestsForDown().size() + Elevator->getRequestsForUp().size() << std::endl;
	std::cout << "People for Up: "<< Elevator->getRequestsForUp().size() << std::endl;
	std::cout << "People for Down: " << Elevator->getRequestsForDown().size() << std::endl;
	std::cout << "Elevator moving: "; 
	if (Elevator->checkIfIsUp())
	{
		std::cout << "Up" << std::endl;
	}
	else {
		std::cout << "Down" << std::endl;
	}
	std::cout << "Door is closed: " << Elevator->checkDoorIsOpen() << std::endl;
}
void CDisplay::showTextOnDisplay(CElevator*& elevator)
{
	
	std::cout << '+' << std::setfill('-') << std::setw(10) << '+';
	std::cout << std::endl << '|' << "Moving..." << '|' << std::endl;
	if (elevator->checkIfIsUp())
	{
		std::cout << std::setfill(' ') << '|' << std::setw(5) << "/\\" << std::setw(5) << '|' << std::endl;
	}
	else {
		std::cout << std::setfill(' ') << '|' << std::setw(5) << "/\\" << std::setw(5) << '|' << std::endl;
	}
	std::cout << '+' << std::setfill('-') << std::setw(10) << '+';
}

void CDisplay::personJoiningEl()
{
	std::cout << "Person enter in the elevator!" << std::endl;
}
void CDisplay::personLeavingEl()
{
	std::cout << "Person leave the elevator!" << std::endl;
}