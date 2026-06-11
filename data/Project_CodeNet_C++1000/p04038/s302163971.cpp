#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=2000,p=1e9+7;
ll f[N+10][N+10],fac[N*N+10],ifac[N*N+10];

ll fpm(ll a,ll b)
{
	ll ret=1;
	for(;b;b>>=1) ret=(b&1)?ret*a%p:ret,a=a*a%p;
	return ret;
}

inline ll C(ll a,ll b){return fac[a]*ifac[b]%p*ifac[a-b]%p;}

inline void add(ll &a,ll b){a=a+b>=p?a+b-p:a+b;}

int main()
{
	fac[0]=1;
	for(ll i=1;i<=N*N;++i) fac[i]=fac[i-1]*i%p;
	ifac[N*N]=fpm(fac[N*N],p-2);
	for(ll i=N*N-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%p; 
	
	int n,k;scanf("%d %d",&n,&k);
	if(k==1){printf("1\n");return 0;};
	f[0][0]=1;
	for(int j=1;j<=n;++j) f[0][j]=f[0][j-1]*C(j*(k-1)-1,k-2)%p;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			f[i][j]=f[i-1][j];
			if(j>i) add(f[i][j],f[i][j-1]*C(j*(k-1)+i-1,k-2)%p);
		};
	printf("%lld\n",f[n][n]*fac[n]%p);
	return 0;
}