#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N; std::cin >> N;
	std::vector<int> T(N);
	for (auto& r : T) std::cin >> r;

	int M; std::cin >> M;
	std::vector<int> P(M);
	std::vector<int> X(M);
	for (int i{ 0 }; i < M; ++i) {
		int t; std::cin >> t;
		P[i] = t - 1;
		std::cin >> X[i];
	}

	for (int i = 0; i < M; ++i) {
		int save = T[P[i]];
		T[P[i]] = X[i];
		int total = 0;
		for (auto& r : T)
			total += r;
		std::cout << total << std::endl;;
		T[P[i]] = save;
	}

	return 0;
}