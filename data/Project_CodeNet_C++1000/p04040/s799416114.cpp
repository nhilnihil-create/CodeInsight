#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=202020;
int const MOD=1000000007;
ll n,m,a,b,ans,d[N],f[N];
ll kasumi (ll a,ll b,ll n) 
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=res*a%n;
        a=a*a%n;
        b>>=1	;
    }
    return res;
}
ll exgcd(int a,int b,int p)
{
    if(a==b||b==0)
    {
        return 1;
    }
    return ((d[a]*f[b])%p*f[a-b]%p);
}
ll input(int x1,int y1,int x2,int y2)
{
    return exgcd(x2-x1+y2-y1,x2-x1,MOD);
}
void prepare ()
{
	d[1]=1;
	for(int i=2;i<=200000;i++)
		d[i]=(d[i-1]*i)%MOD;
	f[200000]=kasumi(d[200000],MOD-2,MOD);
	for(int i=199999;i>0;i--)
		f[i]=(f[i+1]*(i+1))%MOD;
}
int main ()
{
	prepare();
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	for(int i=1;i<=n-a;i++)
	{
		ans+=(input(1,1,i,b)*input(i,b+1,n,m))%MOD;
		ans%=MOD;
	}
	printf("%d",ans);
	return 0;
}