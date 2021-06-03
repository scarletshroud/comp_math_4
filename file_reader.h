#ifndef _FILE_READER_H_
#define _FILE_READER_H_

#include "point.h"

#include <fstream>
#include <vector>

class FileReader
{
public:
	bool readInput(const char* path, std::vector<point>& points, const size_t pointsAmount);
};

#endif

