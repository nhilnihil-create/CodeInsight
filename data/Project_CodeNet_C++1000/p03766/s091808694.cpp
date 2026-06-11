#include<cstdio>
#include<algorithm>
#define MN 1000005
using namespace std;
const int mod=1e9+7;
int dp[MN],sum[MN],n,res;
int main(){
	scanf("%d",&n);dp[0]=sum[0]=1;res=1ll*(n-1)*(n-1)%mod;
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+(i-3>=0?sum[i-3]:0),dp[i]%=mod;
		sum[i]=sum[i-1]+dp[i],sum[i]%=mod;
		if(i<n-1)res+=1ll*dp[i]*(n-1)%mod*(n-1)%mod,res%=mod;else res+=1ll*dp[i]*(n-1)%mod,res%=mod;
	}
	for(int i=0;i<n-1;i++)dp[n]+=1ll*dp[i]*((i+n+1)-max(n,i+3)+1)%mod,dp[n]%=mod;res+=(dp[n]+dp[n-1])%mod;printf("%d\n",res%=mod);
}