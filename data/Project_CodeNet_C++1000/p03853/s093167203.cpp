#include <bits/stdc++.h>
using namespace std;

char a[1 << 10][1 << 10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int H, W; cin >> H >> W;
	for (int i = 1; i <= H; i++) cin >> a[i];
	for (int i = 1; i <= H * 2; i++) {
		for (int j = 0; j < W; j++) cout << a[(i + 1) / 2][j];
		cout << endl;
	}
	return 0;
}
