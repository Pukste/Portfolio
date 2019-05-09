// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#define size 1000

int taulukko[size];

void find(int data) {
	int _lowerbound = 0;
	int _upperbound = size;
	int _midpoint = 0;
	int _comparisons = 0;


	while (_lowerbound <= _upperbound) {
		_comparisons++;
		_midpoint = (_lowerbound + _upperbound) / 2;
		if (taulukko[_midpoint] == data) {
			std::cout << data << "\njuu\n" << _comparisons << " split\n";
			return;
		}
		else {
			if (taulukko[_midpoint] < data)
				_lowerbound = _midpoint + 1;
			else
				_upperbound = _midpoint - 1;
		}
	}
	

}

int main()
{


	for (int i = 0; i < size; i++) {
		taulukko[i] = rand() % 1000 + 1;
	}
	std::sort(taulukko, taulukko + size);



	
	find(150);
	find(300);
	find(750);

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
