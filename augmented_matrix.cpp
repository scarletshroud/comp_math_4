#include "augmented_matrix.h"

AugmentedMatrix::AugmentedMatrix(const size_t rows, const size_t cols)
{
	m_rows = rows; 
	m_cols = cols;

	m_data = std::vector<std::vector<float>>(rows, std::vector<float>(cols));
}

AugmentedMatrix::~AugmentedMatrix() 
{

}

std::vector<std::vector<float>>& AugmentedMatrix::data() 
{
	return m_data;
}

std::vector<std::vector<float>> AugmentedMatrix::odds() 
{
	std::vector<std::vector<float>> odds = std::vector<std::vector<float>>(m_rows, std::vector<float>(m_cols - 1));
	
	for (size_t i = 0; i < m_rows; ++i) 
	{
		for (size_t j = 0; j < m_cols - 1; ++j)
		{
			odds[i][j] = m_data[i][j]; 
		}
	}
	
	return odds;
}

std::vector<float> AugmentedMatrix::freeMembers() 
{
	std::vector<float> members(m_rows);

	for (size_t i = 0; i < m_rows; ++i)
	{
		members[i] = m_data[i][m_cols - 1];
	}

	return members;
}

size_t AugmentedMatrix::cols() 
{
	return m_cols;
}

size_t AugmentedMatrix::rows() 
{
	return m_rows;
}