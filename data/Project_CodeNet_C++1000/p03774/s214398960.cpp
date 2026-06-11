#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt N, M; std::cin >> N >> M;
	std::vector<intt> a(N);
	std::vector<intt> b(N);
	std::vector<intt> c(M);
	std::vector<intt> d(M);
	for (intt i = 0; i < N; ++i)
		std::cin >> a[i] >> b[i];
	for (intt i = 0; i < M; ++i)
		std::cin >> c[i] >> d[i];
	for (intt i = 0; i < N; ++i) {
		intt dmin = 10000000000000;
		intt p = 0;
		for (intt j = 0; j < M; ++j) {
			if (dmin > std::abs(a[i] - c[j]) + std::abs(b[i] - d[j]))
				p = j + 1;
			dmin = std::min(dmin, std::abs(a[i] - c[j]) + std::abs(b[i] - d[j]));
		}
		std::cout << p << std::endl;
	}

	return 0;
}