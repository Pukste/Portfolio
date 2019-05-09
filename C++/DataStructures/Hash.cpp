// Hash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#define HASHSIZE 20
using namespace std;

string cars[HASHSIZE];

class Hash {
	unsigned hash(const char* s) {
		unsigned _hashval;
		for (_hashval=0; *s != '\0'; s++)
			_hashval = *s + 31 * _hashval;
		return _hashval % HASHSIZE;
	}
public:
	void store(const string& key, const string& value) {
		const char* cstr = key.c_str();
		cars[hash(cstr)] = value;

	}
	string retrieve(const string& key) {
		const char* cstr = key.c_str();
		return cars[hash(cstr)];
	}
};
int main()
{
	Hash autot;
	autot.store("miikka", "ferrari");
	autot.store("jukka", "fiat");
	cout << autot.retrieve("miikka");

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
