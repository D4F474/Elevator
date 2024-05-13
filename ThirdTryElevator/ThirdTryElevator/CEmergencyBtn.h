#ifndef C_EMERGENCY_BTN
#define C_EMERGENCY_BTN

#include "CDisplay.h"

class CEmergencyBtn : public CDisplay
{
public:
	void showTextOnDisplay(CElevator*& elevator) override;
	void emergencyCall();
};
#endif