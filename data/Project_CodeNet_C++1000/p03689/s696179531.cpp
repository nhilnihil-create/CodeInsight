#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
int h, w, a, b, c, d, e, f, g;
const int k = 400;
signed main() {
	cin >> h >> w >> a >> d;
	b = h / a; c = h % a;
	e = w / d; f = w % d;
	g = c * w + f * h - c * f;
	if (b*e >= g*k) {
		cout << "No\n";
		return 0;
	}
	else {
		cout << "Yes\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (j)cout << ' ';
				if ((i + 1) % a == 0 && (j + 1) % d == 0)cout << -((a*d-1)*k)-1;
				else cout << k;
			}
			cout << endl;
		}
	}
}