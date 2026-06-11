#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll func(ll x) {
	if (x == 1) return 1;
	return ((x % MOD) * (func(x - 1) % MOD)) % MOD;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	if (n == m) {
		ll x = func(n);
		cout << (((x * x) % MOD) * 2) % MOD << endl;
	} else if (abs(n - m) == 1) {
		ll mn = min(n, m);
		ll mx = max(n, m);
		ll x = func(mn);
		cout << (((x * x) % MOD) * mx) % MOD << endl;
	} else {
		cout << 0 << endl;
	}
}

int main() {
	solve();
	return 0;
}