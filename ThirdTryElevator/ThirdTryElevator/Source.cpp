#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <iomanip>


#include "CBuilding.h"
#include "CElevator.h"
#include "CDisplay.h"
#include "CUserInput.h"

#define MAIN_MENU_ELEMENTS 2

#define LEVELS_OF_BUILDING 4
#define PEOPLE_TO_USE_ELEVATOR 1

//prototypes
void startProgram(CElevator*& Elevator, CCitizen*& citizen, CDisplay*& display, CUserInput*& userInput);
void enterSignalsForElevatorInBuilding(CElevator*& Elevator, CCitizen*& citizen, CDisplay*& display, CUserInput*& userInput);
unsigned short mainMenu();
void moveElevator(CElevator*& Elevator);
void elevatorStart(CElevator*& Elevator, CCitizen*& citizen, CDisplay*& display, CUserInput*& userInput);


int main()
{
CElevator* Elevator = nullptr;
CCitizen* citizen = nullptr;
CDisplay* display = nullptr;
CUserInput* userInput = nullptr;
	srand(time(NULL));
	startProgram(Elevator, citizen, display, userInput);
	std::cout << std::endl << "Congrats we work good!";
	return 0;
}

void startProgram(CElevator*& Elevator, CCitizen*& citizen, CDisplay*& display, CUserInput*& userInput)
{
	unsigned short menuItem;
	do {
		system("CLS");
		menuItem = mainMenu();
	switch (menuItem)
	{
	case 1:
		Elevator = new CElevator(LEVELS_OF_BUILDING);
		display = new CDisplay();
		userInput = new CUserInput(LEVELS_OF_BUILDING);
		enterSignalsForElevatorInBuilding(Elevator, citizen, display, userInput);
		break;
	default:

		break;
	}
	} while (menuItem != MAIN_MENU_ELEMENTS);
}
void enterSignalsForElevatorInBuilding(CElevator*& Elevator, CCitizen*& citizen, CDisplay*& display, CUserInput*& userInput)
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
		elevatorStart(Elevator, citizen, display, userInput);
	}
}
unsigned short mainMenu()
{
	unsigned short choise;
	std::cout << "******* Menu *******" << std::endl;
	std::cout << '*' << "1. Start simulator" << '*' << std::endl;
	std::cout << '*' << "2. Exit"<< std::setw(12) << '*' << std::endl;
	do {
		std::cout << "Choise option: ";			std::cin >> choise;
	} while (choise < 1 || choise > MAIN_MENU_ELEMENTS);
	return choise;

}

void moveElevator(CElevator*& Elevator)
{
	if (Elevator->checkIfIsUp())
	{
		for (int i = 0; i < 5; i++)
		{

			Elevator->moveUpElevator();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
	else
	{
		
		for (int i = 0; i < 5; i++)
		{
			Elevator->moveDownElevator();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		
	}
}

void elevatorStart(CElevator*& Elevator, CCitizen*& citizen, CDisplay*& display, CUserInput*& userInput)
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
				display->personJoiningEl();
				std::this_thread::sleep_for(std::chrono::seconds(3));
				Elevator->removeBuildWaiters();
				continue;
			}
			else if (citizen != nullptr && citizen->getPersonLevel() == Elevator->getLevelNum())
			{
				Elevator->addForDown(citizen->getPersonDestination());
				display->personJoiningEl();
				std::this_thread::sleep_for(std::chrono::seconds(3));
				Elevator->removeBuildWaiters();
				continue;
			}
		}
	std::thread userInputThread([&]() {
		userInput->userRequestSpecialButtons(Elevator);
		});
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
					display->personLeavingEl();
					std::this_thread::sleep_for(std::chrono::seconds(5));
					moveElevator(Elevator);
					Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
					display->showStatus(Elevator);
				}
				else {
				}
			}
			else if (Elevator->getRequestsForUp().size() == 1 && Elevator->getRequestsForUp().front() == Elevator->getLevelNum())
			{
				display->personLeavingEl();
				std::this_thread::sleep_for(std::chrono::seconds(5));
				Elevator->removeRequestForUp();
			}
			else
			{

				moveElevator(Elevator);
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
					display->personLeavingEl();
					std::this_thread::sleep_for(std::chrono::seconds(5));
					moveElevator(Elevator);
					Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
					display->showStatus(Elevator);
				}
				else {
				}
			}
			else if (Elevator->getRequestsForDown().size() == 1 && Elevator->getRequestsForDown().front() == Elevator->getLevelNum())
			{
				display->personLeavingEl();
				std::this_thread::sleep_for(std::chrono::seconds(5));
				Elevator->removeRequestForDown();
			}
			else
			{
				moveElevator(Elevator);
				Elevator->incementOrDecrementLevelNum(Elevator->checkIfIsUp());
				display->showStatus(Elevator);
			}
		}
		if (Elevator->waiters().size() == 0 && Elevator->getRequestsForUp().size() == 0 && Elevator->getRequestsForDown().size() == 0
			&& Elevator->getCurrLevel() == (LEVELS_OF_BUILDING * 5) - 3)
		{
			userInputThread.detach();
			std::this_thread::sleep_for(std::chrono::seconds(3));
			break;
		}
			userInputThread.detach();
	}
}