#ifndef C_ELEVATOR
#define C_ELEVATOR
#include <list>
#include <cmath>
#include <thread>

//headers
#include "CBuilding.h"
#include "CCitizen.h"

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
	std::list<unsigned short> getRequestsForUp();
	std::list<unsigned short> getRequestsForDown();
	unsigned short getLevelNum() const;
	unsigned short getCurrLevel();
	void moveUpElevator();
	void moveDownElevator();
	void openOrCloseDoor();
	void changeIfIsUpOrDown();
	void addForUp(unsigned short citizenLevel);
	void removeRequestForUp();
	void removeRequestForDown();
	void addForDown(unsigned short citizenLevel);
	bool dropFromMiddleForUp(CElevator& elevator);
	bool dropFromMiddleForDown(CElevator& elevator);
	bool checkIfIsUp();
	bool checkDoorIsOpen();
	bool checkIfCitizenHaveToLeaveElevator(unsigned short c, CElevator& e);
	void incementOrDecrementLevelNum(bool isTrue);
};
#endif