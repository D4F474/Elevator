#include "CElevator.h"
CElevator::CElevator()
{
	requestsForUp = std::list<CCitizen*>();
	requestsForDown = std::list<CCitizen*>();
}

CElevator::CElevator(unsigned short levels)
	:CBuilding(levels)
{
	currLevel = (levels * 5) - 3;
	matrix[currLevel][2] = '(';
	requestsForUp = std::list<CCitizen*>();
	requestsForDown = std::list<CCitizen*>();
}

unsigned short CElevator::callElevatorFromOutside() 
{
	
	return 0;
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

void CElevator::addForUp(CCitizen& citizen)
{
	requestsForUp.push_front(&citizen);
}

void CElevator::addForDown(CCitizen& citizen)
{
	requestsForDown.push_front(&citizen);
}

void CElevator::dropForUp()
{
	requestsForUp.pop_front();
}

void CElevator::dropForDown()
{
	requestsForDown.pop_front();
}

std::list<CCitizen*> CElevator::getRequestsForUp()
{
	return requestsForUp;
}
std::list<CCitizen*> CElevator::getRequestsForDown()
{
	return requestsForDown;
}
unsigned short CElevator::getLevelNum() const
{
	return levelNum;
}

bool CElevator::checkIfCitizenHaveToLeaveElevator(CCitizen*& c, CElevator& e) 
{
	if (c->getPersonDestination() == e.getLevelNum())
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
	for (std::list<CCitizen*>::iterator it = elevator.requestsForUp.begin(); it != elevator.requestsForUp.end();) {
		if (checkIfCitizenHaveToLeaveElevator(*it, elevator)) {
			it = elevator.requestsForUp.erase(it);
		}
		else {
			++it;
		}
	}
	return false;
}

bool CElevator::dropFromMiddleForDown(CElevator& elevator) {
	for (std::list<CCitizen*>::iterator it = elevator.requestsForDown.begin(); it != elevator.requestsForDown.end();) {
		if (checkIfCitizenHaveToLeaveElevator(*it, elevator)) {
			it = elevator.requestsForDown.erase(it);
		}
		else {
			++it;
		}
	}
	return false;
}