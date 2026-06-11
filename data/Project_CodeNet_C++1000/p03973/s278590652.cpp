#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define rep(i,a,b) for(uint32 i = (a); i < (b); ++i)
#define bitget(a,b) (((a) >> (b)) & 1)
#define ALL(x) (x).begin(),(x).end()
#define C(x) std::cout << #x << " : " << x << std::endl
#define scanf scanf_s

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

uint32 getd(uint64 a) {
	uint32 ret = 0;
	while (a) {
		++ret;
		a /= 10;
	}
	return ret;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	uint32 n;
	uint64 ans = 0;
	std::cin >> n;
	std::vector<uint32> a(n);
	rep(i, 0, n)
		std::cin >> a[i];
	uint32 t = 1;
	ans += a[0] - 1;
	a[0] = 1;
	rep(i, 0, n) {
		if (t > a[i]) continue;
		if (t == a[i]) {
			++t;
			continue;
		}
		ans += (a[i] - 1) / t;
	}
	std::cout << ans << "\n";
	return 0;
}