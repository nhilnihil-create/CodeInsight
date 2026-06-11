#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define rep(i,a,b) for(int32 i = (a); i < (b); ++i)
#define bitget(a,b) (((a) >> (b)) & 1)
#define ALL(x) (x).begin(),(x).end()
#define C(x) std::cout << #x << " : " << x << std::endl
#define scanf scanf_s

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;



int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int32 n, m;
	std::cin >> n >> m;
	std::vector<int64> x(n), y(m), a(n-1, 0), b(m-1, 0);
	rep(i, 0, n)
		std::cin >> x[i];
	rep(i, 0, m)
		std::cin >> y[i];
	std::sort(ALL(x));
	std::sort(ALL(y));
	rep(i, 0, n - 1) {
		a[i] = i + 1 - n + 1 + 1 + i;
	}
	rep(i, 0, m - 1) {
		b[i] = i + 1 - m + 1 + 1 + i;
	}
	for (uint32 i = n - 3;~i;--i) {
		a[i] += a[i + 1];
	}
	for (uint32 i = m - 3;~i;--i) {
		b[i] += b[i + 1];
	}
	uint64 c = 0, d = 0;
	rep(i, 0, n - 1) {
		c = (c + ((x[i + 1] - x[i])*a[i])%MOD) % MOD;
	}
	rep(i, 0, m - 1) {
		d = (d + ((y[i + 1] - y[i])*b[i])%MOD) % MOD;
	}
	std::cout << (c*d) % MOD << "\n";
	return 0;
}