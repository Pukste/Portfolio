#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
// Jotain h‰m‰r‰‰ logiin kirjoittamisessa...
using namespace std;

string _logtext;
int x = -1;
ofstream myfile("Log.txt");

string GetTime() {
	time_t now = time(0);

	// convert now to string form
	char str[26];
	ctime_s(str, sizeof str, &now);

	return str;
}

void WriteToLog(string a) {
	

	try {
		if (myfile.is_open()) {

			myfile << a << endl;
			
		}
		else {
			throw x;
		}
	}
	catch (int x) {
		cout << "File could not be opened\n";
	}
}

template <class T>
class Log_Ptr {
public:
	
	
	Log_Ptr(T* i) {
		
		_i = i;
		_logtext = GetTime() + " omistajuus siirretty";
		WriteToLog(_logtext);
		
	}
	Log_Ptr() {
		
		_i = nullptr;
		_logtext = GetTime() + " luotu ilman omistajuutta";
		WriteToLog(_logtext);
		
	}
	~Log_Ptr() {
		delete _i;
		
		_logtext = GetTime() + " olio tuhottu";
		WriteToLog(_logtext);
		myfile.close();
	}

	T* operator-> () {

		if (_i == nullptr) {
			throw exception("Ei osoita\n");
		}
		else {
			
			_logtext = GetTime() + " operator->";
			WriteToLog(_logtext);
			return _i;
		}
	}



	T& operator* () {
		if (_i == nullptr) {
			throw exception("Ei osoita\n");
		}
		else {
			
			_logtext = GetTime() + " operator*";
			WriteToLog(_logtext);
			return *_i;
		}
	}




	void reset() {
		if (_i != nullptr) {
			delete _i;
			_i = nullptr;
			
			_logtext = GetTime() + " omistajuus poistettu";
			WriteToLog(_logtext);
		}

	}
private:
	T* _i;

};

class Olio {
public:
	void tervehdi() { cout << "moo\n"; }
};




int main()
{
	
	
	Olio* x = new Olio();
	Log_Ptr<Olio> xx(x);

	xx->tervehdi();
	xx.reset();
	try {
		xx->tervehdi();
	}
	catch (exception & e) {
		cout << e.what();
	}

	
}
