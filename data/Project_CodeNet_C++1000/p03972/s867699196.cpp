#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll tate[12345678], yoko[12345678], cost[4321][4321];
signed main() {
	ll n, m, cntn = 0, cntm = 0, ans = 0; cin >> n >> m;
	for (int h = 0; h < n; h++) { cin >> tate[h]; }
	sort(tate, tate + n);
	for (int h = 0; h < m; h++) { cin >> yoko[h]; }
	sort(yoko, yoko + m);
	ll ngtate = 0, ngyoko = 0;// n++; m++;
	while (true) {
		if (cntn == n && cntm == m) { break; }
		if (cntn == n) {
			ans += yoko[cntm];
			cntm++; continue;
		}
		if (cntm == m) {
			ans += tate[cntn];
			cntn++; continue;
		}
		if (tate[cntn] < yoko[cntm]) {
			ans += tate[cntn] * (m + 1 - ngyoko);
			ngtate++; cntn++;
		}
		else {
			ans += yoko[cntm] * (n + 1 - ngtate);
			ngyoko++; cntm++;
		}
	}
	cout << ans << endl;
	cin >> n; return 0;
}