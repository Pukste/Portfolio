// Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define Arraysize 200
int eka[Arraysize];
int toka[Arraysize];
int kolmas[Arraysize];

void bubbleSort(int arr[]){
	
	int _temp;
	
	bool _swapped = false;
	for (int k = 0; k < Arraysize; k++) {
		_swapped = false;

		for (int l = 0; l < Arraysize-l; l++) {
			if (arr[l] > arr[l + 1]) {
				_temp = arr[l];
				arr[l] = arr[l + 1];
				arr[l + 1] = _temp;
				_swapped = true;
			}

	}
		if (!_swapped)
			break;
	
	}
	std::cout << "bubble\n";
	for (int i = 0; i < Arraysize; i++) {
		std::cout << arr[i] << "\n";
	}
}
void insertionSort(int arr[]) {
	int _insertion;
	int _position;

	for (int n = 0; n < Arraysize; n++) {
		_insertion = arr[n];
		_position = n;
		
		while (_position > 0 && arr[_position - 1] > _insertion) {
			arr[_position] = arr[_position - 1];
			_position--;
		}
		if (_position!=n){
			arr[_position] = _insertion;
		}
	}
	std::cout << "insertion\n";
	for (int i= 0; i < Arraysize; i++) {
		std::cout << arr[i]<<"\n";
	}
}


int main()
{
	for (int i = 0; i < Arraysize; i++) {
		eka[i] = rand() % Arraysize;
		toka[i] = i;
	}
	for (int j = Arraysize-1; j > 0; j--) {
		kolmas[j] = j;
	}

	bubbleSort(eka);
	insertionSort(eka);
	bubbleSort(toka);
	insertionSort(toka);
	bubbleSort(kolmas);
	insertionSort(kolmas);
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
