#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, c = 0, mi = 10000000000;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v.at(i);
	}
	for (ll i = -100; i < 101; i++) {
		for (ll j = 0; j < n; j++) {
			c += pow( i -v.at(j), 2);
		}
		mi = min(mi, c);
		c = 0;
	}
	cout << mi << endl;
	return 0;
}
