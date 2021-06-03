#include "square_method.h"
#include "augmented_matrix.h"

#include "functions.h"
#include "lin_sys_solver.h"

#include <cmath>

SquareMethod::SquareMethod() 
{
}

SquareMethod::~SquareMethod() 
{
}

Answer SquareMethod::linApproximate(std::vector<point> points)
{
	float sx = 0;
	float sy = 0;
	float sxx = 0;
	float sxy = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		sx += points[i].x;
		sy += points[i].y;

		sxx += pow(points[i].x, 2);
		sxy += points[i].x * points[i].y;
	}

	float rows = 2;
	float cols = 3;

	float det = sxx * points.size() - sx * sx;
	float det_1 = sxy * points.size() - sx * sy;
	float det_2 = sxx * sy - sx * sxy;

	if (det == 0) {
		return Answer();
	}

	float a = det_1 / det; 
	float b = det_2 / det;

	std::vector<float> values(points.size()); 

	for (size_t i = 0; i < values.size(); ++i) 
	{
		values[i] = fun::lin(points[i].x, a, b);
	}

	float correlation = calculateCorrelationCoefficient(points, values);
	float deviation = findDeviation(fun::lin, points, a, b);
	float standartDeviation = findStandartDeviation(deviation, points.size());
	float credibility = findCredibility(fun::lin, points, a, b);

	return Answer(values, standartDeviation, correlation, credibility, fun::LINEAR);
}


Answer SquareMethod::powApproximate(std::vector<point> points)
{
	float sx = 0;
	float sy = 0;
	float sxx = 0;
	float sxy = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		if (points[i].y < 0 || points[i].x < 0)
		{
			return Answer();
		}

		sx += log(points[i].x);
		sy += log(points[i].y);

		sxx += std::pow(log(points[i].x), 2);
		sxy += log(points[i].x) * log(points[i].y);
	}

	float rows = 2;
	float cols = 3;

	float det = sxx * points.size() - sx * sx;
	float det_1 = sxy * points.size() - sx * sy;
	float det_2 = sxx * sy - sx * sxy;

	if (det == 0) {
		return Answer();
	}

	float A = det_1 / det;
	float B = det_2 / det;

	float a = std::pow(2.718, B);
	float b = A;

	std::vector<float> values(points.size());

	for (size_t i = 0; i < values.size(); ++i)
	{
		values[i] = fun::pow(points[i].x, a, b);
	}

	float correlation = calculateCorrelationCoefficient(points, values);
	float deviation = findDeviation(fun::pow, points, a, b);
	float standartDeviation = findStandartDeviation(deviation, points.size());
	float credibility = findCredibility(fun::pow, points, a, b);

	return Answer(values, standartDeviation, correlation, credibility, fun::SEDATE);
}

Answer SquareMethod::expApproximate(std::vector<point> points)
{
	float sx = 0;
	float sy = 0;
	float sxx = 0;
	float sxy = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		if (points[i].y < 0)
		{
			return Answer();
		}

		sx += points[i].x;
		sy += log(points[i].y);

		sxx += pow(points[i].x, 2);
		sxy += points[i].x * log(points[i].y);
	}

	float rows = 2;
	float cols = 3;

	float det = sxx * points.size() - sx * sx;
	float det_1 = sxy * points.size() - sx * sy;
	float det_2 = sxx * sy - sx * sxy;

	if (det == 0) {
		return Answer();
	}

	float A = det_1 / det;
	float B = det_2 / det;

	float a = std::pow(2.718, B);
	float b = A;

	std::vector<float> values(points.size());

	for (size_t i = 0; i < values.size(); ++i)
	{
		values[i] = fun::exp(points[i].x, a, b);
	}

	float correlation = calculateCorrelationCoefficient(points, values);
	float deviation = findDeviation(fun::exp, points, a, b);
	float standartDeviation = findStandartDeviation(deviation, points.size());
	float credibility = findCredibility(fun::exp, points, a, b);

	return Answer(values, standartDeviation, correlation, credibility, fun::EXPONENTIAL);
}

Answer SquareMethod::logApproximate(std::vector<point> points)
{
	float sx = 0;
	float sy = 0;
	float sxx = 0;
	float sxy = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		if (points[i].x < 0)
		{
			return Answer();
		}

		sx += log(points[i].x);
		sy += points[i].y;

		sxx += pow(log(points[i].x), 2);
		sxy += log(points[i].x) * points[i].y;
	}

	float rows = 2;
	float cols = 3;

	float det = sxx * points.size() - sx * sx;
	float det_1 = sxy * points.size() - sx * sy;
	float det_2 = sxx * sy - sx * sxy;

	if (det == 0) {
		return Answer();
	}

	float a = det_1 / det;
	float b = det_2 / det;

	std::vector<float> values(points.size());

	for (size_t i = 0; i < values.size(); ++i)
	{
		values[i] = fun::log(points[i].x, a, b);
	}

	float correlation = calculateCorrelationCoefficient(points, values);
	float deviation = findDeviation(fun::log, points, a, b);
	float standartDeviation = findStandartDeviation(deviation, points.size());
	float credibility = findCredibility(fun::log, points, a, b); 

	return Answer(values, standartDeviation, correlation, credibility, fun::LOGARITHMIC);
}

Answer SquareMethod::sqrApproximate(std::vector<point> points) 
{
	float sx = 0;
	float sxx = 0;
	float sxxx = 0;
	float sxxxx = 0;
	float sy = 0;
	float sxy = 0;
	float sxxy = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		sx += points[i].x;
		sxx += pow(points[i].x, 2);
		sxxx += pow(points[i].x, 3);
		sxxxx += pow(points[i].x, 4);

		sy += points[i].y;
		sxy += points[i].x * points[i].y;
		sxxy += pow(points[i].x, 2) * points[i].y;
	}

	size_t rows = 3;
	size_t cols = 4;

	AugmentedMatrix matrix(rows, cols);

	matrix.data()[0][0] = points.size();
	matrix.data()[0][1] = sx;
	matrix.data()[0][2] = sxx;
	matrix.data()[0][3] = sy;

	matrix.data()[1][0] = sx;
	matrix.data()[1][1] = sxx;
	matrix.data()[1][2] = sxxx;
	matrix.data()[1][3] = sxy;

	matrix.data()[2][0] = sxx;
	matrix.data()[2][1] = sxxx;
	matrix.data()[2][2] = sxxxx;
	matrix.data()[2][3] = sxxy;

	LinSysSolver solver;

	std::vector<float> roots = solver.solve(matrix);

	std::vector<float> values(points.size());

 	for (size_t i = 0; i < points.size(); ++i)
	{
		values[i] = fun::pol(points[i].x, roots[0], roots[1], roots[2]);
	}

	float correlation = calculateCorrelationCoefficient(points, values);
	float deviation = findDeviation(fun::pol, points, roots[0], roots[1], roots[2]);
	float standartDeviation = findStandartDeviation(deviation, points.size());
	float credibility = findCredibility(fun::pol, points, roots[0], roots[1], roots[2]);

	return Answer(values, standartDeviation, correlation, credibility, fun::SQUARE);
}

float SquareMethod::calculateCorrelationCoefficient(const std::vector<point>& points, const std::vector<float>& values)
{
	float avgX = 0;
	float avgY = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		avgX += points[i].x; 
		avgY += values[i];
	}

	avgX /= points.size(); 
	avgY /= points.size();

	float a = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		a += (points[i].x - avgX) * (values[i] - avgY);
	}

	float sumX = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		sumX += std::pow((points[i].x - avgX), 2);
	}

	float sumY = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		sumY += std::pow((values[i] - avgY), 2);
	}

	return a / sqrt(sumX * sumY);
}

float SquareMethod::findDeviation(std::function<float(const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b)
{
	float sum = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		sum += std::pow((f(points[i].x, a, b) - points[i].y), 2);
	}

	return sum;
}

float SquareMethod::findDeviation(std::function<float(const float, const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b, const float c)
{
	float sum = 0;

	for (size_t i = 0; i < points.size(); ++i)
	{
		sum += std::pow((f(points[i].x, a, b, c) - points[i].y), 2);
	}

	return sum;
}

float SquareMethod::findStandartDeviation(const float deviation, const size_t n)
{
	return sqrt(deviation / n);
}

float SquareMethod::findCredibility(std::function<float(const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b)
{
	float sum_1 = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		sum_1 += std::pow(points[i].y - f(points[i].x, a, b), 2);
	}

	float sum_2 = 0; 
	for (size_t i = 0; i < points.size(); ++i)
	{
		sum_2 += std::pow(f(points[i].x, a, b), 2);
	}

	float sum_3 = 0; 
	for (size_t i = 0; i < points.size(); ++i)
	{
		sum_3 += f(points[i].x, a, b);
	}

	sum_3 = std::pow(sum_3, 2);

	return 1 - sum_1 / (sum_2 - sum_3 / points.size());
}

float SquareMethod::findCredibility(std::function<float(const float, const float, const float, const float)> f, const std::vector<point>& points, const float a, const float b, const float c)
{
	float sum_1 = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		sum_1 += std::pow(points[i].y - f(points[i].x, a, b, c), 2);
	}

	float sum_2 = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		sum_2 += std::pow(f(points[i].x, a, b, c), 2);
	}

	float sum_3 = 0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		sum_3 += f(points[i].x, a, b, c);
	}

	sum_3 = std::pow(sum_3, 2);

	return 1 - sum_1 / (sum_2 - sum_3 / points.size());
}
