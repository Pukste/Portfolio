// Pino.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


class String_Pino {
	int stackSize = 20;
	int top = -1;
	std::string pino[20];
	
public:
	void push(std::string input) {
		if (top < 20) {
			top = top + 1;
			pino[top] = input;
			
		}
		else
			std::cout << "Pino on täysi\n";
	}
	
	
	

	std::string pop() {
		if (top < 0) {
			std::cout << "Pino on tyhjä\n";
		}
		else {
			std::string data = pino[top];
			top = top - 1;
			return "data";
		}
	}



};



int main() {
	String_Pino p;
	std::string a("A");
	std::string b("B");
	std::string c("C");
	std::string d("D");
	std::string e("E");
	std::string f("F");
	std::string g("G");
	std::string h("H");
	std::string i("I");
	std::string j("J");
	


	p.push(a);
	p.push(b);
	p.push(c);
	p.push(d);
	p.push(e);
	p.push(f);
	p.push(g);
	p.push(h);
	p.push(i);
	p.push(j);

	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";
	std::cout << p.pop() << "\n";



}

