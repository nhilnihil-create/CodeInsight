#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int base = (int)1e9+7;
int n, m, dp[5005][5005];
char s[5005];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	dp[0][0] = 1, m = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = (dp[i - 1][0] + 2*dp[i - 1][1] % base) % base;
		for (int j = 1; j <= n; ++j)
			dp[i][j] = (dp[i - 1][j - 1] + 2*dp[i - 1][j + 1] % base) % base;
	}
	printf("%d", dp[n][m]);
	return 0;
}
