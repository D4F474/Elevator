#include "CEngine.h"
CEngine::CEngine()
{
	srand(time(NULL));
	startProgram();
}

void CEngine::startProgram()
{
	Elevator = new CElevator(LEVELS_OF_BUILDING);
	display = new CDisplay();

	switch (mainMenu())
	{
	case 1:
		for (int i = 0; i < 1; i++)
		{
			citizen = new CCitizen(Elevator->getLevels());
			Elevator->addBuildWaiters(*citizen);
		}
		Elevator->sortWaiters();
		if (Elevator->waiters().size() > 0)
		{
			elevatorSignals();
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
	std::cout << "1. Start simulator" << std::endl;
	std::cout << "2. Settings simulator" << std::endl;
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
 
void CEngine::elevatorSignals()
{
	while (true)
	{
		if (Elevator->waiters().size() > 0)
		{
			citizen = Elevator->getWaiter();
			//citizen is taking elevator
			if (citizen->getPersonLevel() == Elevator->getLevelNum())
			{
				//sorting citizens by up or down
				if (citizen->getPersonDestination() > Elevator->getLevelNum() && citizen != nullptr)
				{
					Elevator->addForUp(*citizen);
					Elevator->removeBuildWaiters();

				}
				else if (citizen != nullptr)
				{
					Elevator->addForDown(*citizen);
					Elevator->removeBuildWaiters();
				}
				continue;
			}
		}
		//checking if elevator is up or down
		if (Elevator->checkIfIsUp())
		{
			//UP
			//Not allowing to cross over the box
			if (Elevator->getCurrLevel() == 2)
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
				}
			}
			else if (Elevator->getRequestsForUp().size() == 1 && Elevator->getRequestsForUp().front()->getPersonDestination() == Elevator->getLevelNum())
			{
				Elevator->dropForUp();
			}
			else
			{
				moveElevator(*Elevator);
				Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
			}
		}
		else
		{
			//down
			//Not allowing to cross over the box
			if (Elevator->getCurrLevel() == (LEVELS_OF_BUILDING * 5) - 3)
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
				}
			}
			else if (Elevator->getRequestsForDown().size() == 1 && Elevator->getRequestsForDown().front()->getPersonDestination() == Elevator->getLevelNum())
			{
				Elevator->dropForDown();
			}
			else
			{
				moveElevator(*Elevator);
				Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
			}
		}
		display->showStatus(Elevator);
		if (Elevator->waiters().size() == 0 && Elevator->getRequestsForUp().size() == 0 && Elevator->getRequestsForDown().size() == 0 && Elevator->getCurrLevel() == (LEVELS_OF_BUILDING * 5) - 3)
		{
			break;
		}
	}
}