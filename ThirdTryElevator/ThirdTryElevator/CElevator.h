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
	std::list<unsigned short> requestsForUp;
	std::list<unsigned short> requestsForDown;
	// elevator possition
public:
	CElevator();
	CElevator(unsigned short levels);
	void moveUpElevator();
	void moveDownElevator();
	void changeIfIsUpOrDown();
	bool checkIfIsUp();
	bool checkDoorIsOpen();
	void openOrCloseDoor();
	std::list<unsigned short> getRequestsForUp();
	void removeRequestForUp();
	void removeRequestForDown();
	std::list<unsigned short> getRequestsForDown();
	unsigned short getLevelNum() const;
	void incementOrDecrementLevelNum(bool isTrue);
	unsigned short getCurrLevel();
	void addForUp(unsigned short citizenLevel);
	void addForDown(unsigned short citizenLevel);
	void dropForUp();
	//TODO WRITE THIS FUNCTIONS TO DELETE DAMN MIDDLE ELEMENTS FROM LIST
	bool dropFromMiddleForUp(CElevator& elevator);
	void dropForDown();
	bool dropFromMiddleForDown(CElevator& elevator);
	bool checkIfCitizenHaveToLeaveElevator(unsigned short c, CElevator& e);

};
#endif