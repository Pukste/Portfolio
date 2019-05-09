#include <stdlib.h>
#include <iostream>
using namespace std;
class BigData {
public:

	BigData& operator = (const BigData& rhs) {
		free(_ptr);
		_ptr = malloc(rhs._size);
		_size = rhs._size;
		memcpy(_ptr, rhs._ptr, _size);
		return *this;
	}

	BigData& operator = (BigData&& rhs) {
		cout << "Move operaattori\n";

		free(_ptr);
		_ptr = rhs._ptr;
		_size = rhs._size;
		rhs._ptr = nullptr;

		return *this;
	}
	BigData(unsigned sz) {
		_ptr = malloc(sz);
		_size = sz;
	}
	BigData(BigData& b) {
		_ptr = malloc(b._size);
		_size = b._size;

	}
	BigData(BigData&& b) {
		free(_ptr);
		_ptr = b._ptr;
		_size = b._size;
		b._ptr = nullptr;
	};
	~BigData() {
		free(_ptr);
	}
private:
	void* _ptr = 0;  
	unsigned _size = 0;
};

int main() {
	cout << "alku\n";


	BigData a(move(BigData(1024)));
	BigData b(1024);
	b = BigData(1024);
	cout << "loppu\n";

	return 0;
};