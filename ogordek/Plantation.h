#pragma once
#include <vector>
#include <string>
#include "Tile.h"

class Plantation
{
public:
	Plantation();
	~Plantation();
	int n = -1;
	std::vector<std::vector<Tile>> board;
	std::string result;

	std::string checkField (int x, int y, int size);
private:
	
};

