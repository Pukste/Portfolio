// Jono.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class Solmu {
public:
	int _data;
	Solmu* _next = nullptr;
};


class Char_Jono {

	Solmu* _alku = nullptr;
	Solmu* _loppu = nullptr;


public:

	void enqueue(int data) {
		if (_alku == nullptr) {
			_alku = new Solmu();
			_alku->_data = data;
			_loppu = _alku;
		}
		else {

			Solmu* s = new Solmu();
			s->_data = _alku->_data;
			s->_next = _alku->_next;
			_alku->_next = s;
			_alku->_data = data;
			
			


			
		}

	};
	int dequeue() {
		Solmu* ptr = _alku;
		int paluu = _loppu->_data;
		while (ptr->_next!= nullptr) {
			ptr = ptr->_next;

		}
		ptr->_next = nullptr;
		delete(_loppu);
		_loppu = ptr;
		return paluu;

	
	
	};
};



int main()
{
	Char_Jono jono;
	jono.enqueue(1);
	jono.enqueue(2);
	jono.enqueue(3);
	jono.enqueue(4);
	std::cout << jono.dequeue() << "\n";
	std::cout << jono.dequeue() << "\n";
	std::cout << jono.dequeue() << "\n";
	std::cout << jono.dequeue() << "\n";
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
