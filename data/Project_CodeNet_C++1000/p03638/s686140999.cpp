
// D - Grid Coloring

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int grid[100][100];
int a[10001];

int main() {
	int H, W, N;
	cin >> H >> W >> N;

	for (int i=1; i<=N; i++) {
		cin >> a[i];
	}

	char dir = 'r';
	int color = 1;
	int step = 0;
	int r = 0, c = 0;
	while(1) {
		grid[r][c] = color;
		step++;
		a[color]--;

		if (step == H * W) break;

		if (a[color] == 0) color++;

		if (dir == 'R') {
			if (c == W - 1) {
				dir = 'D';
			}
		} else if (dir == 'L') {
			if (c == 0) {
				dir = 'D';
			}
		} else {
			// dir == 'D'
			if (W == 1) dir = 'D';
			else if (c == 0) dir = 'R';
			else dir = 'L';
		}

		if (dir == 'R') c++;
		else if (dir == 'L') c--;
		else r++;
	}

	for (int r=0; r<H; r++) {
		for (int c=0; c<W; c++) {
			if (c != 0) cout << " ";
			cout << grid[r][c];
		}
		cout << endl;
	}

	return 0;
}