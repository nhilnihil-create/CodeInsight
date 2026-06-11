#include <bits/stdc++.h>
#include <unordered_set>

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

void solve_abc_d() {
	ll n, m;
	ll a, b;
	//ll x, y;
	ll k;
	ll l_ans = 0;

	cin >> n >> a >> b;
	V x(n);
	rep(i, n) cin >> x[i];

	ll diff;
	rep(i, n - 1) {
		diff = x[i + 1] - x[i];
		if (diff * a > b) {
			l_ans += b;
		}
		else {
			l_ans += diff * a;
		}
	}

	cout << l_ans << "\n";
	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_d();

	return 0;
}
