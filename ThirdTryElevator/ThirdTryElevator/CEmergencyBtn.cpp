#include "CEmergencyBtn.h"
void CEmergencyBtn::showTextOnDisplay(CElevator*& elevator)
{
	std::cout << '+' << std::setfill('-') << std::setw(20) << '+';
	std::cout << std::setfill(' ') << std::endl << '|' << std::setw(3) << "Emergency call" << std::setw(6) << '|' << std::endl;
	std::cout << '|' << "We call the " << std::setw(8) << '|'
	<< std::endl << '|' << "technicians..." << std::setw(6) << '|' << std::endl;
	std::cout << '+' << std::setfill('-') << std::setw(20) << '+';
}

void CEmergencyBtn::emergencyCall() 
{
	
}