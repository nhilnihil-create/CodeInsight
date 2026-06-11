#include<bits/stdc++.h>
#define db double
#define ll long long
#define ev edge[i].v
#define mod 1000000007
#define pir pair<int,int>
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=head[x];i;i=edge[i].next)
using namespace std;

const int N=2005;

ll f[N][N];
ll fac[N*N],inv[N*N];

ll ksm(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}

ll C(ll n,ll m){
    if(n<0||n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main(){
	ll n,k;
    scanf("%lld%lld",&n,&k);
    if(k==1){puts("1");return 0;}
    fac[0]=inv[0]=f[0][0]=1;
    Rep(i,1,n*k) fac[i]=fac[i-1]*i%mod;
    inv[n*k]=ksm(fac[n*k],mod-2);
    RepD(i,n*k-1,1) inv[i]=inv[i+1]*(i+1)%mod;
    Rep(i,1,n)
    	Rep(j,0,i){
    		if(i) f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if(j) f[i][j]=(f[i][j]+f[i][j-1]*C(n*k-i-(k-1)*(j-1)-1,k-2)%mod)%mod;
		}
    printf("%lld\n",f[n][n]*fac[n]%mod);
    return 0;
}