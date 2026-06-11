#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int sz=1e6+7;
typedef long long ll;
int n;
ll ans;
ll dp[sz],sum[sz];
// dp[i]表示第一位可以自由选择的长度为i的合法方案数 
int main(){
	scanf("%d",&n);
//	if(n==2) return printf("4\n"),0;
	dp[0]=dp[1]=1;
	sum[0]=1;
	sum[1]=2;
	for(int i=2;i<=n;i++){
		dp[i]=(sum[i-1]-dp[i-2]+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	for(int i=0;i<=n-2;i++) (ans+=dp[i]*(n-1)%mod*n%mod)%=mod;
	(ans+=dp[n-1]*(n-1)%mod)%=mod;
	ans=(ans+1)%mod;
//	(ans+=dp[n])%=mod;
	printf("%lld\n",ans);
}