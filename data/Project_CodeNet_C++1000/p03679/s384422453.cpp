#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_a() {
	ll n, m;
	ll x, y;
	ll a, b;
	ll k;
	//string s, t;
	// ans = 0;
	string ans = "NG";

	cin >> x >> a >> b;

	ll t = -a + b;

	if (t <= 0) {
		ans = "delicious";
	}
	else if (t <= x) {
		ans = "safe";
	}
	else {
		ans = "dangerous";
	}

	cout << ans << "\n";

	return;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_a();

	return 0;
}