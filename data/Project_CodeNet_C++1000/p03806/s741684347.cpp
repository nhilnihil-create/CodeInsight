#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int dp[405][405][41];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	rep(i,405)rep(j,405)rep(k,41) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	rep(i,n){
		cin >> a[i] >> b[i] >> c[i];
		rep(j,400)rep(k,400){
			if(j+a[i] >= 401) continue;
			if(k+b[i] >= 401) continue;
			chmin(dp[j][k][i+1], dp[j][k][i]);
			chmin(dp[j+a[i]][k+b[i]][i+1], dp[j][k][i] + c[i]);
		}
	}
	int ans = INF;
	for(int i = 1; i <= 400; i++){
		int ca = i;
		int cb = i * mb;
		if(cb%ma != 0) continue;
		cb /= ma;
		if(cb > 400) continue;
		chmin(ans, dp[ca][cb][n]);
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}