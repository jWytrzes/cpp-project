#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "Gardenencode.h"
#include "Tile.h"

GardenEncode::GardenEncode(){}

GardenEncode::~GardenEncode(){}

void GardenEncode::encode() {
	loadData();

	for (int i = 0; i < plantations.size(); i++)
	{
		int boardSize = pow(2, plantations[i].n);
		plantations[i].checkField(0, 0, boardSize);
		std::cout << plantations[i].n << " " << plantations[i].result << std::endl;
	}
	std::cout << std::endl;

	saveResult();
}

void GardenEncode::loadData() {
	std::fstream dataFile;
	dataFile.open("data.txt", std::ios::in);

	std::string line;
	if (dataFile.good()) {

		
		Plantation plantation;

		while (getline(dataFile, line)) {
			if (line.length() < 1) {
				plantations.push_back(plantation);
				//wyswietlenie danych:
				//plantation.displayN();
				//plantation.displayBoard();

				plantation.board.clear();
				plantation.n = -1;
			}

			if (line.length() == 1) {
				plantation.n = stoi(line);				
				for (int i = 0; i < plantation.board.size(); i++) {
					plantation.board[i].clear();
				}
				plantation.board.clear();
			}

			else {
				std::vector<Tile> row;
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == '\0') break;

					char c = line[i];
					row.push_back(Tile(c - '0'));
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
	file.open("wynik.txt");
	
	for (int i = 0; i < plantations.size(); i++)
	{
		file << plantations[i].n << " " << plantations[i].result << std::endl;
	}

	std::cout << "Wynik zapisano do pliku wynik.txt" << std::endl;
	file.close();
}