#include <bits/stdc++.h>
using namespace std;

int res[105][105];
int main() {
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	int x = 0, y = 0;
	for(int c = 1; c <= n; c++) {
		int k; scanf("%d", &k);
		for(int i = 0; i < k; i++) {
			if(x & 1) {
				res[x][y--] = c;
				if(y < 0) y = 0, x++;
			}
			else {
				res[x][y++] = c;
				if(y == w) y = w - 1, x++;
			}
		}
	}
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) printf("%d%c", res[i][j], j == w - 1 ? '\n' : ' ');
	return 0;
}
