#include "Gardenencode.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Tile.h"
#include <windows.h>

#define STD_OUTPUT_HANDLE ((DWORD)-11)

GardenEncode::GardenEncode() {}
GardenEncode::~GardenEncode() {}

void GardenEncode::encode() {
	loadData();

	std::cout << "\nWynik: \n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	for (int i = 0; i < plantations.size(); i++) {
		int boardSize = pow(2, plantations[i].n);
		plantations[i].checkField(0, 0, boardSize);

		std::cout << plantations[i].n << " " << plantations[i].result << std::endl;
	}
	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, 7);

	saveResult();
}

void GardenEncode::loadData() {
	std::ifstream dataFile;
	dataFile.open("data.txt");

	if (dataFile.good()) {
		Plantation plantation;
		std::string line;
		while (getline(dataFile, line)) {
			if (line.length() == 1) {
				if (plantation.n > 0) {
					plantations.push_back(plantation);
				}

				plantation.n = stoi(line);
				for (int i = 0; i < plantation.board.size(); i++) {
					plantation.board[i].clear();
				}
				plantation.board.clear();
			}

			else {
				std::vector<Tile> row;
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == '\0') {
						break;
					}

					char c = line[i];
					Tile tile = c - '0' ? Tile::Plant : Tile::Blank;
					row.push_back(tile);
				}
				plantation.board.push_back(row);
			}
		}
		plantations.push_back(plantation);
		dataFile.close();
	}

	else {
		std::cout << "Unable to open file" << std::endl;
	}
}

void GardenEncode::saveResult() {
	std::ofstream file;
	file.open("result.txt");

	for (int i = 0; i < plantations.size(); i++) {
		file << plantations[i].n << " " << plantations[i].result << std::endl;
	}

	std::cout << "Wynik zapisano do pliku result.txt." << std::endl;
	std::cout << "-----------------------------------\n\n" << std::endl;
	file.close();
}
