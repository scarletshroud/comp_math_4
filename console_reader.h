#ifndef _CONSOLE_READER_H_
#define _CONSOLE_READER_H_

#include "point.h"
#include <vector>

class ConsoleReader
{
public:
	void readInput(std::vector<point>& points, const size_t pointsAmount);
};

#endif

