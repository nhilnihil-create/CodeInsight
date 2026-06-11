#include <bits/stdc++.h>
#include <unordered_map>

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

void solve_abc_c() {
	ll n;
	ll ans = 0;

	cin >> n;

	V a(n);
	rep(i, n) {
		cin >> a[i];
	}

	sort(RALL(a));

	ll v = 0;
	V r;
	rep(i, n) {
		if (a[i] != v) {
			v = a[i];
		}
		else {
			r.push_back(v);
			if (r.size() == 2) {
				break;
			}
			v = 0;
		}
	}

	if (r.size() != 2) {
		ans = 0;
	}
	else {
		ans = r[0] * r[1];
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_c();

	return 0;
}
