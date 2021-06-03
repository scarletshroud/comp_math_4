#ifndef _SQUARE_METHOD_H_
#define _SQUARE_METHOD_H_

#include <vector>
#include <functional>

#include "point.h"
#include "answer.h"

class SquareMethod
{
public:
	SquareMethod();
	~SquareMethod();

	Answer linApproximate(std::vector<point> points); 
	Answer sqrApproximate(std::vector<point> points); 
	Answer powApproximate(std::vector<point> points);
	Answer expApproximate(std::vector<point> points);
	Answer logApproximate(std::vector<point> points);

private:
	float calculateCorrelationCoefficient(const std::vector<point>& points, const std::vector<float>& values);

	float findDeviation(std::function<float(const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b);
	float findDeviation(std::function<float(const float, const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b, const float c);

	float findStandartDeviation(const float deviation, const size_t n);

	float findCredibility(std::function<float(const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b);
	float findCredibility(std::function<float(const float, const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b, const float c);

};

#endif