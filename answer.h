#ifndef _ANSWER_H_
#define _ANSWER_H_

#include "functions.h"

#include <vector>

class Answer
{
public:
	Answer();
	Answer(std::vector<float> values, float standartDeviation, float correlation, float credibility, fun::type type);
	~Answer();

	float corellation();
	float credibility();
	float standartDeviation();

	std::vector<float>& values();

	fun::type type();

private: 
	float m_standartDeviation;
	float m_corellation;
	float m_credibility; 

	std::vector<float> m_values;

	fun::type m_type;
};

#endif
