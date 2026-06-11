#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100000], s = 0;
ll x = 0, y = 0;
bool b = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i, b = !b) {
		s += a[i];
		if (b) {
			if (s <= 0) {
				x += 1 - s;
				s = 1;
			}
		} else if (s >= 0) {
			x += s + 1;
			s = -1;
		}
	}

	b = 1;
	s = 0;
	swap(x, y);
	for (int i = 0; i < n; ++i, b = !b) {
		s += a[i];
		if (b) {
			if (s <= 0) {
				x += 1 - s;
				s = 1;
			}
		} else if (s >= 0) {
			x += s + 1;
			s = -1;
		}
	}
	cout << min(x, y) << endl;
}
