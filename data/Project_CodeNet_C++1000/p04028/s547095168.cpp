# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);

LL dp[5010][5010];

int main() {
	int n;
	string s;
	cin >> n >> s;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		if (i != 0) {
			dp[i][0] += dp[i - 1][0];
		}
		for (int j = 1; j <= i; j++) {
			dp[i][j] += (dp[i - 1][j - 1] * 2) % MOD;
			dp[i + 1][j - 1] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
		}
	}
	LL ans = dp[n][s.size()];
	for (int i = 0; i < s.size(); i++) {
		ans = (ans * 500000004) % MOD;
	}
	cout << ans << endl;
}