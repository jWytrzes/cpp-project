#include <iostream>
#include <fstream>
#include <string>
#include "Gardenencode.h"

using namespace std;

int main()
{
	char choice;
	cout << "Wybierz operacje: " << endl;
	cout << "e - enkoduj z pliku data.txt" << endl;
	cout << "d - dekoduj z pliku data2.txt" << endl;

	cin >> choice;

	GardenEncode gardenEncode;

	switch (choice) {
	case 'e':
		gardenEncode.encode();
		break;
	case 'd':
		cout << "Operacja niedostepna" << endl;
		break;
	}

	system("pause");
}	
