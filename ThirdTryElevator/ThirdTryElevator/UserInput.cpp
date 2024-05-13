#include "CUserInput.h"
CUserInput::CUserInput(unsigned short levelOfBuilding)
	:CCitizen(levelOfBuilding,0)
{
	doorBtn = new CDoorBtn();
	stopBtn = new CStopBtn();
	emergencyBtn = new CEmergencyBtn();
}
void CUserInput::showUserMenu()
{
	system("CLS");
	for (int i = 1; i <= getLevel(); i++)
	{
		std::cout << "( " << i << " )" << std::endl;
	}
	setPersonDestination(userRequestDestination());
}

unsigned short CUserInput::userRequestDestination()
{
	char userInput = '\0';
	bool rightInput = false;
	while (!rightInput)
	{
		std::cin >> userInput;
		if (userInput > '0' && userInput <= getLevel() + '0' && userInput != getPersonLevel() + '0')
		{
			return userInput - '0';
		}
	}
	return 0;
}

void CUserInput::userRequestSpecialButtons(CElevator*& elevator) 
{
	char userInput = '\0';
	bool rightInput = false;
	std::cout << "( s )" << std::endl;
	std::cout << "( [ )" << std::endl;
	std::cout << "( ! )" << std::endl;					std::cin >> userInput;
	while (!rightInput)
	{
		switch (userInput)
		{
			case 's':
				stopBtn->showTextOnDisplay(elevator);
				rightInput = true;
				break;
			case '[':
				doorBtn->showTextOnDisplay(elevator);
				rightInput = true;
				break;
			case '!':
				emergencyBtn->showTextOnDisplay(elevator);
				rightInput = true;
				break;
		}
	}
}