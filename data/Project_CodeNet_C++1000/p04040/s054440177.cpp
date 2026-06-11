#include <cstdio>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1;c=getchar();}
	while ('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
const int mod(1e9+7),maxn(2e5+5);
int h,w,a,b;
ll fac[maxn],inv[maxn];
ll ans;
ll qpow(ll a,ll b){
	ll sum=1;
	while (b){
		if (b&1) sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
void pre(){
	fac[0]=inv[0]=1;
	for (int i(1);i<=maxn;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[200000]=qpow(fac[200000],mod-2);
	for (int i(199999);i;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
void init(){
	h=read(),w=read(),a=read(),b=read();
}
inline ll cal(int x1,int y1,int x2,int y2){
	int n=x2-x1+y2-y1,m=x2-x1;
	if (n==m||m==0) return 1;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	pre();
	init();
	for (int i(1);i<=h-a;++i)
		ans=(ans+cal(1,1,i,b)*cal(i,b+1,h,w)%mod)%mod;
	printf("%lld",ans);
	return 0;
}
