#include<bits/stdc++.h>
#define FOR(i,a,b) for (register ll i=(a);i<=(b);i++)
#define For(i,a,b) for (register ll i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register ll j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pb push_back
#define pii pair<ll,ll>
#define MP make_pair
using namespace std;
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
ll n,ans=0,dp[N],pre[N];
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
inline void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int main()
{
	n=read();
	dp[0]=1;
	dp[1]=1;
	pre[1]=2;
	FOR(i,2,n)
	{
		dp[i]=(pre[i-1]-dp[i-2]+mod)%mod;
		pre[i]=(pre[i-1]+dp[i])%mod;
	}
	dp[0]=1;
	FOR(i,0,n-2) ans=(ans+dp[i]*n%mod*(n-1)%mod)%mod;
	ans=(ans+dp[n-1]*(n-1)%mod)%mod;
	ans=(ans+1)%mod;
	write(ans);
	return 0;
}
