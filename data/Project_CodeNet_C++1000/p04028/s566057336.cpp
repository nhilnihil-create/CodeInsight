#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define lbd(a, x) lower_bound(all(a), x)
const int mod = 1e9 + 7;
const int N = 5100;
int dp[N][N][2];
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int k = s.size();
	dp[0][0][1] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			dp[i][j][1] = (dp[i - 1][j + 1][0] + dp[i - 1][j + 1][1]) * 2ll % mod;
			if(j) {
				dp[i][j][0] = (dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0]) % mod;
			} else {
				dp[i][j][1] = ((ll) dp[i][j][1] + dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
			}
		}
	}
	cout << (dp[n][k][0] + dp[n][k][1]) % mod << '\n';
	return 0;
}
