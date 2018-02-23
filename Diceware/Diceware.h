#pragma once

#include <vector>

namespace Diceware 
{

struct tElement
{
	int page;
	int column;
	int row;
};

class Diceware
{

public:
	Diceware(int numElements, int maxPage, int maxCols, int maxRow);
	~Diceware(void);

	std::vector<tElement>& generateElements(void);

private:
	int mNumElements;
	int mMaxPage;
	int mMaxCols;
	int mMaxRow;

	std::vector<tElement> mGeneratedElements;	

};

}