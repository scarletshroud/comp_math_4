#include "functions.h"
#include <cmath>

float fun::lin(const float x, const float a, const float b) {
	return a * x + b; 
}

float fun::pol(const float x, const float a, const float b, const float c) {
	return c * x * x + b * x + a; 
}

float fun::exp(float x, const float a, const float b) {
	return a * std::pow(2.718, b * x);
}

float fun::log(float x, const float a, const float b) {
	return a * std::log(x) + b;
}

float fun::pow(float x, const float a, const float b) {
	return a * std::pow(x, b);
}
