#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int dp[50][500][500];

void chmin(int& a, int b) {
	if (a > b) {
		a = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ma, mb;
	cin >> n >> ma >> mb;
	rep(i, 50)rep(j, 500)rep(k, 500) dp[i][j][k] = inf;
	dp[0][0][0] = 0;
	rep(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		rep(j, 500)rep(k, 500) {
			if (dp[i][j][k] == inf) continue;
			chmin(dp[i + 1][j][k], dp[i][j][k]);
			chmin(dp[i + 1][j + a][k + b], dp[i][j][k] + c);
		}
	}
	int ans = inf;
	rrep(i, 500)rrep(j, 500) {
		if (i * mb == j * ma) chmin(ans, dp[n][i][j]);
	}
	cout << (ans == inf ? -1 : ans) << endl;
	return 0;
}
