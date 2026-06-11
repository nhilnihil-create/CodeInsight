#include<bits/stdc++.h>
#pragma O3
#define int long long
using namespace std;
const int N=6000,mod=1e9+7;
int dp[N][N],l;
signed main(){
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	l=s.length();
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		for(int j=1;j<=n;j++){
			dp[i][j]=(dp[i-1][j-1]*2+dp[i-1][j+1])%mod;
		}
	}
	for(int i=1;i<=l;i++){
		dp[n][l]=(dp[n][l]*(mod+1)/2)%mod;
	}
	cout<<dp[n][l];
}
