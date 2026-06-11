#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	const long long INF = 100000000;
	int n, m, r;
	std::cin >> n >> m >> r;

	std::vector<int>town(r);
	for (int i = 0; i < r; ++i) {
		std::cin >> town.at(i);
		town.at(i)--;
	}

	std::vector<std::vector<long long>>road(n, std::vector<long long>(n, INF));
	for (int i = 0; i < n; ++i)
		road.at(i).at(i) = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		long long c;
		std::cin >> a >> b >> c;
		road.at(--a).at(--b) = c;
		road.at(b).at(a) = c;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (road.at(j).at(i) != INF && road.at(i).at(k) != INF) {
					road.at(j).at(k) = std::min(road.at(j).at(k), road.at(j).at(i) + road.at(i).at(k));
					road.at(k).at(j) = road.at(j).at(k);
				}

	std::sort(town.begin(), town.end());
	int ans = INF;
	do {
		int dis = 0;
		for (int i = 0; i < r - 1; ++i)
			dis += road.at(town.at(i)).at(town.at(i + 1));
		if (ans > dis)
			ans = dis;
	} while (next_permutation(town.begin(), town.end()));

	std::cout << ans;
}