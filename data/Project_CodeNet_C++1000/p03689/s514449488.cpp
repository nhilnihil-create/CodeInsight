#include <bits/stdc++.h>
#define ld long double
using namespace std;

const int mx = 1e9;
int H, W, h, w;

ld rg(int a, int b) {
	ld x = a, y = b;
	return x / y;
}

const int bj = 100000;
void irk(int &a, int &b, ld x, ld y) {
	for(b = bj; b <= mx; b += bj) {
		int l = 1, r = mx;
		while(l < r) {
			int m = (l + r) / 2;
			ld z = rg(m, b);
			if(z <= x) {
				l = m + 1;
			} else if(z >= y) {
				r = m - 1;
			} else {
				a = m;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W >> h >> w;
	ld x = rg((H / h) * (W / w), H * W - (H / h) * (W / w));
	ld y = rg(1, h * w - 1);
	if(x >= y) {
		return cout << "No" << endl, 0;
	}
	int a = 0, b = 0;
	irk(a, b, x, y);
	cout << "Yes\n";
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			if(i % h == 0 && j % w == 0) {
				cout << -b << " ";
			} else {
				cout << a << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// (H/h*W/w) | (H*W-H/h*W/w) < a | b < 1 | (h*w-1)
