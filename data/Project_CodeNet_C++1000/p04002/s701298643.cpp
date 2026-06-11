#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
#include <stack>
#include <cassert>
#include <memory>
#include <random>


struct Coordinate {
	int x, y;
	Coordinate operator+(const Coordinate& that) const {
		return Coordinate{ x + that.x, y + that.y };
	}
	bool operator==(const Coordinate& that) const {
		return x == that.x && y == that.y;
	}
};
constexpr std::array<Coordinate, 9> neighbors{ Coordinate{-1, -1}, Coordinate{-1, 0}, Coordinate{-1, 1},
Coordinate{0, -1}, Coordinate{0, 0}, Coordinate{0, 1},
Coordinate{1, -1}, Coordinate{1, 0}, Coordinate{1, 1}
};
template<typename T>
inline void hash_combine(unsigned int& seed, const T& value) {
	seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template<>
struct std::hash<Coordinate> {
	unsigned int operator()(const Coordinate& value) const {
		unsigned int seed = 0;
		hash_combine(seed, value.x);
		hash_combine(seed, value.y);
		return seed;
	}
};
int main() {
	int height, width, n; std::cin >> height >> width >> n;
	std::unordered_map<Coordinate, int> count;
	for (auto i = 0; i < n; ++i) {
		int a, b; std::cin >> a >> b;
		for (const auto& neighbor: neighbors) {
			const auto next = neighbor + Coordinate{ a, b };
			if (2 <= next.x && next.x <= height - 1 && 2 <= next.y && next.y <= width - 1)
				count[next]++;
		}
	}
	std::vector<long long int> result(10, 0);
	result[0] = (long long int)(height - 2) * (width - 2);
	for (const auto& p : count) {
		result[p.second]++;
		result[0]--;
	}
	for (const auto i : result) {
		std::cout << i << '\n';
	}
}