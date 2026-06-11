#include <bits/stdc++.h>
using namespace std;

long long h, w, n;
long long q[10];
int mat[6][6];
int sum[6][6];

set <pair <int, int> > s;

void calc (int x, int y) {
	memset (mat, 0, sizeof mat);

	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j) {
			mat[i][j] = s.count (make_pair (x + i - 3, y + j - 3));
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + mat[i][j];
		}

	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			int xc = x + i - 3, yc = y + j - 3;
			if (xc < 1 || xc > h - 2 || yc < 1 || yc > w - 2) continue;

			int temp = sum[i + 2][j + 2] - sum[i - 1][j + 2] - sum[i + 2][j - 1] + sum[i - 1][j - 1];
			q[temp]--;
			q[temp + 1]++;
		}
	}
}

int main () {

	cin >> h >> w >> n;

	q[0] = (h - 2LL) * (w - 2LL);

	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf ("%d %d", &x, &y);
		calc (x, y);
		s.insert (make_pair (x, y));
	}

	for (int i = 0; i <= 9; ++i)
		printf ("%lld\n", q[i]);


	return 0;
}