#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
	std::string s; std::cin >> s;
	std::sort(s.begin(), s.end());
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			std::cout << "no" << std::endl;
			return 0;
		}
	}
	std::cout << "yes" << std::endl;

	return 0;
}