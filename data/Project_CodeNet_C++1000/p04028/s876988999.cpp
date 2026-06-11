#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

ll mpow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector<int> dp(n+1,0);
	dp[0] = 1;
	rep(rot, 0, n) {
		vector<int> nxt(n + 1);
		rep(i, 0, n + 1) {
			if (dp[i] > 0) {
				if (i > 0) nxt[i - 1] = (nxt[i - 1] + dp[i]) % mod;
				else nxt[0] = (nxt[0] + dp[0]) % mod;
				if (i < n)nxt[i + 1] = (nxt[i + 1] + dp[i])*2LL % mod;
			}
		}
		swap(dp, nxt);
	}
	printf("%d", (1LL*mpow(mpow(2,s.size()),mod-2)*dp[s.size()])%mod);
	return 0;
}
