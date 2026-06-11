#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x = 1, y = 1, z = 2, m;

int main() {
	cin >> n;
	for (int i = 0, t, a, c; i < n; ++i) {
		cin >> t >> a;
		c = t + a;
		m = max((x + t - 1) / t * c, (y + a - 1) / a * c);
		z = (m + c - 1) / c * c;
		x = z / c * t;
		y = z / c * a;
	}
	cout << z << endl;
}
