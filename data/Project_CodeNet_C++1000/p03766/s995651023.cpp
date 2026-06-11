// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1e6+9;
const ll mod = 1e9+7;

ll dp[maxn];

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	dp[0] = dp[1] = 1;
	ll sum = dp[0] + dp[1];
	for (int i = 2; i < maxn; i++) {
		dp[i] = (sum - dp[i - 2] + mod) % mod;
		sum = (sum + dp[i]) % mod;
	}
	ll n, res = 0;
	cin >> n;
	for (ll i = 1; i < n; i++) {
		res = (res + dp[i - 1] * min(i + 1, n - 1) % mod) % mod;
		res = (res + dp[i - 1] * (n - 1) % mod * (n - 1) % mod) % mod;
	}
	res = (res + dp[n - 1] * n % mod) % mod;
	cout << res << "\n";
}

