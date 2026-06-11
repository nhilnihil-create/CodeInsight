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
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_b() {
	ll n, m;
	ll x, y;
	//ll a, b, c;
	//ll k;
	string s;
	ll l_ans = 0;
	float f_ans = 0;
	string s_ans;

	cin >> n >> m;

	V a(n), b(n), c(m), d(m);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	rep(i, m) {
		cin >> c[i] >> d[i];
	}

	V dist(n, INF);
	V ans(n, -1);
	rep(i, n) {
		rep(j, m) {
			if (dist[i] > abs(a[i] - c[j]) + abs(b[i] - d[j])) {
				dist[i] = abs(a[i] - c[j]) + abs(b[i] - d[j]);
				ans[i] = j + 1;
			}
		}
		cout << ans[i] << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_b();

	return 0;
}
