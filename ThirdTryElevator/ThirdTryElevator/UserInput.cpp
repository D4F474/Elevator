#include "CUserInput.h"
CUserInput::CUserInput(unsigned short levelOfBuilding)
	:CCitizen(levelOfBuilding,0)
{

}
void CUserInput::showUserMenu()
{
	system("CLS");
	for (int i = 1; i <= getLevel(); i++)
	{
		std::cout << "( " << i << " )" << std::endl;
	}
	std::cout << "( s )" << std::endl;
	std::cout << "( [ )" << std::endl;
	std::cout << "( ! )" << std::endl;
	setPersonDestination(userRequestDestination());
}

unsigned short CUserInput::userRequestDestination()
{
	char userInput = '\0';
	bool rightInput = false;
	while (!rightInput)
	{
		std::cin >> userInput;
		if (userInput > '0' && userInput <= getLevel() + '0')
		{
			return userInput - '0';
		}
	}
	return 0;
}

unsigned short userRequestSpecialButtons() {

}