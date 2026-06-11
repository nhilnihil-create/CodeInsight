#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int H, W, N;
	cin >> H >> W >> N;

	vector<vector<int>> v(H, vector<int>(W));
	vector<int> C(N);
	for (int i = 0; i < N; i++) cin >> C.at(i);

	int x, y;
	x = 0;
	y = 0;
	for (int i = 0; i < N; ) {
		if (C.at(i) == 0) {
			i++;
			continue;
		}
		while (C.at(i)) {
			//cout << x << ' ' << y << endl;
			v.at(x).at(y) = i + 1;
			if (x % 2) y--;
			else y++;

			if (y < 0) {
				x++;
				y = 0;
			}
			else if (y == W) {
				x++;
				y = W - 1;
			}

			C.at(i)--;
		}

		if (x >= H) break;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << v.at(i).at(j);
			if (j == W - 1) cout << endl;
			else cout << ' ';
		}
	}
}