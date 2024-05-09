#include "CDisplay.h"

void CDisplay::showStatus(CElevator*& Elevator)
{
	std::cout << "Status" << std::endl;
	std::cout << "People in building: " << Elevator->waiters().size() << std::endl;
	std::cout << "People in elevator: " << Elevator->getRequestsForDown().size() + Elevator->getRequestsForUp().size() << std::endl;
	std::cout << "People for Up: "<< Elevator->getRequestsForUp().size() << std::endl;
	std::cout << "People for Down: " << Elevator->getRequestsForDown().size() << std::endl;
	std::cout << "Elevator moving: " << Elevator->checkIfIsUp() ? std::cout << "Up" << std::endl : std::cout << "Down" << std::endl;
	//fix me
	std::cout << "Door is closed: " << "YES" << std::endl;
}