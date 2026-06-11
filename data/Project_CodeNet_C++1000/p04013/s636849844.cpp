#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=53;
int N, A;
int x[MAX_N];
ll dp[MAX_N][MAX_N][MAX_N*MAX_N];

void solve()
{
	dp[0][0][0]=1;
	for(int i=0;i<N;++i)for(int j=0;j<=i;++j)for(int k=0;k<=j*50;++k){
		if(dp[i][j][k]){
			dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
			dp[i+1][j][k]+=dp[i][j][k];
		}
	}
	ll ans = 0;
	for(int j=1;j<=N &&j*A<=2500;++j) ans+=dp[N][j][j*A];
	cout << ans;
}

int main()
{
	cin >> N >> A;
	for(int i=0;i<N;++i)cin >> x[i];
	solve();
	return 0;
}