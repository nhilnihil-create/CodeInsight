#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 102;
int N;
ll W, w[MAX_N], v[MAX_N];
ll dp[MAX_N][MAX_N][400];

void solve()
{
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<N;++i){
		ll we = w[i]-w[0], va = v[i];
		for(int j=0;j<=i;++j){
			for(int k=0;k<400;++k)if(dp[i][j][k]!=-1){
				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
				dp[i+1][j+1][k+we]=max(dp[i+1][j+1][k+we], dp[i][j][k]+va);
			}
		}
	}
	ll base = w[0];
	ll ans = 0;
	for(int j=1;j<=N;++j)for(int k=0;k<400;++k)if(dp[N][j][k]!=-1 && base*j+k<=W){
		ans = max(ans, dp[N][j][k]);
	}
	cout << ans << '\n';
}

int main()
{
	cin >> N >> W;
	for(int i=0;i<N;++i){
		cin >> w[i] >> v[i];
	}
	solve();
	return 0;
}