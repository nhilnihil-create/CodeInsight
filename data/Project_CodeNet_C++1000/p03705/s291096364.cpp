#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main(){
	intt N, A, B; std::cin >> N >> A >> B;
	if (A > B)
		std::cout << 0 << std::endl;
	else {
		if (N == 1) {
			if (A == B)
				std::cout << 1 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
		else
			std::cout << (B - A) * (N - 2) + 1 << std::endl;
	}

	return 0;
}