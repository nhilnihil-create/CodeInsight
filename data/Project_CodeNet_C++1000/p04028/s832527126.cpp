#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;
const long long mod = 1000000007;
const double eps = 1e-11;
const int inf = 1ll << 61;
int dp[5005][5005];//現在i回目でj文字ある
signed main() {
	int n; cin >> n; string s; cin >> s;
	dp[0][s.size()]++;
	rep(i, n) {
		rep(j, 5002) {
			dp[i+1][j + 1] += dp[i][j] * 2;
			dp[i+1][max(0ll,j - 1)] += dp[i][j];
			dp[i + 1][j + 1] %= mod;
			dp[i + 1][max(0ll,j - 1)] %= mod;
		}
	}
	cout << dp[n][0] << endl;
}