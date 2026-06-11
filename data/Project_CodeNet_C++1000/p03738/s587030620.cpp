#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	std::string A, B; std::cin >> A >> B;
	if (A.size() > B.size()) {
		std::cout << "GREATER" << std::endl;
		return 0;
	}
	else if (A.size() < B.size()) {
		std::cout << "LESS" << std::endl;
		return 0;
	}
	else {
			for (int i = 0; i < A.size(); ++i) {
				if (A[i] > B[i]) {
					std::cout << "GREATER" << std::endl;
					return 0;
				}
				else if (A[i] < B[i]) {
					std::cout << "LESS" << std::endl;
					return 0;
				}
			}
	}
	std::cout << "EQUAL" << std::endl;
	return 0;
}