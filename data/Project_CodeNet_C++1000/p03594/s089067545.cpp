#include<cstdio>
using namespace std;
int n, m, k, x, y, _2k;
char col[] = "RGBY";
char mp[505][505];

int main() {
	scanf("%d%d%d", &n, &m, &k), _2k = k * 2;
	for(register int i = 1; i <= n; ++i)
		for(register int j = 1; j <= m; ++j) {
			x = n + i + j, y = m + i - j;
			mp[i][j] = col[2 * ((x / k) & 1) + ((y / k) & 1)];
		}
	for(register int i = 1; i <= n; ++i) {
		for(register int j = 1; j <= m; ++j)
			putchar(mp[i][j]);
		putchar('\n');
	}
	return 0;
} 