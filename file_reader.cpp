#include "file_reader.h"

bool FileReader::readInput(const char* path, std::vector<point>& points, const size_t pointsAmount)
{
	std::ifstream input(path); 

	std::vector<point> _points(pointsAmount);

	if (!input.is_open())
		return false;

	for (size_t i = 0; i < pointsAmount; ++i)
	{
		input >> _points[i].x;
		input >> _points[i].y;
	}

	input.close();

	points = _points;

	return true;
}