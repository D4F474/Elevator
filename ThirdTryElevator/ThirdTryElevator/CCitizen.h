#ifndef C_CITIZEN
#define C_CITIZEN
#include <iostream>

class CCitizen 
{
private:
	unsigned short personLevel;
	unsigned short personDestination;
	unsigned short buildingLevels;
public:
	CCitizen(unsigned short level);
	CCitizen(unsigned short level, unsigned short currlevel);
	void setPersonLevel(unsigned short level);
	void setPersonDestination(unsigned short level);
	void setLevelOfBuilding(unsigned short level);
	unsigned short getPersonLevel() const;
	unsigned short getPersonDestination() const;
	unsigned short getLevel() const;
	unsigned short randomNumberForDestination();
	unsigned short randomNumberForCurrentLevel();

	friend std::ostream& operator << (std::ostream& toStream, const CCitizen& citizen);
};
#endif