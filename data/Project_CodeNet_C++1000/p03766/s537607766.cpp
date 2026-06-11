#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1000005;
const int mod=1000000007;

int n,ans;
int dp[N],s[N];

int main(){
	int i;
	scanf("%d",&n);
	if (n==1){
		printf("%d\n",n);
		return 0;
	}
	dp[0]=dp[1]=s[0]=1; s[1]=2;
	for (i=2;i<n;i++){
		dp[i]=(s[i-1]-dp[i-2])%mod;
		s[i]=(s[i-1]+dp[i])%mod;
	}
	ans=1ll*dp[n-1]*n%mod;
	(ans+=1ll*dp[n-2]*(n-1)%mod*n%mod)%=mod;
	for (i=0;i<n-2;i++){
		(ans+=1ll*dp[i]*(i+2)%mod*n%mod)%=mod;
		(ans+=1ll*dp[i]*(n-i-3)%mod*(n-1)%mod)%=mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}