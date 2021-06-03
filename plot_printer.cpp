#include "plot_printer.h"

PlotPrinter::PlotPrinter() : m_gnuplot()
{
}

PlotPrinter::~PlotPrinter() {

}

void PlotPrinter::printPlotToPng(const char* outputPath, const char* dataPath, const size_t cols)
{
	//m_gnuplot("set xrange [" + std::to_string(a) + ":" + std::to_string(b) + "]");

	//double step = (b - a) / 2;

	//m_gnuplot("set yrange [" + std::to_string(-step) + ":" + std::to_string(step) + "]");

	m_gnuplot("set grid");

	m_gnuplot("set xzeroaxis lt -1");
	m_gnuplot("set yzeroaxis lt -1");

	m_gnuplot("set xlabel \"X\"");
	m_gnuplot("set ylabel \"Y\"");

	m_gnuplot("set terminal png size 1024, 1024");

	std::string output = std::string(outputPath); 
	m_gnuplot("set output \"" + output + "\"");

	std::string data = std::string(dataPath);

	std::string command = "plot \"" + data + "\" using 1:2 with lines, "; 

	for (size_t i = 3; i < 3 + cols; ++i)
	{
		command.append("\"" + data + "\" using 1:" + std::to_string(i) + " with lines, ");
	}

	m_gnuplot(command);
}