#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
const ll MOD=1e9+7;
int h,w,a,b;
const int maxf=2e5+10;
ll f[maxf],frev[maxf];
ll pow(ll b,ll p,ll k=MOD)
{
	ll t=1,y=b;
	while(p!=0)
	{
		if((p&1)==1) t=t*y%k;
		y=y*y%k;p=p>>1;
	}
	return t;
}
void preload()
{
    f[0]=1;frev[0]=pow(1,MOD-2);
    for(int i=1;i<=2e5;i++)
    {
        f[i]=(f[i-1]*i)%MOD;
        frev[i]=pow(f[i],MOD-2);
    }
}
ll C(ll n,ll m)
{
    return f[n]%MOD*frev[m]%MOD*frev[n-m]%MOD;
}
ll counter(int x,int y,int xx,int yy)
{
    ll tot=(yy-y)+(xx-x);
    ll d=xx-x;
    return C(tot,d)%MOD;
}
int main()
{
    preload();
    scanf("%d%d%d%d",&h,&w,&a,&b);
    ll tot=counter(1,1,h,w);
    for(ll i=1;i<=b;i++)
    {
        ll t=counter(1,1,h-a,i)*counter(h-a+1,i,h,w)%MOD;
        tot=((tot-t)%MOD+MOD)%MOD;
    }
    printf("%lld\n",tot);
}
