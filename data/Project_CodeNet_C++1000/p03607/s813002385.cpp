#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt N; std::cin >> N;
	std::map<intt, intt> MAP;
	for (intt i = 0; i < N; ++i) {
		intt t; std::cin >> t;
		++MAP[t];
	}
	intt count = 0;
	for (auto& r : MAP) {
		if (r.second % 2 == 1)
			++count;
	}
	std::cout << count << std::endl;

}