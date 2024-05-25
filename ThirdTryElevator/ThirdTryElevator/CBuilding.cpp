#include "CBuilding.h"
CBuilding::CBuilding()
{
	setLevels(0);
}
CBuilding::CBuilding(unsigned short levels)
{
	BuildWaiters = std::list<CCitizen*>();
	setLevels(levels);
	for (int i = 0; i < HEIGHT * getLevels(); i++)
	{
		char* row = new char[WIDTH];
		for (int j = 0; j < WIDTH; j++)
		{
			row[j] = '|';
		}
		matrix.push_back(row);
		matrix[i][2] = 'O';
	}
}

void CBuilding::setLevels(unsigned short levels) {Levels = levels;}
unsigned short CBuilding::getLevels() const {return Levels;}
void CBuilding::getMatrix() const
{
	int level = getLevels();
	for (int i = 0; i < HEIGHT * getLevels(); i++)
	{
		if (i % HEIGHT == 0)
		{
			std::cout << "<--" << level-- << "-->" << std::endl;
		}
		for (int j = 0; j < WIDTH; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CBuilding::addBuildWaiters(CCitizen& citizen) {BuildWaiters.push_back(&citizen);}
void CBuilding::removeBuildWaiters() {BuildWaiters.pop_front();}

CCitizen* CBuilding::getWaiter() {return BuildWaiters.front();}

std::list<CCitizen*> CBuilding::waiters() {return BuildWaiters;}

void CBuilding::sortWaiters()
{
	BuildWaiters.sort([](CCitizen*& a, CCitizen*& b) { return a->getPersonLevel() < b->getPersonLevel(); });
}