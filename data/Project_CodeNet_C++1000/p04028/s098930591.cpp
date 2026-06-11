#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <climits>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <type_traits>
#include <utility>
#include <vector>

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;

template<uint64 MOD>
class modint {
public:
	uint32 a;
	modint(uint32 x = 0) :a(x < MOD ? x : x%MOD) {}
	const modint operator+(const modint &o) const{
		if (a + o.a < MOD) return modint(a + o.a);
		return modint(a + o.a - MOD);
	}
	modint &operator+=(const modint &o) {
		a += o.a;
		if (a >= MOD) a -= MOD;
		return *this;
	}
	const modint operator-(const modint &o) const{
		if (a < o.a) return modint(a + MOD - o.a);
		return modint(a - o.a);
	}
	modint &operator-=(const modint &o) {
		if (a < o.a) a += MOD;
		a -= o.a;
		return *this;
	}
	const modint operator*(const modint &o) const{
		return modint((uint64)a*(uint64)o.a%MOD);
	}
	modint &operator*=(const modint &o) {
		a = (uint64)a*(uint64)o.a%MOD;
		return *this;
	}
	const modint operator/(const modint &o) const {
		return *this*~o;
	}

	const modint operator-() const{
		if (a) return modint(MOD - a);
		return modint(0);
	}
	modint operator++() {
		++a;
		if (a == MOD) a = 0;
		return *this;
	}
	modint operator++(int) {
		if (a == MOD - 1) {
			a = 0;
			return modint(MOD - 1);
		}
		++a;
		return modint(a - 1);
	}
	modint operator--() {
		if (a) {
			--a;
		}
		else {
			a = MOD - 1;
		}
		return *this;
	}
	modint operator--(int) {
		if (a) {
			--a;
			return modint(a + 1);
		}
		a = MOD - 1;
		return modint(0);
	}
	modint operator~() const {
		int64 x = a, y = MOD, u = 1, v = 0, t;
		while (y) {
			t = x / y;
			x -= t*y;
			std::swap(x, y);
			u -= t*v;
			std::swap(u, v);
		}
		return modint(u);
	}
	bool operator!() const{
		if (a) return false;
		return true;
	}
	bool operator==(const modint o) const{
		return a == o.a;
	}
	bool operator!=(const modint o) const{
		return a != o.a;
	}
	bool operator<(const modint o) const{
		return a < o.a;
	}
	bool operator<=(const modint o) const{
		return a <= o.a;
	}
	bool operator>(const modint o) const{
		return a > o.a;
	}
	bool operator>=(const modint o) const{
		return a >= o.a;
	}
};

using mint = modint<1000000007>;
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	uint32 n;
	std::string s;
	std::cin >> n >> s;
	mint dp[5003][5003] = {};
	dp[0][0] = mint(1);
	for (uint32 i = 1;i <= n;++i) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][1] + dp[i - 1][0];
		for (uint32 j = 1;j <= i;++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] + dp[i - 1][j + 1];
		}
	}
	std::cout << dp[n][s.length()].a << "\n";
	return 0;
}