#include "CElevator.h"
CElevator::CElevator()
{
	requestsForUp = std::list<unsigned short>();
	requestsForDown = std::list<unsigned short>();
}

CElevator::CElevator(unsigned short levels)
	:CBuilding(levels)
{
	currLevel = (levels * 5) - 3;
	matrix[currLevel][2] = '(';
	requestsForUp = std::list<unsigned short>();
	requestsForDown = std::list<unsigned short>();
}

void CElevator::moveUpElevator()
{
	matrix[currLevel][2] = '0';
	matrix[--currLevel][2] = '(';
	system("CLS");
	getMatrix();
}

void CElevator::moveDownElevator()
{
	matrix[currLevel][2] = '0';
	matrix[++currLevel][2] = '(';
	system("CLS");
	getMatrix();
}

unsigned short CElevator::getCurrLevel()
{
	return currLevel;
}

void CElevator::changeIfIsUpOrDown() 
{
	if (isUp)
	{
		isUp = false;
		return;
	}
	isUp = true;
}

bool CElevator::checkIfIsUp()
{
	return isUp;
}

void CElevator::addForUp(unsigned short citizenLevel)
{
	requestsForUp.push_front(citizenLevel);
}

void CElevator::addForDown(unsigned short citizenLevel)
{
	requestsForDown.push_front(citizenLevel);
}

void CElevator::dropForUp()
{
	requestsForUp.pop_front();
}

void CElevator::dropForDown()
{
	requestsForDown.pop_front();
}

std::list<unsigned short> CElevator::getRequestsForUp()
{
	return requestsForUp;
}
std::list<unsigned short> CElevator::getRequestsForDown()
{
	return requestsForDown;
}
unsigned short CElevator::getLevelNum() const
{
	return levelNum;
}

bool CElevator::checkIfCitizenHaveToLeaveElevator(unsigned short c, CElevator& e)
{
	if (c == e.getLevelNum())
	{
		return true;
	}
	return false;
}

void CElevator::incementOrDecrementLevelNum(bool isTrue) 
{
	if (isTrue)
	{
		levelNum++;
	}
	else 
	{
		levelNum--;
	}
}

void CElevator::removeRequestForUp()
{
	requestsForUp.pop_front();
}
void CElevator::removeRequestForDown()
{
	requestsForDown.pop_front();
}

bool CElevator::dropFromMiddleForUp(CElevator& elevator) {
	unsigned short counter = 0;
	for (std::list<unsigned short>::iterator it = elevator.requestsForUp.begin(); it != elevator.requestsForUp.end();) {
		if (checkIfCitizenHaveToLeaveElevator(*it, elevator)) {
			it = elevator.requestsForUp.erase(it);
			counter++;
		}
		else {
			++it;
		}
	}
	if (counter > 0)
	{
		return true;
	}
		return false;
}

bool CElevator::dropFromMiddleForDown(CElevator& elevator) {
	for (std::list<unsigned short>::iterator it = elevator.requestsForDown.begin(); it != elevator.requestsForDown.end();) {
		if (checkIfCitizenHaveToLeaveElevator(*it, elevator)) {
			it = elevator.requestsForDown.erase(it);
		}
		else {
			++it;
		}
	}
	return false;
}

bool CElevator::checkDoorIsOpen()
{
	return isDoorOpen;
}
void CElevator::openOrCloseDoor()
{
	if (isDoorOpen)
	{
		isDoorOpen = false;
	}
	isDoorOpen = true;
}