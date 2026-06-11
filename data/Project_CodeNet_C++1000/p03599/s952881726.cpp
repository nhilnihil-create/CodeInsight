#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
//using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_c() {
	ll a, b, c, d, e, f;
	ll sum, sugar;

	cin >> a >> b >> c >> d >> e >> f;

	ll w1 = 100 * a;
	ll w2 = 100 * b;
	ll s1 = c;
	ll s2 = d;
	ll water;
	float nodo = -1;
	ll ans1, ans2;

	for (ll i = 0; i <= 3000; i += w1) {
		for (ll j = 0; j + i <= 3000; j += w2) {
			water = i + j;
			for (ll k = 0; k <= (i + j)/100 * e; k += s1) {
				if (water + k > f) break;

				for (ll l = 0; l + k <= (i + j) / 100 * e; l += s2) {
					sugar = k + l;

					sum = water + sugar;
					if (sum <= f && sugar <= (i + j) / 100 * e) {
						if ((float)100 * sugar / sum > nodo) {
							nodo = (float)100 * sugar / sum;
							ans1 = sum;
							ans2 = sugar;
						}
					}
				}
			}
		}
	}
	cout << ans1 << " " << ans2 << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_c();

	return 0;
}