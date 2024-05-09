#ifndef C_BUILDING
#define C_BUILDING
#include <iostream>
#include <list>
#include <vector>

#include "CCitizen.h"

const unsigned short HEIGHT = 5;
const unsigned short WIDTH = 5;

class CBuilding
{
private:
	unsigned short Levels;
	std::list<CCitizen*> BuildWaiters;
protected:
	std::vector<char*> matrix;
public:
	CBuilding();
	CBuilding(unsigned short levels);
	void setLevels(unsigned short levels);
	unsigned short getLevels() const;
	void getMatrix() const;
	void addBuildWaiters(CCitizen& citizen);
	void removeBuildWaiters();
	CCitizen* getWaiter();
	std::list<CCitizen*> waiters();
	void sortWaiters();
};

#endif