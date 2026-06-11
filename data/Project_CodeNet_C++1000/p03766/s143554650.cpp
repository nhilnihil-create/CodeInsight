#include<bits/stdc++.h>
#define maxn 1010000
#define mod 1000000007
using namespace std;
int ans,dp[maxn],n,s[maxn];
int main(){
	scanf("%d",&n);
	dp[1]=n,s[1]=dp[1];
	dp[2]=1ll*n*n%mod,s[2]=(dp[1]+dp[2])%mod; 
	for(int i=3;i<=n;++i){
		dp[i]=(dp[i-1]+s[i-3]+1ll*(n-1)*(n-1)+n-i+2)%mod;
		s[i]=(s[i-1]+dp[i])%mod;
	}
	printf("%d",dp[n]);
}