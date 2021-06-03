#ifndef _DATA_SAVER_H_
#define _DATA_SAVER_H_

#include "point.h"
#include "answer.h"

#include <vector>
#include <fstream>

class DataSaver
{
public:
	bool saveDataToFile(const char* path, const std::vector<point>& data, const std::vector<float>& result);
	bool saveDataToFile(const char* path, const std::vector<point>& data, std::vector<Answer> answers);
};

#endif

