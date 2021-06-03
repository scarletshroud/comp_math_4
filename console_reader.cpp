#include "console_reader.h"

#include "function.h"
#include "functions.h"

#include <iostream>

void ConsoleReader::readInput(std::vector<point>& points, const size_t pointsAmount)
{
	std::vector<point> _points(pointsAmount);
	
	std::cout << "Enter the points (Format: X Y)" << std::endl;

	for (size_t i = 0; i < pointsAmount; ++i) 
	{
		std::cin >> _points[i].x;
		std::cin >> _points[i].y;
	}

	points = _points;
}