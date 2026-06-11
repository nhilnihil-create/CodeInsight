#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll test[12345678];
ll ans[12345678];
signed main() {
	ll n, m, cnt = 0, z = 0; cin >> n;
	map<ll, ll> kosuu, saishou;
	vector<ll> v, kari; v.push_back(0);
	for (int h = 1; h <= n; h++) {
		cin >> test[h];
		kosuu[test[h]]++; kari.push_back(test[h]);
		if (saishou[test[h]] == 0) {
			saishou[test[h]] = h;
		}
	}
	sort(kari.begin(), kari.end());
	for (int h = 0; h < kari.size(); h++) {
		if (h == 0) { v.push_back(kari[h]); continue; }
		if (kari[h - 1] != kari[h]) { v.push_back(kari[h]); }
	}
	for (int h = v.size() - 1; h > 0; h--) {
		ans[saishou[v[h]]] += kosuu[v[h]] * (v[h] - v[h - 1]);
		kosuu[v[h - 1]] += kosuu[v[h]];
		saishou[v[h - 1]] = min(saishou[v[h - 1]], saishou[v[h]]);
	}
	for (int h = 1; h <= n; h++) {
		
		cout << ans[h] << endl;
	}
	return 0;
}