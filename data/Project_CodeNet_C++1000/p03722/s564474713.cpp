#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstdint>

using namespace std;

typedef long long signed int ll;

constexpr ll inf = 1000000000000000;

ll c[1000][1000], n, d[1000],m,e[1000];

int main() {
	for (ll i = 0; i < 1000; i++) for (ll j = 0; j < 1000; j++) c[i][j] = -inf;
	for (ll i = 0; i < 1000; i++) d[i] = -inf;
	for (ll i = 0; i < 1000; i++) e[i] = -inf;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll a, b, cc;
		cin >> a >> b >> cc;
		c[a-1][b-1] = cc;
	}
	d[0] = 0;
	bool update = true;
	for (ll i = 0; i < n && update; i++) {
		update = false;
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {
				if (d[k] < d[j] + c[j][k]) {
					d[k] = d[j] + c[j][k];
					update = true;
				}
			}
		}
	}
	for (ll i = 0; i < n && update; i++) {
		update = false;
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {
				if (d[k] < d[j] + c[j][k]) {
					d[k] = d[j] + c[j][k];
					e[k] = 0;
					update = true;
				}
			}
		}
	}
	if (e[n-1] == 0) cout << "inf";
	else cout << d[n-1];
	cout << endl;
}