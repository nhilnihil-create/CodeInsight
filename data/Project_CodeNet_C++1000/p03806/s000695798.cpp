#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(int i=0;i<n;i++)
#define int long long
#define ggr getchar();getchar();return 0;
#define prique priority_queue
#define mod 1000000007
#define inf 1e15
using namespace std;
typedef pair<int, int>P;
void yes() { cout << "Yay!" << endl; }
void no() { cout << ":(" << endl; }
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y)* mod_pow(kai(y, y), mod - 2, mod) % mod;
}
struct edge { int to, cost; };
int n, ma, mb;
int a[45], b[45], c[45];
int dp[45][444][444];//i番目までの薬から物質Aをjグラム、物質Bをkグラムとるときの最小費用
signed main() {
	cin >> n >> ma >> mb;
	rep(i, n)cin >> a[i] >> b[i] >> c[i];
	rep(i, n + 1) {
		rep(j, 444) {
			rep(k, 444)dp[i][j][k] = inf;
		}
	}
	dp[0][0][0] = 0;
	rep(i, n) {
		for (int j = 0; j < 444; j++) {
			for (int k = 0; k < 444; k++) {
				if (j < a[i] || k < b[i])dp[i + 1][j][k] = dp[i][j][k];
				else dp[i + 1][j][k] = min(dp[i][j - a[i]][k - b[i]] + c[i], dp[i][j][k]);
			}
		}
	}
	int ans = mod;
	for (int i = ma; i <= 422; i += ma) {
		if (dp[n][i][i / ma * mb] != inf)ans = min(ans, dp[n][i][i / ma * mb]);
	}
	if (ans == mod)puts("-1");
	else cout << ans << endl;
	ggr
}
