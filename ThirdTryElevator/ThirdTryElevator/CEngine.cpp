#include "CEngine.h"
CEngine::CEngine()
{
	startProgram();
}

void CEngine::startProgram()
{
	switch (mainMenu())
	{
	case 1:
		Elevator = new CElevator(LEVELS_OF_BUILDING);
		display = new CDisplay();
		userInput = new CUserInput(LEVELS_OF_BUILDING);
		for (int i = 0; i < PEOPLE_TO_USE_ELEVATOR; i++)
		{
			citizen = new CCitizen(Elevator->getLevels());
			Elevator->addBuildWaiters(*citizen);
		}
		userInput->showUserMenu();
		Elevator->addBuildWaiters(*userInput);
		Elevator->sortWaiters();
		if (Elevator->waiters().size() > 0)
		{
			elevatorSignals(*userInput);
		}
		break;
	case 2:
			
		//Settings
		break;
	case 3:

		break;
	default:

		break;
	}
}

unsigned short CEngine::mainMenu()
{
	unsigned short choise;
	std::cout << "*******" << std::endl;
	std::cout << "*** Menu ***" << std::endl;
	std::cout << "1. Start simulator without you" << std::endl;
	std::cout << "2. Start simulator with your control" << std::endl;
	std::cout << "3. Exit" << std::endl;
	do {
		std::cout << "Choise option" << std::endl;
		std::cin >> choise;
	} while (choise < 1 || choise > MAIN_MENU_ELEMENTS);
	return choise;

}

void CEngine::moveElevator(CElevator& Elevator)
{
	if (Elevator.checkIfIsUp())
	{
		for (int i = 0; i < 5; i++)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Elevator.moveUpElevator();
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Elevator.moveDownElevator();
		}
	}
}
 
void CEngine::elevatorSignals(CUserInput& userInput)
{
	while (true)
	{
		if (Elevator->waiters().size() > 0)
		{
			citizen = Elevator->getWaiter();
			//citizen is taking elevator
			//sorting citizens by up or down
			if (citizen->getPersonDestination() > Elevator->getLevelNum() && citizen != nullptr && citizen->getPersonLevel() == Elevator->getLevelNum())
			{
				Elevator->addForUp(citizen->getPersonDestination());
				Elevator->removeBuildWaiters();
				continue;
			}
			else if (citizen != nullptr && citizen->getPersonLevel() == Elevator->getLevelNum())
			{
				Elevator->addForDown(citizen->getPersonDestination());
				Elevator->removeBuildWaiters();
				continue;
			}
		}
		//checking if elevator is up or down
		if (Elevator->checkIfIsUp()) 
		{
			//UP
			//Not allowing to cross over the box
			if (Elevator->getCurrLevel() == 2 || Elevator->getRequestsForUp().size() == 0 && Elevator->getCurrLevel() != (LEVELS_OF_BUILDING * 5) - 3 
				&& Elevator->waiters().size() == 0)
			{
				Elevator->changeIfIsUpOrDown();
			}
			//check if there is somebody to leave the elevator
			if (Elevator->getRequestsForUp().size() > 1)
			{
				if (!Elevator->dropFromMiddleForUp(*Elevator))
				{
					moveElevator(*Elevator);
					Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
					display->showStatus(Elevator);
				}
				else {
					std::this_thread::sleep_for(std::chrono::seconds(3));
				}
			}
			else if (Elevator->getRequestsForUp().size() == 1 && Elevator->getRequestsForUp().front() == Elevator->getLevelNum())
			{
				Elevator->dropForUp();
				std::this_thread::sleep_for(std::chrono::seconds(3));
			}
			else
			{
				moveElevator(*Elevator);
				Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
				display->showStatus(Elevator);
			}

		}else
		{
			//down
			//Not allowing to cross over the box
			if (Elevator->getCurrLevel() == (LEVELS_OF_BUILDING * 5) - 3 && Elevator->waiters().size() == 0)
			{
				Elevator->changeIfIsUpOrDown();
			}
			//check if there is somebody to leave the elevator
			if (Elevator->getRequestsForDown().size() > 1)
			{
				if (!Elevator->dropFromMiddleForDown(*Elevator))
				{
					moveElevator(*Elevator);
					Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
					display->showStatus(Elevator);
				}
				else {
					std::this_thread::sleep_for(std::chrono::seconds(3));
				}
			}
			else if (Elevator->getRequestsForDown().size() == 1 && Elevator->getRequestsForDown().front() == Elevator->getLevelNum())
			{
				Elevator->dropForDown();
				std::this_thread::sleep_for(std::chrono::seconds(3));
			}
			else
			{
				moveElevator(*Elevator);
				Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
				display->showStatus(Elevator);
			}
		}
		if (Elevator->waiters().size() == 0 && Elevator->getRequestsForUp().size() == 0 && Elevator->getRequestsForDown().size() == 0 
			&& Elevator->getCurrLevel() == (LEVELS_OF_BUILDING * 5) - 3)
		{
			break;
		}
	}
}