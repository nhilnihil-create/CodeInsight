#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	std::string s; std::cin >> s;
	if (s.size() % 2 == 1) {
		std::cout << "No" << std::endl;
		return 0;
	}
	std::sort(s.begin(), s.end());
	for(int i = 0; i < s.size(); i += 2)
		if (s[i] != s[i + 1]) {
			std::cout << "No" << std::endl;
			return 0;
		}
	std::cout << "Yes" << std::endl;

	return 0;
}