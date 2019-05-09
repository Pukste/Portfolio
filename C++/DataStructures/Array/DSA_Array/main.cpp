#include <iostream>
#include "array.h"
using namespace std;

int main()
{
	Array<int> intarr;
	cout << intarr.size() << endl;

	intarr[0] = 10;
	intarr[1] = 20;
	intarr[2] = 30;
	intarr[3] = 40;
	intarr[4] = 50;
	cout << endl;

	intarr.squeeze_in(2, 100);
	for (unsigned i = 0; i < intarr.size(); ++i)
		cout << intarr[i] << endl;
	cout << endl;

	intarr.resize(3);
	for (unsigned i = 0; i < intarr.size(); ++i)
		cout << intarr[i] << endl;
	cout << endl;

	intarr.resize(10);
	for (unsigned i = 0; i < intarr.size(); ++i)
		cout << intarr[i] << endl;

	return 0;
}
