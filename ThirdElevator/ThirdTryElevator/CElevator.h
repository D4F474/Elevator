#ifndef C_ELEVATOR
#define C_ELEVATOR
#include <list>
#include <cmath>
//headers
#include "CBuilding.h"
#include "CCitizen.h"

#define MAX_KG_ELEVATOR 180

class CElevator : public CBuilding
{
private:
	bool isDoorOpen = false;
	bool isUp = true;
	unsigned short currLevel = 0;
	short levelNum = 1;
	std::list<CCitizen*> requestsForUp;
	std::list<CCitizen*> requestsForDown;
	// elevator possition
public:
	CElevator();
	CElevator(unsigned short levels);
	void moveUpElevator();
	void moveDownElevator();
	unsigned short callElevatorFromOutside();
	void changeIfIsUpOrDown();
	bool checkIfIsUp();
	std::list<CCitizen*> getRequestsForUp();
	void removeRequestForUp();
	void removeRequestForDown();
	std::list<CCitizen*> getRequestsForDown();
	unsigned short getLevelNum() const;
	void incementOrDecrementLevelNum(bool isTrue);
	unsigned short getCurrLevel();

	void addForUp(CCitizen& citizen);
	void addForDown(CCitizen& citizen);
	void dropForUp();
	//TODO WRITE THIS FUNCTIONS TO DELETE DAMN MIDDLE ELEMENTS FROM LIST
	bool dropFromMiddleForUp(CElevator& elevator);
	void dropForDown();
	bool dropFromMiddleForDown(CElevator& elevator);
	bool checkIfCitizenHaveToLeaveElevator(CCitizen*& c, CElevator& e);

};
#endif