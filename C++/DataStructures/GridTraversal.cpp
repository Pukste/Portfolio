// Verkonlapikaunti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solmu {
public:
	std::string _nimi;
	std::vector<Solmu*> _naapurit;
	bool _vierailtu = false;
	

};

void verkonTulostus() {
	Solmu a, b, c, d, e, f, g, h;
	a._nimi = "A";
	b._nimi = "B";
	c._nimi = "C";
	d._nimi = "D";
	e._nimi = "E";
	f._nimi = "F";
	g._nimi = "G";
	h._nimi = "H";
	
	a._naapurit.push_back(&b);
	a._naapurit.push_back(&c);
	a._naapurit.push_back(&d);
	b._naapurit.push_back(&e);
	b._naapurit.push_back(&a);
	c._naapurit.push_back(&f);
	c._naapurit.push_back(&a);
	d._naapurit.push_back(&g);
	d._naapurit.push_back(&a);
	e._naapurit.push_back(&h);
	e._naapurit.push_back(&b);
	f._naapurit.push_back(&h);
	f._naapurit.push_back(&c);
	g._naapurit.push_back(&h);
	g._naapurit.push_back(&d);
	h._naapurit.push_back(&f);
	h._naapurit.push_back(&g);
	h._naapurit.push_back(&e);


	std::stack<Solmu*> stakki;

	a._vierailtu = true;
	std::cout << a._nimi;

	stakki.push(&a);
	Solmu* ptr = stakki.top();
	while (stakki.empty() == false) {
		
		for (int i = 0; i < ptr->_naapurit.size(); i++) {
			Solmu* obj = ptr->_naapurit[i];
			if (obj->_vierailtu == false) {
				obj->_vierailtu = true;
				std::cout << obj->_nimi;
				stakki.push(obj);
				ptr = obj;
				break;
			}
			if (i == ptr->_naapurit.size()-1 && obj->_vierailtu == true) {
				stakki.pop();
				ptr = stakki.top();
			}
		}
		
	}


}

int main()
{


	verkonTulostus();
}

