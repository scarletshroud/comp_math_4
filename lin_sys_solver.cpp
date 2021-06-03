#include "lin_sys_solver.h"

LinSysSolver::LinSysSolver()
{

}

LinSysSolver::~LinSysSolver()
{

}

std::vector<float> LinSysSolver::solve(AugmentedMatrix& matrix)
{
	std::vector<std::vector<float>> odds = matrix.odds();
	std::vector<float> free = matrix.freeMembers(); 

	for (size_t i = 0; i < matrix.rows(); ++i)
	{
		for (size_t j = i + 1; j < matrix.rows(); ++j) 
		{
			const float d = odds[j][i] / odds[i][i];

			for (size_t k = i; k < matrix.rows(); ++k)
			{
				odds[j][k] = odds[j][k] - d * odds[i][k];
			}

			free[j] = free[j] - d * free[i];
		}
	}

	std::vector<float> roots(matrix.rows(), 0);

	for (int i = matrix.rows() - 1; i >= 0; --i)
	{
		float d = 0;
		
		for (int j = i + 1; j < matrix.rows(); ++j)
		{
			float s = odds[i][j] * roots[j];
			d = d + s;
		}

		roots[i] = (free[i] - d) / odds[i][i];
	}

	return roots;
}