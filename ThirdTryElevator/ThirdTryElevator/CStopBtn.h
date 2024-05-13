#ifndef C_STOP_BTN
#define C_STOP_BTN
#include "CDisplay.h"
#include <thread>
#include <chrono>
class CStopBtn : public CDisplay
{
public:
	void showTextOnDisplay(CElevator*& elevator) override;
	void stopElev();
};
#endif