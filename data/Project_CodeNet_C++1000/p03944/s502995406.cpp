#include "bits/stdc++.h"
using namespace std;

int main() {
	int W, H, N;
	cin >> W >> H >> N;
	vector<vector<int>> data(W, vector<int>(H));
	for (int i = 0; i < N; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
		x--; y--;
		if (1 == a) {
			for (int j = 0; j < W; ++j) {
				for (int k = 0; k < H; ++k) {
					if (j <= x) {
						data[j][k] = 1;
					}
				}
			}
		}
		else if (2 == a) {
			for (int j = 0; j < W; ++j) {
				for (int k = 0; k < H; ++k) {
					if (j > x) {
						data[j][k] = 1;
					}
				}
			}
		}
		else if (3 == a) {
			for (int j = 0; j < W; ++j) {
				for (int k = 0; k < H; ++k) {
					if (k <= y) {
						data[j][k] = 1;
					}
				}
			}
		}
		else {
			for (int j = 0; j < W; ++j) {
				for (int k = 0; k < H; ++k) {
					if (k > y) {
						data[j][k] = 1;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < W; ++j) {
		for (int k = 0; k < H; ++k) {
			if (0 == data[j][k]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}