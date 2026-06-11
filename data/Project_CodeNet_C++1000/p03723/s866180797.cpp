#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int A, B, C; std::cin >> A >> B >> C;
	if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
		std::cout << 0;
		return 0;
	}
	if (A == B && B == C && C == A) {
		std::cout << -1 << std::endl;
		return 0;
	}
	int count = 0;
	while (true) {
		int a = B / 2 + C / 2;
		int b = A / 2 + C / 2;
		int c = A / 2 + B / 2;
		++count;
		A = a;
		B = b;
		C = c;
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1)
			break;
	}
	std::cout << count << std::endl;

	return 0;
}