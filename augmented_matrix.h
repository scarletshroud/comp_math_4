#ifndef _AUGMENTED_MATRIX_H_
#define _AUGMENTED_MATRIX_H_

#include <vector>

class AugmentedMatrix
{
public:
	AugmentedMatrix(const size_t rows, const size_t cols); 
	~AugmentedMatrix(); 
	
	std::vector<std::vector<float>>& data();
	std::vector<std::vector<float>> odds();

	std::vector<float> freeMembers(); 

	size_t rows();
	size_t cols(); 

private:
	size_t m_rows;
	size_t m_cols; 

	std::vector<std::vector<float>> m_data;
};


#endif // !_AUGMENTED_MATRIX_H_

