#include "gnuplot.h"

Gnuplot::Gnuplot()
{
#ifdef WIN32
	gnuplotpipe = _popen(GNUPLOT_NAME, "w");
#else
	gnuplotpipe = popen(GNUPLOT_NAME, "w");
#endif

	if (!gnuplotpipe)
	{
		std::cout << "Gnuplot not found!";
	}
}

Gnuplot::~Gnuplot()
{
	fprintf(gnuplotpipe, "exit\n");

#ifdef WIN32
	_pclose(gnuplotpipe);
#else
	pclose(gnuplotpipe);
#endif
}

void Gnuplot::operator()(const std::string& command)
{
	fprintf(gnuplotpipe, "%s\n", command.c_str());
	fflush(gnuplotpipe);
}