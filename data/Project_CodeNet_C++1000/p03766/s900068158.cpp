#include<bits/stdc++.h>
#define re register
#define N 1000005
#define mod 1000000007
using namespace std;
template<typename _int>
inline void read(re _int&x){
	re _int res=0,flag=1;re char opt;
	while((opt=getchar())<'0'||opt>'9')if(opt=='-')flag=-1;
	while(opt>='0'&&opt<='9'){res=(res<<1)+(res<<3)+opt-48;opt=getchar();}
	x=res*flag;
}
typedef long long ll; 
ll n,dp[N],sum[N],ans;
int main(void){
	re ll i;*dp=1;*sum=1;
	read(n);ans=(n>2);
	if(n==1)return puts("1"),0;
	for(i=1;i<=n;++i){
		(dp[i]+=(sum[i-1]-((i>=2)?dp[i-2]:0)+mod)%mod)%=mod;
//		printf("%lld %lld\n",sum[i-1],((i>=2)?dp[i-2]:0));
		sum[i]=(sum[i-1]+dp[i])%mod;
		if(i<n-1)(ans+=(1ll*(n-1)*(n-1)%mod+min(i+2,n-1))*dp[i]%mod)%=mod;
	}
	printf("%lld\n",((ans+1ll*n*dp[n-1]%mod)%mod+1ll*(n-1)*(n-1)%mod+1)%mod);
	return 0;
}
