#include "data_saver.h"

bool DataSaver::saveDataToFile(const char* path, const std::vector<point>& input, const std::vector<float>& result) 
{
	std::ofstream out(path);

	if (!out.is_open())
		return false;

	if (result.empty())
		return false;

	for (size_t i = 0; i < input.size(); ++i)
	{
		out << input[i].x << " " << input[i].y << " " << result[i] << std::endl;
	}

	out.close(); 

	return true;
}

bool DataSaver::saveDataToFile(const char* path, const std::vector<point>& input, std::vector<Answer> answers)
{
	std::ofstream out(path);

	if (!out.is_open())
		return false;


	for (size_t i = 0; i < input.size(); ++i)
	{
		out << input[i].x << " " << input[i].y << " ";

		for (size_t j = 0; j < answers.size(); ++j)
		{
			if (answers[j].values().empty())
				break;

			out << answers[j].values()[i] << " ";
		}

		out << std::endl;
	}

	out.close();

	return true;
}