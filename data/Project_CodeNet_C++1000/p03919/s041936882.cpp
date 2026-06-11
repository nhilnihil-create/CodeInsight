#include"bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<string>> S(H, vector<string>(W));
	char c;
	int x;
	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			cin >> S[i][j];
			if (S[i][j] == "snuke") {
				c = 'A' + j;
				x = 1 + i;
			}
		}
	}
	cout << c << x << endl;
	return 0;
}