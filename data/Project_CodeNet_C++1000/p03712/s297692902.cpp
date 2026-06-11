#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> a(H, vector<char>(W));
	rep(i, H) {
		rep(j, W) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < H + 2; i++) {
		for (int j = 0; j < W + 2; j++) {
			if (i == 0 || i == H + 1 || j == 0 || j == W + 1) printf("#");
			else printf("%c", a[i - 1][j - 1]);
		}
		printf("\n");
	}
}


