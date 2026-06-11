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

ll keta(ll a) {
	if (a == 0) return 0;
	return 1 + keta(a / 10);
}

void solve() {
	ll n;
	cin >> n;
	ll ans = 10000000001;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		ll b = n / i;
		ans = min(ans, max(keta(i), keta(b)));
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}