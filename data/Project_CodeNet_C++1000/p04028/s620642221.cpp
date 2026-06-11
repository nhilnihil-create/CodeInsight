#include <iostream>
#include <string>
#include <cstdint>

int64_t dp[5002][5001];
constexpr int64_t Mod = 1000000007;

int main() {
	int n;
	std::string str;
	std::cin >> n >> str;

	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		if (i != 0)
			dp[i][0] += dp[i - 1][0];
		for (int j = 1; j <= i; ++j) {
			dp[i][j] += (dp[i - 1][j - 1] * 2) % Mod;

			dp[i + 1][j - 1] = (dp[i][j] + dp[i + 1][j - 1]) % Mod;
		}
	}

	auto ans = dp[n][str.size()];
	for (int i = 0; i < str.size(); ++i)
		ans = (ans * 500000004) % Mod;

	std::cout << ans << std::endl;
}