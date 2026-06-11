#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define INF	1e18
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
long long dp[3][MAXN], a[MAXN];
void update (long long &x, long long y) {
	x = max(x, y);
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 0; i < MAXN; i++)
		dp[0][i] = dp[1][i] = dp[2][i] = -INF;
	dp[0][1] = a[1];
	for (int i = 1; i < n; i++)
		if (a[i + 1] >= 0) {
			//Non - parentheses
			update(dp[0][i + 1], dp[0][i] + a[i + 1]);
			update(dp[1][i + 1], dp[1][i] - a[i + 1]);
			update(dp[0][i + 1], dp[1][i] - a[i + 1]);
			update(dp[2][i + 1], dp[2][i] + a[i + 1]);
			update(dp[1][i + 1], dp[2][i] + a[i + 1]);
			update(dp[0][i + 1], dp[2][i] + a[i + 1]);
		} else {
			//Non - parentheses
			update(dp[0][i + 1], dp[0][i] + a[i + 1]);
			update(dp[1][i + 1], dp[1][i] - a[i + 1]);
			update(dp[0][i + 1], dp[1][i] - a[i + 1]);
			update(dp[2][i + 1], dp[2][i] + a[i + 1]);
			update(dp[1][i + 1], dp[2][i] + a[i + 1]);
			update(dp[0][i + 1], dp[2][i] + a[i + 1]);
			//Add - parentheses
			update(dp[1][i + 1], dp[0][i] + a[i + 1]);
			update(dp[2][i + 1], dp[1][i] - a[i + 1]);
		}
	cout << dp[0][n] << endl;
	return 0;
}