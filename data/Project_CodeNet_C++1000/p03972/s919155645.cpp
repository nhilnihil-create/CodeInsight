#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
typedef pair<ll, int> P;

int main() {
	int W, H;
	cin >> W >> H;
	vector<P> E;
	rep(i, W) {
		ll p;
		cin >> p;
		E.emplace_back(p, 0);
	}
	rep(i, H) {
		ll q;
		cin >> q;
		E.emplace_back(q, 1);
	}
	sort(E.begin(), E.end());
	int cntH = 0, cntW = 0;
	ll ans = 0;
	for (P &e : E) {
		if (e.second) {
			ans += e.first*(W + 1 - cntW);
			cntH++;
		}
		else {
			ans += e.first*(H + 1 - cntH);
			cntW++;
		}
	}
	cout << ans << endl;
}