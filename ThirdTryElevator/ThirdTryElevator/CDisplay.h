#ifndef C_DISPLAY
#define C_DISPLAY
#include <iostream>
#include <iomanip>
#include "CElevator.h"
class CDisplay 
{
public:
	void showStatus(CElevator*& elevator);
	virtual void showTextOnDisplay(CElevator*& elevator);
};

#endif
