#include <iostream>
#include <thread>
#include <chrono>
#include <list>

//Classes
#include "CBuilding.h"
#include "CElevator.h"
#include "CDisplay.h"
#include "CUserInput.h"

#define MAIN_MENU_ELEMENTS 3
#define LEVELS_OF_BUILDING 4
#define PEOPLE_TO_USE_ELEVATOR 1
void startProgram();
void enterSignalsForElevatorInBuilding();
unsigned short mainMenu();
void moveElevator();
void elevatorStart();

CElevator* Elevator = nullptr;
CCitizen* citizen = nullptr;
CDisplay* display = nullptr;
CUserInput* userInput = nullptr;

int main()
{
	srand(time(NULL));
	startProgram();
	std::cout << std::endl << "Congrats we work good!";
	return 0;
}

void startProgram()
{
	switch (mainMenu())
	{
	case 1:
		Elevator = new CElevator(LEVELS_OF_BUILDING);
		display = new CDisplay();
		userInput = new CUserInput(LEVELS_OF_BUILDING);
		enterSignalsForElevatorInBuilding();
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
void enterSignalsForElevatorInBuilding()
{
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
		elevatorStart();
	}
}
unsigned short mainMenu()
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

void moveElevator()
{
	if (Elevator->checkIfIsUp())
	{
		for (int i = 0; i < 5; i++)
		{

			Elevator->moveUpElevator();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			Elevator->moveDownElevator();

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

void elevatorStart()
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
					moveElevator();
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
				moveElevator();
				Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
				display->showStatus(Elevator);
			}

		}
		else
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
					moveElevator();
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
				moveElevator();
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