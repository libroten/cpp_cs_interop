#pragma once

#ifdef MINIMIZER_EXPORTS
#define MINIMIZER_API __declspec(dllexport)
#else
#define MINIMIZER_API __declspec(dllimport)
#endif

//Class that implements function to minimize.
class MINIMIZER_API Function
{
public:
	virtual double Evaluate(double point) = 0;
	
	virtual double GetLowerBound() = 0;
	virtual double GetUpperBound() = 0;
};


//Class that implements minimizing algo
class MINIMIZER_API Minimizer
{
public:
	double FindOptimum(Function* func);
	double GetOptPoint();
	double GetOptValue();

private:
	double m_optPoint;
	double m_optValue;

};