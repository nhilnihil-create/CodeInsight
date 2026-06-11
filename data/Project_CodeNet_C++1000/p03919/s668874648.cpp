#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<string>> s(H, vector<string>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) { cin >> s[i][j]; }
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (s[i][j] == "snuke") {
				cout << (char)('A' + j) << i + 1 << endl;
				return 0;
			}
		}
	}

	return 0;
}
