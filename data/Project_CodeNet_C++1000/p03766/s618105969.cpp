//It is coded by ning-mew on 10.14
//Problem : arc 071 F
#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn=1e6+7;
const LL mod=1e9+7;

LL n,dp[maxn],s[maxn],ans;

LL mul(LL A,LL B){return (A*B)%mod;}
LL add(LL A,LL B){return (A+B)%mod;}
int main(){
    scanf("%lld",&n);if(n==1){printf("1\n");return 0;}
    dp[0]=1;s[0]=1;
    ans=add(ans,mul(n-1,n-1));ans=add(ans,1);
    for(int i=1;i<=n;i++){
	dp[i]=dp[i-1];if(i>=3)dp[i]=add(dp[i],s[i-3]);
	s[i]=add(s[i-1],dp[i]);//s[1]=dp[1];
	//cout<<i<<' '<<dp[i]<<endl;
	if(i<n-1)ans=add(ans,mul(dp[i],mul(n-1,n-1)));
	if(i==n-1)ans=add(ans,mul(dp[i],n-1));
	if(i!=n&&i!=n-1)ans=add(ans,mul(dp[i],i+1));
    }
    //cout<<dp[n]<<endl;
    ans=add(ans,dp[n]);
    printf("%lld\n",ans);
    return 0;
}
