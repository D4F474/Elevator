#ifndef C_DOOR_BTN
#define C_DOOR_BTN

#include "CDisplay.h"
#include "CElevator.h"
class CDoorBtn : public CDisplay
{
public:
	void showTextOnDisplay(CElevator*& elevator) override;
	void openOrCloseDoor();
};
#endif