#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

int s[2000];

int main() {
	int H, W, h, w; cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if (W%w != 0) {
		for (int i = 1; i <= W; ++i) s[i] = 1000;
		for (int i = 0; i < W; ++i) s[i + w] = s[i] - 1;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cout << s[j + 1] - s[j] << (j < W - 1 ? " " : "\n");
			}
		}
	}
	else {
		for (int i = 1; i <= H; ++i) s[i] = 1000;
		for (int i = 0; i < H; ++i) s[i + h] = s[i] - 1;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cout << s[i + 1] - s[i] << (j < W - 1 ? " " : "\n");
			}
		}
	}
	return 0;
}