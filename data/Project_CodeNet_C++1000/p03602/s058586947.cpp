
// Problem : D - Restoring Road Network
// Contest : AtCoder Regular Contest 083
// URL : https://atcoder.jp/contests/arc083/tasks/arc083_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 303, mod = 1e9 + 7, inf = 2e9;

int n, a[N][N], dp[N][N];
ll sum = 0;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j]) {
				bool direct = 1;
				for (int k = 1; k <= n; k++) {
					if (a[i][k] && a[k][j] && a[i][j] == a[i][k] + a[k][j]) {
						direct = 0;
					}
				}
				if (direct) {
					dp[i][j] = a[i][j];
					sum += a[i][j];
				}
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] != inf && dp[k][j] != inf && dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	bool no = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j]) {
				if (a[i][j]) {
					no = 1;
				}
			} else if (dp[i][j] != a[i][j]) {
				no = 1;
			}
		}
	}
	cout << (no ? -1 : sum / 2);
}
