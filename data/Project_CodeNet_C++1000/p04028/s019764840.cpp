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



int main(void) {
	static constexpr uint64 MOD = 1000000007;
	uint32 n;
	std::string s;
	std::cin >> n >> s;
	uint64 dp[5003][5003] = {};
	dp[0][0] = 1;
	for (uint32 i = 1;i <= n;++i) {
		for(uint32 j=0;j<=i;++j) {
			if (j == 0) {
				dp[i][j] = (dp[i - 1][j + 1] * 2 + dp[i - 1][j]) % MOD;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] * 2) % MOD;
			}
		}
	}
	std::cout << dp[n][s.length()] << "\n";
	return 0;
}