#include <iostream>;
using namespace std;

int main() {

	int taulukko[10] = { 4,3,1,8,9 };
	int size = 10;
	int value = 5;
	bool find(const int* taulukko, int size, int value); {

		for (int i = 0; i < size; i++) {
			if (taulukko[i] == value) {
				printf("juu");
				return true;
			}
		};
		printf("ei");
		return false;



	}





}