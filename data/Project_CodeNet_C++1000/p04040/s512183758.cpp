#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=100001;
typedef long long ll;
ll H,W,A,B,fac[2000010];
void create()
{
	fac[1]=1;
	for(int i=2;i<=2000001;i++)
		fac[i]=fac[i-1]*i,fac[i]%=mod;
	return;
}
ll expand(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll r=expand(b,a%b,x,y);
    ll t=y;
    y=x-(a/b)*y;
    x=t;
    return r;
}
ll ways(ll x1,ll y1,ll x2,ll y2)
{
	if(y2==y1 || x2==x1)
		return 1;
	ll x=fac[abs(y2-y1)+abs(x2-x1)];
	ll y=fac[abs(y2-y1)];
	ll z=fac[abs(x2-x1)];
	ll t=(y*z%mod+mod)%mod;
	ll x0=0,y0=0;
	expand(t,mod,x0,y0);
	ll answer=x*x0%mod;
	answer=(answer%mod+mod)%mod;
	return answer;
}
int main()
{
	scanf("%lld %lld %lld %lld",&H,&W,&A,&B);
	create();
	ll ans=0;
	for(int i=B+1;i<=W;i++)
		ans+=ways(A,i,1,W)*ways(H,1,A+1,i),ans%=mod;
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}