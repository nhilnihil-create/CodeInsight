#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#define intt long long

int main() {
	std::string S; std::cin >> S;
	intt N = S.size();
	intt ans = 0;
	for (int bit = 0; bit < (1 << N - 1); ++bit) {
		intt total = 0;
		for (int i = 0; i < N - 1; ++i) {
			total *= 10;
			total += S[i] - '0';
			if (bit & (1 << i)) {
				ans += total;
				total = 0;
			}
		}
		total *= 10;
		total += S.back() - '0';
		ans += total;
	}
	std::cout << ans << std::endl;
}