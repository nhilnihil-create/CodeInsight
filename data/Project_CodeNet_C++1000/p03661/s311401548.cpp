#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
#define inf (1ll<<60)
#define N 200005
#define mod 1000000007
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,m,ans=inf,a[N],sum1[N],sum2[N];
int main(){
	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) sum1[i]=sum1[i-1]+a[i];
	per(i,n,1) sum2[i]=sum2[i+1]+a[i];
	rep(i,1,n-1) ans=min(ans,abs(sum1[i]-sum2[i+1]));
	printf("%lld",ans);
}