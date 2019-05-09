#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int taulukko[10] = { 4,3,1,8,9 };
	int size = 5;
	int index = 3;
	printf("Taulukko ennen :\n");

	for (int i = 0; i < 10; i++) {
		printf("Taulukko[%d] = %d \n", i, taulukko[i]);
	}

	void remove(int* taulukko, int size, int value); {

		for (int i = index; i < size; i++) {
			taulukko[i] = taulukko[i + 1];
		};



		printf("Taulukko jälkeen :\n");

		for (int i = 0; i < 10; i++) {
			printf("Taulukko[%d] = %d \n", i, taulukko[i]);
		}
	}
}