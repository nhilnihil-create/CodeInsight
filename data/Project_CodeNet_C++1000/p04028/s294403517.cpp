#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
const int mod=1e9+7;
int dp[maxn][maxn];
signed main() {
	int n;
	string str;
	cin>>n>>str;
	int m=str.length();
	dp[0][0]=1;
	for(int i=1 ; i<=n ; i++) {
		for(int j=0 ; j<=i ; j++) {
			if(i==1&&j==0) dp[1][0]=1;
			else {
				if(j==0) dp[i][j]=(dp[i-1][j]+2*dp[i-1][1])%mod;
				else dp[i][j]=(2*dp[i-1][j+1]+dp[i-1][j-1])%mod;
			}
		}
	}
	cout<<dp[n][m]%mod;
}