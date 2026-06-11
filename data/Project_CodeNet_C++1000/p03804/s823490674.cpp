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

void solve_abc_b() {
	ll n, m;
	ll x, y;
	//ll a, b, c;
	ll k;
	string s;
	//ll ans = 0;
	//float ans = 0;
	string ans;

	cin >> n >> m;

	vector<string> a(n), b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, m) {
		cin >> b[i];
	}

	string tmp;
	bool same;
	ll cnt = 0;
	rep(h, n) {
		rep(w, n) {
			same = true;
			rep(i, m) {
				if (h + i >= n) {
					same = false;
					break;
				}

				tmp = a[h + i].substr(w, m);
				if (tmp != b[i]) {
					same = false;
					break;
				}
			}
			if (same) {
				cout << "Yes" << "\n";
				return;
			}
		}
	}
	
	cout << "No" << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_b();

	return 0;
}