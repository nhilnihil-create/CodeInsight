#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;

ll test[1234567];
signed main() {
	ll n, mae = 0, ato = 0; cin >> n;
	rep(i, 3 * n) { cin >> test[i]; }

	priority_queue<ll, vector<ll>, greater<ll>> que1;
	rep(i, n) { que1.push(test[i]); mae += test[i]; }
	vector<ll> v1(n * 3); v1[n] = mae;
	for (int h = n; h < 2 * n; h++) {
		mae += test[h]; que1.push(test[h]);
		mae -= que1.top(); que1.pop();
		v1[h + 1] = mae;
	}

	priority_queue<ll, vector<ll>, less<ll>> que2;
	for (int h = 3 * n - 1; h >= 2 * n; h--) { que2.push(test[h]); ato += test[h]; }
	vector<ll> v2(n * 3); v2[2 * n] = ato;
	for (int h = 2 * n - 1; h >= n; h--) {
		ato += test[h]; que2.push(test[h]);
		ato -= que2.top(); que2.pop();
		v2[h] = ato;
	}
	ll ans = 0 - INF;
	for (int h = n; h <= 2 * n; h++) {
		ans = max(ans, v1[h] - v2[h]);
	}
	cout << ans << endl;
	return 0;
}