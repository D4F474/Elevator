#ifndef C_ENGINE
#define C_ENGINE
#include <iostream>
#include <thread>
#include <chrono>
#include <list>

#include "CBuilding.h"
#include "CCitizen.h"
#include "CElevator.h"

#define MAIN_MENU_ELEMENTS 3
#define LEVELS_OF_BUILDING 4

class CEngine
{
private:
	CElevator* Elevator = nullptr;
	CCitizen* citizen = nullptr;
public:
	unsigned short manyCitizens = 2;
	CEngine();
	void startProgram();
	unsigned short mainMenu();
	void moveElevator(CElevator& Elevator);
};

#endif