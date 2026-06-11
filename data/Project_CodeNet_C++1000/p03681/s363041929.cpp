#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll mod = 1000000007;

int main() {
	ll n, m;
	cin >> n >> m;
	if (abs(n - m) >= 2) {
		cout << 0 << endl;
		return 0;
	}
	ll M = min(m, n);
	ll N = max(m, n);
	ll ans = 1;
	if (M == N) {
		ans *= 2;
	}
	rep(i, N) {
		ans *= i + 1;
		ans %= mod;
	}
	rep(i, M) {
		ans *= i + 1;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

