#include "Plantation.h"
#include <iostream>
#include <string>

Plantation::Plantation(){}

Plantation::~Plantation(){}

std::string Plantation::checkField(int x, int y, int size) {
	int plants = 0, blanks = 0;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (board[i][j].isPlant)
				plants++;
			else
				blanks++;
		}
	}

	if (plants == size * size && !blanks) result += "1";
	else if (!plants && blanks == size * size) result += "0";
	else {
		result += "#";
		result = checkField(x, y, size / 2); //top left Q
		result = checkField(x + size / 2, y, size / 2); //top right Q.
		result = checkField(x, y + size / 2, size / 2); //bottom left Q.
		result = checkField(x + size / 2, y + size / 2, size / 2); //bottom right Q
	}

	return result;
}

void Plantation::displayN() {
	std::cout << "N: " << n << std::endl;
}

void Plantation::displayBoard() {
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			std::cout << board[i][j].isPlant << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}