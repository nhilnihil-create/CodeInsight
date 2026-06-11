#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll res[1223456], test[1234567];
signed main() {
	ll n, x, l, q; cin >> n;
    vector<vector<ll>> table(71, vector<ll>(n + 2));
	for (int h = 0; h < n; h++) { cin >> test[h]; }
	cin >> l >> q;
	ll mae = -1, ato = 0;
	while (true) {
		if (mae == n - 2) { break; }
		mae++;
		while (true) {
			if (ato != n - 1 && test[ato + 1] - test[mae] <= l) { ato++; }
			else { break; }
		}
		//cout << ' ' << mae + 1 << ' ' << ato + 1 << endl;
		table[0][mae + 1] = ato + 1;
	}
    for (int i = 1; i < 70; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j] = table[i - 1][table[i - 1][j]];
			//cout << i << ' ' << j << ' ' << table[i][j] << endl;
        }
    }
    for (int h = 0; h < q; h++) {
		ll a, b, ans = 0; cin >> a >> b; 
		if (a > b) { swap(a, b); } ll cnt = a;
		while (true) {
			if (cnt >= b) { break; }
			ll ok = 0, ng = 70, mid = (ok + ng) / 2;
			while (ng - ok > 1) {
				if (table[mid][cnt] != 0 && table[mid][cnt] <= b) { ok = mid; }
				else { ng = mid; }
				mid = (ok + ng) / 2;
				//cout << table[mid][cnt] << endl;
			}
			ans += pow(2, ok); cnt = table[ok][cnt];
		}
		cout << ans << endl;
    }
    return 0;
}