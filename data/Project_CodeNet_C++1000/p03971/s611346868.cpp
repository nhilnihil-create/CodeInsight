#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N, A, B; std::cin >> N >> A >> B;
	std::string s; std::cin >> s;
	int count = 0; int count_b = 0;
	for (int i{ 0 }; i < s.size(); ++i) {
		if (s[i] == 'c') {
			std::cout << "No" << std::endl;
		} else if (s[i] == 'a') {
			if (count < A + B ) {
				std::cout << "Yes" << std::endl;
				++count;
			}
			else {
				std::cout << "No" << std::endl;
			}
		} else {
			if (count < A + B && count_b < B) {
				std::cout << "Yes" << std::endl;
				++count;
				++count_b;
			}
			else {
				std::cout << "No" << std::endl;
			}
		}
	}

	return 0;
}