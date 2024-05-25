#ifndef C_USER_INPUT
#define C_USER_INPUT
#include "CCitizen.h"
#include "CDoorBtn.h"
#include "CStopBtn.h"
#include "CEmergencyBtn.h"
class CUserInput : public CCitizen
{
private:
	CDoorBtn* doorBtn;
	CStopBtn* stopBtn;
	CEmergencyBtn* emergencyBtn;
public:
	CUserInput(unsigned short levelOfBuilding);
	void showUserMenu();
	unsigned short userRequestDestination();
    void userRequestSpecialButtons(CElevator*& elevator);
};
#endif