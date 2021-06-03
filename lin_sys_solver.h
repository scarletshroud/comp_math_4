#ifndef _LIN_SYS_SOLVER_H_
#define _LIN_SYS_SOLVER_H_

#include "augmented_matrix.h"

class LinSysSolver
{
public:
	LinSysSolver();
	~LinSysSolver();

	std::vector<float> solve(AugmentedMatrix& matrix); 
};


#endif // !_LIN_SYS_SOLVER_H_
