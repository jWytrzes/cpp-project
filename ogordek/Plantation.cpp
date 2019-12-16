#include "Plantation.h"
#include <iostream>
#include <string>

Plantation::Plantation() {}
Plantation::~Plantation() {}

std::string Plantation::checkField(int x, int y, int size) {
	int plants = 0;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (board[i][j] == Tile::Plant) {
				plants++;
			}
		}
	}
	int blanks = size * size - plants;

	if (plants == size * size) {
		result += "1";
	}

	else if (blanks == size * size) {
		result += "0";
	}

	else {
		result += "#";
		result = checkField(x, y, size / 2); //top left Q
		result = checkField(x + size / 2, y, size / 2); //top right Q
		result = checkField(x, y + size / 2, size / 2); //bottom left Q
		result = checkField(x + size / 2, y + size / 2, size / 2); //bottom right Q
	}

	return result;
}