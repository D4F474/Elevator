#include "CCitizen.h"

CCitizen::CCitizen(unsigned short level)
{
	setLevelOfBuilding(level);
	setPersonLevel(randomNumberForCurrentLevel());
	setPersonDestination(randomNumberForDestination());
	setPersonKg(randomKillogramsForPerson());
}

void CCitizen::setPersonKg(unsigned short kg)
{
		personKg = kg;	
}

void CCitizen::setPersonLevel(unsigned short level)
{	
		personLevel = level;
}

void CCitizen::setPersonDestination(unsigned short level)
{
	personDestination = level;
}

void CCitizen::setLevelOfBuilding(unsigned short level)
{
	buildingLevels = level;
}
unsigned short CCitizen::getPersonKg()
{
	return personKg;
}

unsigned short CCitizen::getPersonLevel()
{
	return personLevel;
}

unsigned short CCitizen::getPersonDestination()
{
	return personDestination;
}

unsigned short CCitizen::randomNumberForDestination() 
{
	unsigned short generatedNum = 0;
	generatedNum = rand() % getLevel() + 1;
	if (generatedNum == getLevel())
	{
		randomNumberForDestination();
	}
	return generatedNum;
}

unsigned short CCitizen::randomNumberForCurrentLevel() 
{
	unsigned short random = rand() % getLevel() + 1;
	return random;
}

unsigned short CCitizen::randomKillogramsForPerson() 
{
	unsigned short random = rand() % 120 + 30;
	return random;
}

unsigned short CCitizen::getLevel() {
	return buildingLevels;
}
std::ostream& operator << (std::ostream& toStream, const CCitizen& citizen) 
{
	toStream << "KG: "<<citizen.personKg << std::endl <<
		"Destination: " << citizen.personDestination << std::endl
		<<"Current level: " << citizen.personLevel << std::endl;
	return toStream;
}


//TODO fix it

