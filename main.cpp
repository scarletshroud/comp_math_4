#include <iostream>

#include "console_reader.h"
#include "plot_printer.h"
#include "file_reader.h"
#include "square_method.h"
#include "data_saver.h"
#include "answer.h"
#include "function.h"
#include "point.h"

#define POINTS_AMOUNT 7

Answer findBestOption(std::vector<Answer>& answers)
{
	Answer bestAnswer = answers[0];
	float minStandartDeviation = answers[0].standartDeviation();

	for (size_t i = 0; i < answers.size(); ++i)
	{
		if (answers[i].standartDeviation() < minStandartDeviation)
		{
			minStandartDeviation = answers[i].standartDeviation();
			bestAnswer = answers[i];
		}
			
	}

	return bestAnswer;
}

int main()
{
	SquareMethod squareMethod;

	ConsoleReader consoleReader;
	FileReader fileReader;

	PlotPrinter plotPrinter;

	Function function;

	std::vector<point> points;

	const char* userInputPath = "userInput.txt";
	fileReader.readInput(userInputPath, points, POINTS_AMOUNT);
	
	std::vector<Answer> answers;
	
	answers.push_back(squareMethod.linApproximate(points)); 
	answers.push_back(squareMethod.sqrApproximate(points));
	answers.push_back(squareMethod.expApproximate(points));
	answers.push_back(squareMethod.powApproximate(points));
	answers.push_back(squareMethod.logApproximate(points));

	Answer bestAnswer = findBestOption(answers);
	DataSaver dataSaver;

	if (bestAnswer.values().empty())
	{
		std::cout << "Unable to find approximation";
		return 0;
	}

	const char* allOptionsPath = "all_options.txt";
	dataSaver.saveDataToFile(allOptionsPath, points, answers);

	const char* resultPath = "result.txt";
	dataSaver.saveDataToFile(resultPath, points, bestAnswer.values());


	plotPrinter.printPlotToPng("res.png", resultPath, 1);
	plotPrinter.printPlotToPng("all.png", allOptionsPath , 5);

	switch (bestAnswer.type())
	{
		case fun::LINEAR:
			std::cout << "Best Approximate Function: Linear" << std::endl;
			std::cout << "Corellation: " << bestAnswer.corellation() << std::endl;
			break;

		case fun::EXPONENTIAL:
			std::cout << "Best Approximate Function: Exponential" << std::endl;
			break;

		case fun::LOGARITHMIC:
			std::cout << "Best Approximate Function: Logarithmic" << std::endl;
			break;

		case fun::SEDATE:
			std::cout << "Best Approximate Function: Sedate" << std::endl;
			break;

		case fun::SQUARE:
			std::cout << "Best Approximate Function: Square" << std::endl;
			break;
	}

	std::cout << "Standart Deviation: " << bestAnswer.standartDeviation() << std::endl; 

	return 0;
}