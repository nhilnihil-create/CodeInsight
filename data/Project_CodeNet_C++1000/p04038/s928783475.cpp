#include<cstdio>
typedef long long LL;
const int MOD=1e9+7;
const int N=2003;

int n,k,all;
int f[N][N];
int fac[N*N];
int ifac[N*N];

inline int Pow(int x,int p) {
	int y=1;
	for(;p;p>>=1,x=1ll*x*x%MOD)
		if(p&1) y=1ll*y*x%MOD;
	return y;
}
inline LL C(int x,int y) {
	return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;
}
int main() {
	scanf("%d %d",&n,&k);
	if(k==1) {
		puts("1");
		return 0;
	}
	all=n*k;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=all;i++)
		fac[i]=1ll*i*fac[i-1]%MOD;
	ifac[all]=Pow(fac[all],MOD-2);
	for(int i=all-1;i>=1;i--)
		ifac[i]=(i+1ll)*ifac[i+1]%MOD;
	f[0][0]=1;
	for(int i=1;i<=n;i++) {
		f[i][0]=f[i-1][0];
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+1ll*f[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2))%MOD;
	}
	printf("%lld\n",1ll*f[n][n]*fac[n]%MOD);
	return 0;
}