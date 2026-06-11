#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n, k; cin >> n >> k;
	vector<pair<ll, ll>> pa;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		pa.push_back({ a,b });
	}
	sort(pa.begin(), pa.end());

	ll sum = 0;
	ll ans;
	for (int i = 0; i < n; i++) {		
		sum += pa[i].second;
		if (k <= sum) {
			ans = pa[i].first;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}