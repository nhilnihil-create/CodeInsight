#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 1634569;

const int N = 1e6 + 20;
ll dp[N], n, sum;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	dp[0] = 1;
	dp[1] = n;
	sum = n + 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = ((n - i + 1) * n + (i - 2) * (n - 1) + sum - dp[i - 2] + MOD) % MOD;
		sum = (sum + dp[i]) % MOD;
	}
	cout << dp[n] << endl;
}

