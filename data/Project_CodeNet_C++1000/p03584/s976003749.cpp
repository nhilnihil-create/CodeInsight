#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int n;
ll k, a[100005], b[100005], dp[100005][35];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	ll ma = 0;
	for (int i = 1; i <= n; i++) {
		bool ok = true;
		for (int p = 0; p < 30; p++) {
			if (k >> p & 1) continue;
			else if (a[i] >> p & 1) ok = false;
		}
		if (ok) ma += b[i];
	}
	for (int i = 1; i <= n; i++) {
		FOR(j, 30) {
			if (!(k >> j & 1)) continue;
			bool ok = true;
			if (a[i] >> j & 1) ok = false;
			for (int p = j+1; p < 30; p++) {
				if (k >> p & 1) continue;
				else if (a[i] >> p & 1) ok = false;
			}
			if (ok) dp[i][j] = dp[i-1][j] + b[i];
			else dp[i][j] = dp[i-1][j];
		}
	}
	for (int j = 0; 1 << j <= k; j++) {
		ma = max(ma, dp[n][j]);
	}
	cout << ma << endl;
	return 0;
}