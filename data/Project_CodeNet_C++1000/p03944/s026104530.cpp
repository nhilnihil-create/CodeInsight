#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int w1, h1, n;
	cin >> w1 >> h1 >> n;
	int w0 = 0;
	int h0 = 0;
	for (int i = 0; i < n; i++) {
		int x, y, a;
		cin >> x >> y >> a;
		if (a == 1) {
			if (w0 < x)w0 = x;
		}
		else if (a == 2) {
			if (w1 > x)w1 = x;
		}
		else if (a == 3) {
			if (h0 < y)h0 = y;
		}
		else {
			if (h1 > y)h1 = y;
		}
	}
	ll ans = (w1 - w0) * (h1 - h0);
	if ((w1 - w0) < 0 || (h1 - h0) < 0)ans = 0;
	cout << ans << endl;
}