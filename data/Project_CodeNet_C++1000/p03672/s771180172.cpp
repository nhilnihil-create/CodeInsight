#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

intt func(intt n) {
	intt r = 0;
	while (n > 0) {
		r += n;
		--n;
	}
	return r;
}

int main() {
	std::string s; std::cin >> s;
	for (int i = s.size() - 2; i >= 0; i -= 2) {
		if (s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
			std::cout << i << std::endl;
			return 0;
		}
	}
}