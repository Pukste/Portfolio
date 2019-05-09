// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int recfunc(int n) {
	
	if (n == 0)
		return 0;
	else if (n == 1)
		return 2;
	else
		return recfunc(n - 1) + 3;
}


int main()
{
	int a = 2;
	int n = 8;
	std::cout << "Recursive";
	for (int i = 0; i < n; i++) {
		std::cout << "\n" << recfunc(i);
	}
	std::cout << "\nIterative";
	for (int j = 0; j < n; j++) {
		std::cout <<"\n"<< a + j * 3;
	}
}

