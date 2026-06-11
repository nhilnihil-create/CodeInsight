#include "iostream"
#include "vector"
#include "iomanip"
#include "algorithm"
#include "vector"
#include "cmath"

typedef struct {
	int a;
	int b;
	int c;
}Drag;

int main() {
	int n;
	double ma, mb;
	std::cin >> n;
	std::cin >> ma;
	std::cin >> mb;

	std::vector<Drag> drag(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> drag[i].a;
		std::cin >> drag[i].b;
		std::cin >> drag[i].c;
	}

	std::vector<std::vector<std::vector<int>>> v(n + 1, std::vector<std::vector<int>>(n * 10 + 1, std::vector<int>(n * 10 + 1, 10000)));
	v[0][0][0] = 0;

	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= n * 10; ++j)
			for (int k = 0; k <= n * 10; ++k) {
				int tmp_0 = v[i - 1][j][k];
				int tmp_1 = (j >= drag[i - 1].a && k >= drag[i - 1].b) ? v[i - 1][j - drag[i - 1].a][k - drag[i - 1].b] + drag[i - 1].c : 10000;
				v[i][j][k] = (tmp_0 < tmp_1) ? tmp_0 : tmp_1;
			}

	int min = 10000;
	int k_max = (ma > mb) ? ((double)n * 10 / ma) : ((double)n * 10 / mb);
	for (int i = 1; i <= k_max; ++i) {
		if (v[n][ma * i][mb * i] < min)
			min = v[n][ma * i][mb * i];
	}
	if (min == 10000)
		min = -1;

	std::cout << min;
}