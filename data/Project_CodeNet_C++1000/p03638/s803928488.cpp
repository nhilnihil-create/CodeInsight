#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, w, n, x, mat[112][112];

	int l = 0, c = 0;

	scanf("%d %d", &h, &w);

	scanf("%d", &n);

	int sum = 1;
	for (int i=1; i<=n; ++i) {
		scanf("%d", &x);

		while (x--) {			
			mat[l][c] = i;

			if ((sum > 0 && c == w-1) || (sum < 0 && c == 0)) {
				++l, sum*=-1;
			}
			else {
				c+=sum;
			}
		}
	}

	for (int i=0; i<h; ++i) {
		for (int j=0; j<w; ++j) {
			printf("%d ", mat[i][j]);
		}
		puts("");
	}

	return 0;
}