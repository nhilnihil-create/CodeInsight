#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 100005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

LL dp[MAXN][3];

void solve() {
	int n; read(n);
	int x; read(x);
	dp[1][0] = x;
	dp[1][1] = dp[1][2] = -INF;
	for (int i=2;i<=n;++i) {
		read(x);
		if (x < 0) {
			dp[i][0] = -INF;
			dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + x;
			dp[i][2] = max(dp[i-1][1], dp[i-1][2]) - x;
		} else {
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + x;
			dp[i][1] = max(dp[i-1][1], dp[i-1][2]) - x;
			dp[i][2] = dp[i-1][2] + x;
		}
	}	
	printf("%lld\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
}

int main() {
	solve();
	return 0;
}
