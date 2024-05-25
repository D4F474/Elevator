#include "CCitizen.h"

CCitizen::CCitizen(unsigned short level)
{
	setLevelOfBuilding(level);
	setPersonLevel(randomNumberForCurrentLevel());
	setPersonDestination(randomNumberForDestination());
}

CCitizen::CCitizen(unsigned short level, unsigned short currlevel)
{
	setLevelOfBuilding(level);
	system("CLS");
	std::cout << "From 1 to " << getLevel() << std::endl;
	std::cout << "Which floor you want to be: ";				std::cin >> currlevel;
	setPersonLevel(currlevel);
}

void CCitizen::setPersonLevel(unsigned short level) { personLevel = level; }

void CCitizen::setPersonDestination(unsigned short level) { personDestination = level; }

void CCitizen::setLevelOfBuilding(unsigned short level) { buildingLevels = level; }

unsigned short CCitizen::getPersonLevel() const { return personLevel; }

unsigned short CCitizen::getPersonDestination() const { return personDestination;}

unsigned short CCitizen::randomNumberForDestination() 
{
	unsigned short generatedNum = 0;
	generatedNum = rand() % getLevel() + 1;
	while(generatedNum == personLevel || generatedNum == 4)
	{
		generatedNum = rand() % getLevel() + 1;
	}
	return generatedNum;
}

unsigned short CCitizen::randomNumberForCurrentLevel() 
{
	unsigned short random = rand() % getLevel() + 1;
		random = rand() % getLevel() + 1;
	personLevel = random;
	return personLevel;
}

unsigned short CCitizen::getLevel() const { return buildingLevels; }
std::ostream& operator << (std::ostream& toStream, const CCitizen& citizen) 
{
	toStream <<
		"Destination: " << citizen.personDestination << std::endl
		<<"Current level: " << citizen.personLevel << std::endl;
	return toStream;
}