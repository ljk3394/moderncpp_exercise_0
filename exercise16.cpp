#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>

int main() {

	// Use std::atomic
	std::atomic<int> x1 = 0;

	auto t1 = std::chrono::steady_clock::now();
	// 시간 측정
	std::thread th1([&]() {
		for (int i = 0;i < 100'000'000;i++) {
			x1.fetch_add(1);
		}

		});
	std::thread th2([&]() {
		for (int i = 0;i < 100'000'000;i++) {
			x1.fetch_add(1);
		}

		});
	if (th1.joinable())
		th1.join();
	if (th2.joinable())
		th2.join();
	auto t2 = std::chrono::steady_clock::now();
		std::cout << x1 << '\n';

		auto dt=std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		std::wcout << "took" << dt.count() << "ms\n";

	// do something

	//std::cout << x1 << '\n';
	//std::cout << "걸린 시간: " << /* ... */ << '\n';

	//// Use std::mutex
	//std::mutex x2;

	//// 시간 측정
	//std::thread th3( /* ... */);
	//std::thread th4( /* ... */);

	//// do something

	//std::cout << x2 << '\n';
	//std::cout << "걸린 시간: " << /* ... */ << '\n';

	return 0;
}