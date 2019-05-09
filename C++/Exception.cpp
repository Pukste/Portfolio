#include <iostream>


int main()
{

	unsigned long a = 100000000;
	int kerrat = 0;
	try {
		while (true) {
			kerrat++;
			new int[a];

		}
	}
	catch (const std::bad_alloc & e) {
		std::cout << "Allocation failed: " << e.what() << '\n' << kerrat << " kertaa";
	}
}