#include"bits/stdc++.h"

#define rep(i, N) for(ll i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	ll x, y; cin >> x >> y;
	ll lxl = abs(x), lyl = abs(y);
	bool pos = (x >= 0);

	int ans = 0;
	if (lxl < lyl && !pos) {
		ans++;
		pos = true;
	}
	if (lxl > lyl&& pos) {
		ans++;
		pos = false;
	}

	ans += abs(lxl - lyl);

	if (pos && y < 0) {
		ans++;
	}
	if (!pos && y > 0) {
		ans++;
	}

	cout << ans << endl;

	return 0;
}