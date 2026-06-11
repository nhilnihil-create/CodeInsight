#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define ll long long
using namespace std;
const int N=2e5+10;
const ll mod=1e9+7;
int n,m,a,b,maxx;
ll fac1[N]={1},inv[N]={0,1},fac2[N]={1},ans,x,y;
inline ll C(int nn,int mm){return fac1[nn]*fac2[mm]%mod*fac2[nn-mm]%mod;}
int main()
{
//	freopen("Iroha and a Grid .in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&a,&b); maxx=n+m;
	for(RG int i=1;i<=maxx;i++) fac1[i]=fac1[i-1]*i%mod;
	for(RG int i=2;i<=maxx;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(RG int i=1;i<=maxx;i++) fac2[i]=fac2[i-1]*inv[i]%mod;
	for(RG int i=1;i<=n-a;i++)
	{
		x=C(b+i-2,b-1), y=C(n+m-i-b-1,m-b-1);
		(ans+=(x*y%mod))%=mod;
	}
	printf("%lld",ans);
	return 0;
}