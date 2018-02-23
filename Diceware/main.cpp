#include "Diceware.h"
#include <iostream>
#include <string>

void parseOpt(const char* optStr, char** argv, int index, int* number)
{
	if(std::strcmp(argv[index], optStr) == 0)
	{
		try 
		{
			*number = std::stoi(argv[index+1]);
		}
		catch (std::exception e)
		{
		}
	}
}

int main(int argc, char ** argv)
{
	int maxPage = 1;
	int numWords = 1;
	int numCol = 1;
	int numRow = 1;
	for (int opt = 0; opt < argc; ++opt)
	{
		
		parseOpt("-w", argv, opt, &numWords);
		parseOpt("-p", argv, opt, &maxPage);
		parseOpt("-r", argv, opt, &numRow);
		parseOpt("-c", argv, opt, &numCol);
		
	}

	Diceware::Diceware dice(numWords, maxPage, numCol, numRow);

	std::vector<Diceware::tElement> words = dice.generateElements();

	std::vector<Diceware::tElement>::iterator it;
	for (it = words.begin(); it < words.end(); it++)
	{
		std::cout << "(" << (*it).page << ", " << (*it).column << ", " << (*it).row << ") " << std::endl;		
	}

	std::cout << "Press ENTER to exit..." ;
	std::cin.get();
	return 0;
}