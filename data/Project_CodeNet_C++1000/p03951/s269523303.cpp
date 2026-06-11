#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

intt N;
std::string s1, s2;
int func() {
	for (int i = 0; i < N; ++i) {
		if (s1.substr(i) == s2.substr(0, N - i))
			return i + N;
	}
	return N * 2;
}

int main(){
	 std::cin >> N;
	 std::cin >> s1 >> s2;
	std::cout << func() << std::endl;

	return 0;
}