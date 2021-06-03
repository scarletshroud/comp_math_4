#ifndef _PLOT_PRINTER_H_
#define _PLOT_PRINTER_H_

#include <string>

#include "gnuplot.h"

class PlotPrinter {
public:
	PlotPrinter();
	~PlotPrinter();

	void printPlotToPng(const char* outputPath, const char* dataPath, const size_t cols);

private:
	Gnuplot m_gnuplot;
};

#endif

