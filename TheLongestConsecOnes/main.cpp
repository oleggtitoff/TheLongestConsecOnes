#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define INPUT_FILENAME "INPUT.TXT"
#define OUTPUT_FILENAME "OUTPUT.TXT"

#define SEARCHED_SYMBOL '1'

#define INPUT_ERROR_MESSAGE "Error! The file was not open for reading.\n"
#define OUTPUT_ERROR_MESSAGE "Error! The file was not open for writing.\n"


std::string readFromFile(std::string fileName)
{
	std::ifstream fileInput(fileName);

	if (fileInput.is_open())
	{
		std::string buff;

		std::getline(fileInput, buff);
		fileInput.close();

		return buff;
	}
	
	throw INPUT_ERROR_MESSAGE;
}


void writeToFile(std::string fileName, std::string data)
{
	std::ofstream fileOutput(fileName);

	if (fileOutput.is_open())
	{
		fileOutput << data << std::endl;
		fileOutput.close();

		return;
	}
	
	throw OUTPUT_ERROR_MESSAGE;
}


int symbolConsecCounter(std::string str)
{
	int maxCount = 0;
	int currCount = 0;

	for (auto it = str.begin(); it < str.end(); it++)
	{
		if (*it == SEARCHED_SYMBOL)
		{
			currCount++;
		}
		else
		{
			maxCount = std::max(currCount, maxCount);
			currCount = 0;
		}
	}
	
	return maxCount;
}


int main(void)
{
	try
	{
		writeToFile(OUTPUT_FILENAME, std::to_string(symbolConsecCounter(readFromFile(INPUT_FILENAME))));
	}
	catch (const char *message)
	{
		std::cerr << message << std::endl;
	}
	
	return 0;
}