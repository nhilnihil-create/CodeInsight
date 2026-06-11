#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll g = 0;
	ll m = 0;
	rep(i, n) {
		cin >> a[i];
		m = max(m, a[i]);
		g = __gcd(g, a[i]);
	}
	if (k > m) {
		cout << "IMPOSSIBLE" << endl;
	} else if (k % g != 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << "POSSIBLE" << endl;
	}
	
	return 0;
}