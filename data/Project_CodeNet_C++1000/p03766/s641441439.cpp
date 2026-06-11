#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e6 + 7, mod = 1e9 + 7, offset = 1e6 + 2;

int dp[N], n;


int get(int idx) {
	idx += offset;
	return idx < 0 ? 0 : dp[idx];
}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = -offset; i <= 0; i++) {
		dp[i + offset] = (1 + dp[i + offset - 1]) % mod;
	}
	dp[1 + offset] = (n + dp[offset]) % mod;
	int k = (n - 1) * (n - 1) % mod;
	for(int i = 2; i <= n; i++) {
		dp[i + offset] = (get(i - 1) - get(i - 2) + mod) % mod;
		dp[i + offset] += k + (get(i - 3) - get(i - n - 2) + mod) % mod;
		dp[i + offset] %= mod;
		dp[i + offset] = (dp[i + offset] + dp[i + offset - 1]) % mod;
	}

	cout << (dp[n + offset] - dp[n + offset - 1] + mod) % mod << endl;

}