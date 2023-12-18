#include <iostream>
#include <thread>

int x=0;

int main() {

	std::thread th = std::thread([&]() {
		for (int i = 0;i < 100000000;++i) {
			x += 1;
		}

		});

	std::thread th2 = std::thread([&]() {
		for (int j = 0;j < 100000000;++j) {
			x += 1;
		}

		});
	if(th.joinable())
		th.join();

	if (th2.joinable())
		th2.join();


	std::cout << x << '\n';

	return 0;
}