#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if (H % h == 0 && W % w == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i % h == 0 && j % w == 0) cout << -1 * h * w * 250 + 249;
			else cout << 250;
			if (j == W) cout << endl;
			else cout << " ";
		}
	}
}