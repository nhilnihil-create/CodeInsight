#include<cstdio>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
#define _rep(i,s,t) for(register int i=s;i>=t;--i)
using namespace std;
const int N=2011,mod=1e9+7;
int fac[N*N],ifac[N*N];
int n,m;
inline int C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int f[N][N];
inline int fp(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)
			res=1ll*res*a%mod;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	if(m==1){
		puts("1");
		return 0;
	}
	fac[0]=1;
	rep(i,1,4000000)
		fac[i]=1ll*i*fac[i-1]%mod;
	ifac[4000000]=fp(fac[4000000],mod-2);
	_rep(i,4000000,1)
		ifac[i-1]=1ll*i*ifac[i]%mod;
	f[0][0]=1;
	rep(i,1,n)
		rep(j,0,i){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+1ll*f[i][j-1]*(n-j+1)%mod*C(n-i+(n-j+1)*(m-1)-1,m-2))%mod;
		}
	printf("%d\n",f[n][n]);
	return 0;
}