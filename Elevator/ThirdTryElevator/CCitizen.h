#ifndef C_CITIZEN
#define C_CITIZEN
#include <iostream>

#define MIN_KG_FOR_CITIZEN 30
#define MAX_KG_FOR_CITIZEN 120
class CCitizen 
{
private:
	unsigned short personKg;
	unsigned short personLevel;
	unsigned short personDestination;
	unsigned short buildingLevels;
public:
	CCitizen(unsigned short level);
	void setPersonKg(unsigned short kg);
	void setPersonLevel(unsigned short level);
	void setPersonDestination(unsigned short level);
	void setLevelOfBuilding(unsigned short level);
	unsigned short getPersonKg();
	unsigned short getPersonLevel();
	unsigned short getPersonDestination();
	unsigned short randomNumberForDestination();
	unsigned short randomNumberForCurrentLevel();
	unsigned short randomKillogramsForPerson();
	unsigned short getLevel();

	friend std::ostream& operator << (std::ostream& toStream, const CCitizen& citizen);
};
#endif