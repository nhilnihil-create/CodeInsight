#include <bits/stdc++.h>
using namespace std;

char a[2048][2048];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, d; cin >> n >> m >> d;
	if (d & 1) {
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			if ((i + j) & 1) a[i][j] = 'R';
			else a[i][j] = 'G';
		}
	} else {
		int x = d;
		for (int i = 0; i < d / 2; i++) {
			for (int j = 0; j < d + d; j++) {
				if (j < i) a[i][j] = 'B';
				else if (j < i + x) a[i][j] = 'R';
				else if (j < i + d) a[i][j] = 'Y';
				else if (j < i + d + x) a[i][j] = 'G';
				else a[i][j] = 'B';
			}
			x -= 2;
		}
		for (int i = d / 2; i < d; i++) {
			for (int j = 0; j < d + d; j++) {
				if (j < d - i) a[i][j] = 'B';
				else if (j < d - i + x) a[i][j] = 'G';
				else if (j < d - i + d) a[i][j] = 'Y';
				else if (j < d - i + d + x) a[i][j] = 'R';
				else a[i][j] = 'B';
			}
			x += 2;
		}
		for (int i = d; i < d + d; i++) for (int j = 0; j < d + d; j++) {
			a[i][j] = a[i - d][j];
			if (a[i][j] == 'R') a[i][j] = 'G';
			else if (a[i][j] == 'G') a[i][j] = 'R';
			else if (a[i][j] == 'B') a[i][j] = 'Y';
			else a[i][j] = 'B';
		}
		for (int i = 0; i < d + d; i++) for (int j = d + d; j < m; j++) a[i][j] = a[i][j - d - d];
		for (int i = d + d; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = a[i - d - d][j];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
cout << a[i][j];
if (j == m - 1) cout << endl;
}
//	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int u = 0; u < n; u++) for (int v = 0; v < m; v++) if (abs(i - u) + abs(j - v) == d) {
//		if (a[i][j] == a[u][v]) cerr << i << " " << j << " " << u << " " << v << endl;
//		assert(a[i][j] != a[u][v]);
//	}
	return 0;
}

