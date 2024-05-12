#ifndef C_DISPLAY
#define C_DISPLAY
#include <iostream>
#include "CElevator.h"
class CDisplay
{
public:
	void showStatus(CElevator*& elevator);
	void showLevel(CElevator*& elevator);
	void showIfDoorIsOpen(CElevator*& elevator);
	void showAlarmButton(CElevator*& elevator);
};

#endif
