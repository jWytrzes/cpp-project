#include "Code.h"
#include <iostream>
#include "Tile.h"

Code::Code() {}
Code::~Code() {}

void Code::createBoard() {	
	int boardSize = pow(2, n);
	for (int i = 0; i < boardSize; i++) {
		std::vector<Tile> row;
		for (int j = 0; j < boardSize; j++) {
			row.push_back(Blank);
		}
		board.push_back(row);
	}
	fillBoard(0, 0, boardSize);
}

void Code::fillBoard(int x, int y, int size) {
	if (characters[stringPos] == '1') {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				board[j][i] = Plant;
			}
		}
		stringPos++;
	}

	else if (characters[stringPos] == '#') {
		stringPos++;
		fillBoard(x, y, size / 2); //top left Q
		fillBoard(x + size / 2, y, size / 2); //top right Q
		fillBoard(x, y + size / 2, size / 2); //bottom left Q
		fillBoard(x + size / 2, y + size / 2, size / 2); //bottom right Q
	}

	else {
		stringPos++;
	}
}

void Code::countPlants() {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j]) {
				result++;
			}
		}
	}
}