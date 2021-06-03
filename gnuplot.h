#ifndef _GNUPLOT_H_
#define _GNUPLOT_H_

#include <string>
#include <cstdio>
#include <iostream>

#ifdef WIN32
#define GNUPLOT_NAME "gnuplot -persist"
#else
#define GNUPLOT_NAME "gnuplot -persist"
#endif

class Gnuplot
{
public:
	Gnuplot();
	~Gnuplot();

	void operator ()(const std::string& command);

private:
	FILE* gnuplotpipe;
};

#endif



