#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, w, d; cin >> h >> w >> d;
	vector<vector<int>> col(h, vector<int>(w, -1));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int ti = i / d, tj = j / d;
			int di = i % d, dj = j % d;
			int s1 = (di + dj < d), s2 = (di > dj);
			int color = s1 * 2 + s2;
			if (ti + tj & 1) color = 3 - color;
			col[i][j] = color;
		}
	}
	char color[] = "RYGB";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << color[col[i][j]];
		}
		cout << "\n";
	}
	return 0;
}
