#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
ll dp[5003][5003];
int N, L;

constexpr int MAX_N = 1003;
ll fact[MAX_N], inv[MAX_N];

ll powm(ll x, ll p) {
	if (p == 0) return 1;
	ll res = powm(x, p / 2);
	res *= res;
	res %= mod;
	if (p % 2LL == 1) {
		res *= x;
		res %= mod;
	}
	return res;
}

int main() {
	string s; cin >> N >> s;
	L = s.length();
	dp[0][L] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 5002; ++j) {
			dp[i][j] += j == 0 ? dp[i - 1][j] : dp[i - 1][j - 1];
			dp[i][j] %= mod;
			dp[i][j] += 2 * dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	ll t = 1;
	for (int i = 0; i < L; ++i) {
		t *= 2;
		t %= mod;
	}
	ll ans = dp[N][0]*powm(t, mod - 2) % mod;
	cout << ans << endl;
	return 0;
}