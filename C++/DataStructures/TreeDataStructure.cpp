// TreeDataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
class Solmu {
public:
	
	Solmu(std::string data, int x, int y, int z) : _data(data), _x(x), _y(y), _z(z) {}

	std::string _data;
	int _x, _y, _z;
	Solmu* _parent = nullptr;
	std::vector<Solmu*> _childs;
};

void lapikaynti(Solmu* s) {

	if (s == nullptr)
		return;


	for (auto obj : s->_childs) {
		lapikaynti(obj);
		
	}
	if (s->_parent != nullptr) {
		s->_x = s->_x + s->_parent->_x;
		s->_y = s->_y + s->_parent->_y;
		s->_z = s->_z + s->_parent->_z;
	}
	std::cout << s->_data << "\nx: " << s->_x << "\ny: " << s->_y << "\nz: " << s->_z << "\n";
}

int main()
{
	Solmu A("root", 0,0,0), B("B", 1,0,0), C("C", 0,1,0), D("D", 0,0,1), E("E", 1,0,0), F("F",0,1,0), G("G",0,0,1), H("H",1,0,0), I("I",0,1,0), J("J",1,0,0), K("K",0,1,0);
	
	A._childs.push_back(&B);
	A._childs.push_back(&C);
	A._childs.push_back(&D);
	
	B._childs.push_back(&E);
	B._childs.push_back(&F);
	B._childs.push_back(&G);
	B._parent = &A;
	
	C._childs.push_back(&H);
	C._childs.push_back(&I);
	C._parent = &A;
	
	D._childs.push_back(&J);
	D._childs.push_back(&K);
	D._parent = &A;

	E._parent = &B;
	F._parent = &B;
	G._parent = &B;
	H._parent = &C;
	I._parent = &C;
	J._parent = &D;
	K._parent = &D;
	lapikaynti(&A);

	return 0;
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
