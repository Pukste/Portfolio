#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <conio.h>

class Semaphore {
public:
	Semaphore(int laskuri = 1) : _laskuri(laskuri) {

	}


	void wait(int threadID) {
		std::unique_lock<std::mutex> lock(mtx);
		while (_laskuri <0) {
			cv.wait(lock);
		}
		std::cout << threadID << " menee\n";
		_laskuri--;


		
	}
	void post() {
		std::unique_lock<std::mutex> lock(mtx);
		_laskuri++;
		cv.notify_one();
	}



private:
	int _laskuri;
	std::mutex mtx;
	std::condition_variable cv;
};


int main()
{
	Semaphore se(-1);

	std::thread th1([&]() {se.wait(1); });
	std::thread th2([&]() {se.wait(2); });
	std::thread th3([&]() {se.wait(3); });
	std::thread th4([&]() {se.wait(4); });
	std::cout << "Odottaa\n";
	se.post();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	se.post();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	se.post();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	se.post();


	th1.join();
	th2.join();
	th3.join();
	th4.join();

	return 0;
}

