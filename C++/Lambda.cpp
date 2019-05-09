#include <iostream>
#include <vector>;
#include <algorithm>
using namespace std;

void kek(int i) {
	i -= 100;
	if (i < 0)
		i = 0;
}

struct Healthreducer {
	int operator() (int i) {
		i -= 100;
		if (i < 0)
			i = 0;
		return 0;

	}
};

auto func1 = [](int i) {i -= 100; if (i < 0) i = 0; };



int main() {
	vector<int> v = { 430, 200, 50, 150 };
	for_each(v.begin(), v.end(), Healthreducer());
	/*for_each(v.begin(), v.end(), kek);
	for_each(v.begin(), v.end(), func1);
	for_each(v.begin(), v.end(), [](int i) {i -= 100; if (i < 0) i = 0; });
		*/

	for each (auto a in v)
	{
		std::cout << a << "\n";
	}
};