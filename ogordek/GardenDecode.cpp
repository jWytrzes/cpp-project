#include "GardenDecode.h"
#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>

#define STD_OUTPUT_HANDLE ((DWORD)-11)

GardenDecode::GardenDecode() {}
GardenDecode::~GardenDecode() {}

void GardenDecode::decode() {
	loadData();

	std::cout << "\nWynik: \n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	for (int i = 0; i < codes.size(); i++) {
		int boardSize = pow(2, codes[i].n);
		codes[i].createBoard();
		codes[i].countPlants();
		std::cout << codes[i].result << std::endl;
	}
	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, 7);

	saveResult();
}

void GardenDecode::loadData() {
	std::ifstream dataFile;
	dataFile.open("data2.txt");

	if (dataFile.good()) {
		Code code;
		std::string line;
		while (getline(dataFile, line)) {
			code.characters = "";
			std::string numString = "";
			int i = 0;

			while (line[i] != ' ') {
				numString += line[i];
				i++;
			}
			i++;

			int num = std::stoi(numString);
			code.n = num;
			
			for (i; i < line.length(); i++) {
				code.characters += line[i];
			}
			codes.push_back(code);
		}
		dataFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
}

void GardenDecode::saveResult() {
	std::ofstream file;
	file.open("result2.txt");

	for (int i = 0; i < codes.size(); i++) {
		file << codes[i].result << std::endl;
	}

	std::cout << "Wynik zapisano do pliku result2.txt." << std::endl;
	std::cout << "------------------------------------\n\n" << std::endl;
	file.close();
}