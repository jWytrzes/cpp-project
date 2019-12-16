#pragma once
#include <string>
#include <vector>
#include "Plantation.h"

class Code
{
public:
	Code();
	~Code();
	int n;
	int result = 0;
	int stringPos = 0;
	std::string characters;
	std::vector<std::vector<Tile>> board;
	void countPlants();
	void createBoard();

private:
	void fillBoard(int x, int y, int size);
};

