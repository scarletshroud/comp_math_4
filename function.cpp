#include "function.h"

#include <string>

Function::Function() {
}

Function::Function(std::function<double(double)> f, const std::string str)
{
	m_f = f;
	m_df = 0;
	m_d2f = 0;
	m_str = str;
}

Function::~Function()
{
}

std::function<double(double)> Function::f()
{
	return m_f;
}

std::function<double(double)> Function::df()
{
	return m_df;
}

std::function<double(double)> Function::d2f()
{
	return m_d2f;
}

const std::string& Function::str()
{
	return m_str;
}