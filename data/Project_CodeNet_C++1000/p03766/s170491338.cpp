#include <bits/stdc++.h>
#define N 1000005
#define ll long long
#define For(i,x,y) for(int i=(x);i<=(y);++i)
#define Rof(i,x,y) for(int i=(x);i>=(y);--i)
#define Edge(x) for(int i=head[x];i;i=e[i].nxt)
#define mset(x,y) memset(x,y,sizeof(x))
#define strL strlen
#define p_b push_back
#define mcpy(x,y) memcpy(x,y,sizeof(x))
#define lson l,mid,(o<<1)
#define rson mid+1,r,((o<<1)|1)
#define Ls (t[o].ls)
#define Rs (t[o].rs)
#define mod 1000000007
using namespace std;
ll sum[N],dp[N],_[N];
int main(){
	int n;ll ans=0;
	scanf("%d",&n);
	dp[0]=sum[0]=1;
	For(i,1,n-1){
		dp[i]=dp[i-1];
		if(i>=3) (dp[i]+=sum[i-3])%=mod;
		sum[i]=(sum[i-1]+dp[i])%mod; 
	}
	For(i,0,n-2) (ans+=1ll*dp[i]*n%mod*(1ll*n-1)%mod)%=mod;
	(ans+=dp[n-1]*(1ll*n-1)%mod)%=mod;
	printf("%lld\n",(ans+1)%mod);
}