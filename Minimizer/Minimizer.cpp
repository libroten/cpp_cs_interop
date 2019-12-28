#include <cmath>
#include "Minimizer.h"

double Minimizer::FindOptimum(Function* func)
{
	double eps = 0.00001;

	double minX = func->GetLowerBound();
	double maxX = func->GetUpperBound();

	double delta = eps / 2;

	while (abs(maxX - minX) > eps)
	{
		double x1 = (minX + maxX) / 2 + delta;
		double x2 = (minX + maxX) / 2 - delta;

		double y1 = func->Evaluate(x1);
		double y2 = func->Evaluate(x2);

		if (y1 < y2)
		{
			maxX = x2;
		}
		else
		{
			minX = x1;
		}
	}

	m_optPoint = minX;
	m_optValue = func->Evaluate(minX);

	return m_optValue;
}

double Minimizer::GetOptPoint()
{
	return m_optPoint;
}

double Minimizer::GetOptValue()
{
	return m_optValue;
}