#include <thread>
#include <future>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <execution>

class Game_Task {
public:
	virtual void perform() = 0;

	virtual ~Game_Task() {
	}
};

class tuttu : public Game_Task {
public:
	void perform() {
		
			for (unsigned i = 0; i < 100000000; i++) {
				a++;
			}
			std::cout << a;
	}
private:
	unsigned a = 0;
};

class juttu : public Game_Task {
public:
	void perform(){
		for (unsigned i = 0; i < 100000000; i++) {
			b = b + 2 * i;
		}
		std::cout << b;
	}
private:
	unsigned b = 0;
};

class timo : public Game_Task {
public:
	void perform() {
		for (unsigned i = 0; i < 100000000; i++) {
			c = c + 3 * i;
		}
		std::cout << c;
	}
private:
	unsigned c = 0;
};

class joel : public Game_Task {
public:
	void perform() {
		for (unsigned i = 0; i < 100000000; i++) {
			d = d + 4 * i;
		}
		std::cout << d;
	}
private:
	unsigned d = 0;
};

void parallel_loop(std::vector<Game_Task*> vec, int threads) {

	int start = 0;
	std::vector<std::thread> thr;
	int loopsperthread = vec.size() / threads;
	int overflow = (vec.size() % threads);
	int end = loopsperthread;
	auto code = [&](int start, int end)-> void {
		for (int j = start; j < end; j++) {
			vec[j]->perform();
		}
	};
	for (int i = 0; i < threads; i++) {
		if (i == threads)
			end += overflow;
		thr.emplace_back(std::thread(code, start, end));
		start = end;
		end = start + loopsperthread;
	}
	for (std::thread& t : thr)
		t.join();
}

template<class T>
void loop_with_async(std::vector<T*> vec) {
	std::vector<std::future<void>> futures;
	
	for (auto const& task:vec) {
		auto code = [&]() ->void { task->perform(); };
		futures.emplace_back(std::async(std::launch::async, code));
	}
	for (int j = 0; j < futures.size(); j++) {
		futures[j].wait();
	}
}


int main()
{
	clock_t start;
	double duration;
	Game_Task* a = new tuttu;
	Game_Task* b = new juttu;
	Game_Task* c = new timo;
	Game_Task* d = new joel;


	std::vector<Game_Task*> tasks;
	for (int i = 0; i < 20; i++)
	{
		tasks.push_back(a);
		tasks.push_back(b);
		tasks.push_back(c);
		tasks.push_back(d);
	}
	
	int number_of_tasks = tasks.size();
	//perus debug: 19,094 sekuntia
	//release: 2,676
	start = clock();
	for (int i = 0; i < number_of_tasks; i++) { 
		tasks[i]->perform(); 
	} 
	// Continue only after all tasks are complete!
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\n\nSequential: " << duration << "\n\n";
	// a) debug: 19,825 sekuntia 
	//release x4: 0,682 sekuntia
	//release x8: 0.392 sekuntia
	//release x32: 0.216 sekuntia

	
	start = clock();
	parallel_loop(tasks, 4);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\n\nParallel 4: " << duration << "\n\n";

	// b) debug: 16,15 sekuntia
	//release: 0,288 sekuntia(16 thread)
	start = clock();
	parallel_loop(tasks, std::thread::hardware_concurrency());
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\n\nParallel x_corecount: " << duration << "\n\n";

	// c) debug: 15,799 sekuntia
	//release: 0,252 sekuntia
	start = clock();
	loop_with_async(tasks);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\n\nAsync: " << duration << "\n\n";


	// execution::par) debug: 15,799 sekuntia
	//release: 0,265 sekuntia
	start = clock();
	std::for_each(std::execution::par, tasks.begin(), tasks.end(), [](Game_Task * a) { a->perform(); });
	std::cout << "\n\c++17, std::execution::par : " << duration << "\n\n";

	// execution::par_unseq) debug: 15,799 sekuntia 
	//release: 0,265 sekuntia
	start = clock();
	std::for_each(std::execution::par_unseq, tasks.begin(), tasks.end(), [](Game_Task * a) { a->perform(); });
	std::cout << "\n\c++17, std::execution::par_unseq : " << duration << "\n\n";

	delete a;
	delete b;
	delete c;
	delete d;
	std::this_thread::sleep_for(std::chrono::seconds(20));
	return 0;
}

