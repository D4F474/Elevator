#ifndef C_ENGINE
#define C_ENGINE
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

class CEngine
{
private:
	CElevator* Elevator = nullptr;
	CCitizen* citizen = nullptr;
	CDisplay* display = nullptr;
	CUserInput* userInput = nullptr;
public:
	unsigned short manyCitizens = 2;
	CEngine();
	void startProgram();
	unsigned short mainMenu();
	void moveElevator(CElevator& Elevator);
	void elevatorSignals(CUserInput& userInput);
};

#endif