#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {

	int taulukko[10] = { 4,3,1,8,9 };
	int size = 5;
	int value = 8;
	int index = 2;

	void insert(int* taulukko, int size, int value, int index); {

		for(int i = size; i>=index; i--){
			taulukko[i + 1] = taulukko[i];
		};

		taulukko[index] = value;
		
		for (int j = 0; j < 10; j++) {
			cout << taulukko[j] + "\n";
		}


	}


}