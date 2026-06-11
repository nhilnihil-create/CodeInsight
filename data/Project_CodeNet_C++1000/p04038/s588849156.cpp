#include <cstdio>
#define N 2010
#define mod 1000000007
int n,k,f[N*N],inv[N*N],a[N][N];
inline int C(int x,int y){
	return 1ll*f[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&k);if(k==1){puts("1");return 0;}
	f[0]=f[1]=1;for(int i=2;i<=n*k;++i) f[i]=1ll*f[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n*k;++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n*k;++i) inv[i]=1ll*inv[i-1]*inv[i]%mod;
	a[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			a[i][j]=a[i-1][j];
			if(j) a[i][j]=(a[i][j]+1ll*(n-j+1)*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod*a[i][j-1]%mod)%mod;
		}
	}
	printf("%d\n",a[n][n]);
	return 0;
}