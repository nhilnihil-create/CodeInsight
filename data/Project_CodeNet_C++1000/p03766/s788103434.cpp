#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int md = 1e9 + 7;

int n, dp[N];
int sum;
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;

	dp[0] = 1;
	dp[1] = n;
	sum = 0;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i-1]; // 1,...
		dp[i] = (dp[i] + 1LL * (n-1) * (n-1)) % md; // c,d,... (c,d > 1)
		dp[i] = (dp[i] + sum) % md; // c,1,... (c + 1 <= i)
		dp[i] = (dp[i] + (n - i + 1)) % md; // c,1,1,1... (c + 1 > i)
		sum = (sum + dp[i-2]) % md;
		//cerr << i << ' ' << dp[i] << endl;
	}

	cout << dp[n] << endl;
}