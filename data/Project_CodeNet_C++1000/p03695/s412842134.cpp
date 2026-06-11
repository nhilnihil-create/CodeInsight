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
	int N; std::cin >> N;
	int min = 0;
	int max = 0;
	bool a = false;
	bool b = false;
	bool c = false;
	bool d = false;
	bool e = false;
	bool f = false;
	bool g = false;
	bool h = false;
	for (int i = 0; i < N; ++i) {
		int num; std::cin >> num;
		if (num < 400)
			a = true;
		if (num < 800 && 400 <= num)
			b = true;
		if (num < 1200 && 800 <= num)
			c = true;
		if (num < 1600 && 1200 <= num)
			d = true;
		if (num < 2000 && 1600 <= num)
			e = true;
		if (num < 2400 && 2000 <= num)
			f = true;
		if (num < 2800 && 2400 <= num)
			g = true;
		if (num <3200 && 2800 <= num)
			h = true;
		if (num >= 3200)
			++max;
	}
	if (a == true)
		++min;
	if (b == true)
		++min;
	if (c == true)
		++min;
	if (d == true)
		++min;
	if (e == true)
		++min;
	if (f == true)
		++min;
	if (g == true)
		++min;
	if (h == true)
		++min;

	std::cout << std::max(min, 1)  << " " << max + min << std::endl;

	return 0;
}