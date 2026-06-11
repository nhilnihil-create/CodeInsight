#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
ll mod_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll x = mod_pow(a, b / 2);
		return (x*x) % MOD;
	}
	return (a*mod_pow(a, b - 1)) % MOD;
}
ll dp[5001][5001];
int main() {
	int N;
	string s;
	cin >> N;
	cin >> s;
	dp[1][0] = 1;
	dp[1][1] = 2;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j > 0) (dp[i + 1][j - 1] += dp[i][j]) %= MOD;
			else (dp[i + 1][0] += dp[i][0]) %= MOD;
			(dp[i + 1][j + 1] += dp[i][j] * 2) %= MOD;
		}
	}
	ll inv = mod_pow(2, MOD - 2);
	cout << (dp[N][s.size()] * mod_pow(inv, s.size())) % MOD << endl;
}