#include <bits/stdc++.h>
using namespace std;

#define N 5005

int dp[2][N];

char s[N];
int n;

const int mod = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	dp[0][0] = 1;
	int u = 0, v = 1;
	scanf("%d %s", &n, s);
	int m = strlen(s);
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < N; j ++) {
			dp[v][j] = 0;
			if (j > 0) add(dp[v][j], dp[u][j-1]);
			if (j+1 < N) add(dp[v][j], dp[u][j+1]), add(dp[v][j], dp[u][j+1]);
			if (j == 0) add(dp[v][j], dp[u][j]);
		}
		swap(u, v);
	}
	int ans = dp[u][m];
	printf("%d\n", ans);
	return 0;
}
