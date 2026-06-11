#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll ans;

int main() {
	cin >> n;
	ll lim = 1;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if (x == lim) {
			lim++;
			continue;
		}
		ll add = (x - 1) / lim;
		ans += add;
		if (x - add * lim == 1 && lim == 1) lim++;
	}	
	cout << ans;
}
