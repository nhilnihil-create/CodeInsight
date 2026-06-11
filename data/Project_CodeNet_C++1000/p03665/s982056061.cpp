#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<vector<ll>> dp(n+1, vector<ll>(5505, 0));
	dp[0][0] = 1;
	rep(i,n){
		rep(j,5001){
			dp[i+1][j] += dp[i][j];
			dp[i+1][j+a[i]] += dp[i][j];
		}
	}
	ll ans = 0;
	rep(j,5001){
		if(j%2 == p) ans += dp[n][j];
	}
	cout << ans << endl;
	return 0;
}