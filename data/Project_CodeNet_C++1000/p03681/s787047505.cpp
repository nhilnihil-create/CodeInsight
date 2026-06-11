#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1LL << 61);
const int inf = 1001001001;
const int mod = 1000000007;

ll fact(ll a) {
	ll res = 1;
	for (int i = 1; i <= a; ++i) (res *= i) %= mod;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (abs(n - m) > 1) {
		cout << 0 << endl;
		return 0;
	}
	if (n == m) {
		ll ans = 2ll * fact(n) % mod * fact(m) % mod;
		cout << ans << endl;
	}
	else {
		ll ans = fact(n) * fact(m) % mod;
		cout << ans << endl;
	}
	return 0;
}