#include <bits/stdc++.h>

const int kN = 500 + 5;

int mat[kN][kN];

int main() {
	int H, W, h, w, s = 0; scanf("%d%d%d%d", &H, &W, &h, &w);
	for(int i = 1; i <= H; ++i)
		for(int j = 1; j <= W; ++j) mat[i][j] = 1000;
	for(int i = 1; i <= H; ++i)
		for(int j = 1; j <= W; ++j) {
			if(i % h == 0 && j % w == 0)
				mat[i][j] = -h * w * 1000 + 999;
		}
	for(int i = 1; i <= H; ++i)
		for(int j = 1; j <= W; ++j)
			s += mat[i][j];
	if(s > 0) {
		printf("Yes\n");
		for(int i = 1; i <= H; ++i) {
			for(int j = 1; j <= W; ++j) printf("%d ", mat[i][j]);
			printf("\n");
		}
	} else {
		printf("No\n");
	}
	return 0;
}