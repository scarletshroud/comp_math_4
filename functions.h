#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <string>

namespace fun 
{
	float lin(const float x, const float a, const float b);
	const std::string F1_STR = "2 * x + 3";

	float pol(const float x, const float a, const float b, const float c);
	const std::string F2_STR = "3 * x * x + 0.5 * x - 4";

	float exp(float x, const float a, const float b);
	const std::string F3_STR = "5 * exp(x) / 4";

	float log(float x, const float a, const float b);
	const std::string F4_STR = "log(x) / (x - 4)";

	float pow(float x, const float a, const float b);
	const std::string F5_STR = "2 ^ x";

	enum type
	{
		LINEAR,
		SQUARE,
		EXPONENTIAL,
		LOGARITHMIC,
		SEDATE
	};
};

#endif 

