#pragma once
#include <vector>
#include <string>
#include "Tile.h"

class Plantation
{
public:
	Plantation();
	~Plantation();
	int n;
	std::vector<std::vector<Tile>> board;
	std::string result;

	void displayN();
	void displayBoard();
	std::string checkField (int x, int y, int size);
private:
	
};

