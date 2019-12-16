#include <iostream>
#include "GardenEncode.h"
#include "GardenDecode.h"

int main() {
	char choice;
	while (1) {
		std::cout << "Wybierz operacje: " << std::endl;
		std::cout << "e - enkoduj z pliku data.txt" << std::endl;
		std::cout << "d - dekoduj z pliku data2.txt" << std::endl;
		std::cout << "x - wyjscie" << std::endl;

		std::cin >> choice;

		GardenEncode gardenEncode;
		GardenDecode gardenDecode;

		switch (choice) {
		case 'e':
			gardenEncode.encode();
			break;
		case 'd':
			gardenDecode.decode();
			break;
		case 'x':
			exit(0);
			break;
		default:
			std::cout << "Operacja niedostepna" << std::endl;
		}
	}
	system("pause");
}	
