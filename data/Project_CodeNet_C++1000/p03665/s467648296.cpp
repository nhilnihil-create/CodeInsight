#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll comb(ll a, ll b) {
	ll ret = 1;
	rep(i, b) ret *= (a - i);
	rep(i, b) ret /= (i + 1);
	return ret;
}

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	bool even = true;
	rep(i, n) {
		if (a[i] % 2 == 1) even = false;
	}
	if (even) {
		if (p == 0) cout << (1LL << n) << endl;
		else cout << 0 << endl;
		return 0;
	}
	cout << (1LL << (n - 1)) << endl;
	return 0;
}
