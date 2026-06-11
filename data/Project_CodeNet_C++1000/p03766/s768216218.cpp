#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
constexpr ll MODN = 1000000007;
ll n, dp, dp_1, dp_2, dp_3;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dp_1 = 1, dp = 1 + n;
	for (int i = 2; i <= n; ++i) {
		dp_3 = dp_2, dp_2 = dp_1, dp_1 = dp;
		dp = n * n - n + 2 + dp_3;
		dp += min(-2, -i) + 2 * dp_1 - dp_2;
		dp %= MODN;
	}
	cout << (dp - dp_1 + MODN) % MODN << endl;
	return 0;
}