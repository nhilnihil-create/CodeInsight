#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main(){
	int w, h; cin >> w >> h;
	vector<ll> p(w), q(h);
	rep(i, 0, w) cin >> p[i];
	rep(i, 0, h) cin >> q[i];
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	p.push_back(1e9);
	q.push_back(1e9);
	ll ws = 0, wg = w+1, hs = 0, hg = h+1;
	ll ans = 0;
	while ((ws < w) || (hs < h)) {
		if (p[ws] < q[hs]) {
			ans += hg * p[ws];
			wg--; ws++;
		}
		else {
			ans += wg* q[hs];
			hg--; hs++;
		}
	}
	printf("%lld", ans);
	return 0;
}
