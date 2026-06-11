#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, ma, mb;
	cin >> n >> ma >> mb;

	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];

	int max_m = 404;
	int INF = 1e9;
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(max_m, vector<int>(max_m, INF)));
	dp[0][0][0] = 0;

	rep(i, n){
		rep(j, max_m) rep(k, max_m) dp[(i+1)%2][j][k] = INF;

		rep(j, max_m){
			rep(k, max_m){
				chmin(dp[(i+1)%2][j][k], dp[i%2][j][k]);
				if(j + a[i] < max_m && k + b[i] < max_m){
					chmin(dp[(i+1)%2][j + a[i]][k + b[i]], dp[i%2][j][k] + c[i]);
				}
			}
		}
	}

	int ans = INF;
	for(int y = 1; max(y * ma, y * mb) < max_m; y++){
		chmin(ans, dp[n%2][y * ma][y * mb]);
	}

	if(ans == INF){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}	
}
