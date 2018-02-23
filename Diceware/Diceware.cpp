#include "Diceware.h"
#include <random>

Diceware::Diceware::Diceware(int numElements, int maxPage, int maxCols, int maxRow) 
	:mNumElements(numElements)
	,mMaxPage(maxPage)
	,mMaxCols(maxCols)
	,mMaxRow(maxRow)
{

}

std::vector<Diceware::tElement>& Diceware::Diceware::generateElements(void)
{
	int i;

	std::random_device rd;   // non-deterministic generator  
    std::mt19937 gen(rd());  // to seed mersenne twister.  

    std::uniform_int_distribution<> distPage(1, mMaxPage); // distribute results between 1 and 6 inclusive.  
    std::uniform_int_distribution<> distCol(1, mMaxCols); // distribute results between 1 and 6 inclusive.  
    std::uniform_int_distribution<> distRow(1, mMaxRow); // distribute results between 1 and 6 inclusive.  

	for (i=0; i<mNumElements; i++)
	{
		//generate random page
		//generate random row
		//generate random column

		tElement newElement = {distPage(gen), distCol(gen), distRow(gen)};
		mGeneratedElements.push_back(newElement);
	}
	return mGeneratedElements;
}

Diceware::Diceware::~Diceware(void)
{
}
