#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(401, vector<int>(401)));
	rep(i, n + 1){
		rep(j, 401){
			rep(k, 401){
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	rep(i, n){
		rep(j, 401){
			rep(k, 401){
				if(j < a[i] || k < b[i]) dp[i + 1][j][k] = dp[i][j][k];
				else dp[i + 1][j][k] = min(dp[i][j - a[i]][k - b[i]] + c[i], dp[i][j][k]);
			}
		}
	}
	int out = INF;
	rep(i, 400){
		rep(j, 400){
			if(i != 0 && j != 0 && ma * j == mb * i) out = min(out, dp[n][i][j]);
		}
	}
	cout << (out == INF ? -1 : out) << endl;
}
