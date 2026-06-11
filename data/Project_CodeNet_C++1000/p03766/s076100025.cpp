#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,ans=0,fr[1000010],dp[1000010];
int main(){
	scanf("%lld",&n);
	dp[0]=1;fr[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(i>=3){dp[i]=(dp[i]+fr[i-3])%mod;}
		fr[i]=(fr[i-1]+dp[i])%mod;
	}
	for(int i=0;i<(n-1);i++){ans=(ans+(dp[i]*(n-1)%mod*n%mod))%mod;}
	ans=(ans+(dp[n-1]*(n-1)%mod))%mod;
	printf("%lld\n",ans+1);
	return 0;
}