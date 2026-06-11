#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

std::vector<long long> solve(int H, int W, const std::vector<std::pair<int, int>> &points)
{
	std::unordered_map<long long, int> map;
	for (const auto &p : points)
	{
		int i1 = std::max(p.first - 2, 0);
		int i2 = std::min(p.first, H - 3);
		int j1 = std::max(p.second - 2, 0);
		int j2 = std::min(p.second, W - 3);
		for (int i = i1; i <= i2; ++i)
		{
			for (int j = j1; j <= j2; ++j)
			{
				long long key = (long long)i << 32 | j;
				if (map.count(key) == 0) { map[key] = 0; }
				++map[key];
			}
		}
	}
	std::vector<long long> counts(10);
	for (const auto &pair : map) { ++counts[pair.second]; }
	int sum = std::accumulate(counts.begin(), counts.end(), 0);
	counts[0] = (long long)(H - 2) * (long long)(W - 2) - sum;
	return counts;
}

int main()
{
	int H, W, N;
	std::cin >> H >> W >> N;
	std::vector<std::pair<int, int>> points(N);
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		points[i] = std::make_pair(a - 1, b - 1);
	}
	for (long long n : solve(H, W, points)) { std::cout << n << std::endl; }
}
