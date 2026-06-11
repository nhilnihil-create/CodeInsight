#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

#define st first
#define nd second

typedef pair<int,int> pun;
typedef long long ll;

int dx[4] = {-1, 1, 1, -1};
int dy[4] = {1, 1, -1, -1};
int color[N][N];
int n, m, d, r;

void maluj(int x, int y, int c) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	color[x][y] = c;
}

char farba(int x) {
	switch (x) {
		case 1 : return 'R';
		case 2 : return 'G';
		case 3 : return 'B';
		case 4 : return 'Y';
	}
	return '.';
}

int main() {
	scanf("%d%d%d", &n, &m, &d);
	if (d % 2) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				color[i][j] = (i + j) % 2 + 1;
			}
		}
	} else {
		r = d/2;
		for (int i = 0; d * (i-1) < n; i ++) {
			int x = d * i;
			for (int j = 0; d * (j-1) < m; j ++) {
				int y = d * j - 1;
				for (int m = 0; m < r; m ++) {
				for (int k = 0; k < r - m; k ++) {
					for (int a = 0; a < 4; a ++) {
						maluj(x + dx[a] * m, y + k * dy[a], (i + j) % 2 + 1);
						maluj(x + dx[a] * m, y + k * dy[a] + 1, (i + j) % 2 + 1);
						
						maluj(x + r + dx[a] * m, y + k * dy[a] + r, 2 + (i + j) % 2 + 1);
						maluj(x + r + dx[a] * m, y + k * dy[a] + r + 1, 2 + (i + j) % 2 + 1);
					}
				}
				}
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			printf("%c", farba(color[i][j]));
		}
		printf("\n");
	}
}
