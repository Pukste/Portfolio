#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;


class Olio {
public:
	Olio(string nimi) {
		_nimi = nimi; 
	}
	~Olio() {
		cout << _nimi <<" tuhottu\n";
	}
	string _nimi;
};

int main()
{
	
	vector<unique_ptr<Olio>> v;
	v.push_back(make_unique<Olio>("eka"));
	v.push_back(make_unique<Olio>("toka"));
	v.push_back(make_unique<Olio>("kolmas"));
	v.push_back(make_unique<Olio>("neljäs"));
	v.push_back(make_unique<Olio>("viides"));
	

	v.erase(v.begin() + 2);
	v.erase(v.begin() + 3);
	v.erase(v.begin() + 1);

}

