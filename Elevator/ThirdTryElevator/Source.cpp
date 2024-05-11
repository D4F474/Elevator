#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "CEngine.h"

int main()
{
	srand(time(NULL));
	CEngine* engine = new CEngine();
	std::cout << std::endl << "Congrats we work good!";
	return 0;
}