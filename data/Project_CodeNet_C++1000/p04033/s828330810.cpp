#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

int main() {
	long long a, b; std::cin >> a >> b;
	if (a <= 0 && b >= 0)
		std::cout << "Zero" << std::endl;
	else if (a > 0 && b > 0)
		std::cout << "Positive" << std::endl;
	else {
		if (std::abs(a - b) % 2 == 0)
			std::cout << "Negative" << std::endl;
		else
			std::cout << "Positive" << std::endl;
	}

	return 0;
}