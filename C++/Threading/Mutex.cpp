#include <iostream>
#include <thread>
#include <mutex>

int x = 0;
std::mutex munMutex;


class Mutex_Guard {
public:
	
	Mutex_Guard(std::mutex &a) {
		_i =&a;
		_i->lock();
	}
	
	Mutex_Guard(std::mutex* i) {
		_i = i;
		_i->lock();
	}
	~Mutex_Guard() { _i->unlock(); }

private:
	std::mutex* _i;
};

void safe_increment() {
	Mutex_Guard(*munMutex);
	++x;

}


int main()
{
	std::thread th1(safe_increment);
	std::thread th2(safe_increment);
	std::thread th3(safe_increment);
	std::thread th4(safe_increment);

	th1.join();
	th2.join();
	th3.join();
	th4.join();

    std::cout << x; 
}

