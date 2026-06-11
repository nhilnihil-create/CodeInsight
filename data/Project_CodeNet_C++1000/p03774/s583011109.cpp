#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a >= b) { a = b; return true; } return false; }

int main() {

	int n, m; cin >> n >> m;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	vector<ll> c(m), d(m);
	for (int i = 0; i < m; i++) {
		cin >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		ll ans;
		ll dist = 9223372036854775807LL;
		for (int j = m - 1; j >= 0; j--) {
			ll tmpDist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			if (chmin(dist, tmpDist)) {
				ans = j;
			}
		}
		cout << ans  + 1 << endl;
	}
	return 0;
}