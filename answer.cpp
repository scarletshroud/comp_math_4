#include "answer.h"

Answer::Answer() 
{
	m_values = std::vector<float>(0);
	m_standartDeviation = 999999999999999;
	m_corellation = 0;
	m_credibility = 0;
	m_type = fun::LINEAR;
}

Answer::Answer(std::vector<float> values, float standartDeviation, float correlation, float credibility, fun::type type)
{
	m_values = values;
	m_standartDeviation = standartDeviation;
	m_corellation = correlation;
	m_credibility = credibility; 
	m_type = type;
}

Answer::~Answer()
{
}

float Answer::corellation()
{
	return m_corellation;
}

float Answer::credibility()
{
	return m_credibility;
}

float Answer::standartDeviation()
{
	return m_standartDeviation;
}

std::vector<float>& Answer::values()
{
	return m_values;
}

fun::type Answer::type()
{
	return m_type;
}