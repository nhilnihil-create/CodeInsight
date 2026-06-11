#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
	int N; std::cin >> N;
	std::string S; std::cin >> S;
	int max = 0;
	int count = 0;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == 'I') ++count;
		else if (S[i] == 'D') --count;
		if (max < count) max = count;
	}
	std::cout << max << std::endl;

	return 0;
}