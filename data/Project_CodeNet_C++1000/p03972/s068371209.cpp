#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair<int, int>pi;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
typedef pair<P, P> PPP;

const ll MOD = 1e9 + 7;
const ll INF = 9e18;
const double DINF = 5e14;
const double eps = 1e-10;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second

int h, w, hcnt, wcnt;
ll ans;
P p[200010];

int main() {
	cin >> w >> h;
	wcnt = w + 1, hcnt = h + 1;
	for (int i = 0;i < w;i++) {
		cin >> p[i].fr;
		p[i].sc = 0;
	}
	for (int i = 0;i < h;i++) {
		cin >> p[i + w].fr;
		p[i + w].sc = 1;
	}
	sort(p, p + w + h);
	for (int i = 0;i < w + h;i++) {
		if (!p[i].sc) {
			wcnt--;
			ans += p[i].fr*hcnt;
		}
		else {
			hcnt--;
			ans += p[i].fr*wcnt;
		}
	}
	cout << ans << endl;
	return 0;
}