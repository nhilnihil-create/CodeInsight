#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define N 2010
#define mod 1000000007
using namespace std;

ll f[N][N],jc[(N+2)*N],ny[(N+2)*N];

inline ll C(ll x,ll y){
	return (((1ll*jc[y]*ny[x]))%mod*ny[y-x])%mod;
}

inline ll ksm(ll a,ll p){
	ll ans=1;
	while(p){
		if(p&1)(ans*=1ll*a)%=mod;
		(a*=1ll*a)%=mod;p/=2;
	}
	return ans;
}

int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	if(m==1){printf("1");return 0;}
	jc[0]=1;
	fr(i,1,n*m)jc[i]=(1ll*jc[i-1]*i)%mod;
	ny[n*m]=ksm(jc[n*m],mod-2);
	frn(i,n*m-1,0)ny[i]=(1ll*ny[i+1]*(i+1))%mod;
	f[0][0]=1;
	fr(i,1,n)
		fr(j,0,i){
			f[i][j]=(1ll*f[i-1][j])%mod;
			if(!j)continue;
			(f[i][j]+=((1ll*f[i][j-1]*(n-j+1))%mod*C(m-2,n*m-i-(j-1)*(m-1)-1))%mod)%=mod;
		}
	printf("%lld",f[n][n]);
	return 0;
}