#ifndef C_USER_INPUT
#define C_USER_INPUT
#include "CCitizen.h"
class CUserInput : public CCitizen
{
public:
	CUserInput(unsigned short levelOfBuilding);
	void showUserMenu();
	unsigned short userRequestDestination();
	unsigned short userRequestSpecialButtons();
};
#endif