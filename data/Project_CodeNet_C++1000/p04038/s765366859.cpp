// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7,N=2002*2002;
int pw(int x,int y){
	int z=1;
	for (;y;y>>=1,x=1ll*x*x%M)
		if (y&1) z=1ll*z*x%M;
	return z;
}
int INV(int x){return pw(x,M-2);}
int fac[N],inv[N],f[2002][2002],i,j,n,k;
int C(int n,int m){return 1ll*fac[n]*inv[m]%M*inv[n-m]%M;}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1) return puts("1"),0;
	fac[0]=1;
	for (i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%M;
	inv[N-1]=INV(fac[N-1]);
	for (i=N-2;~i;i--) inv[i]=1ll*inv[i+1]*(i+1)%M;
	for (i=0;i<=n;i++)
		for (f[i][0]=1,j=1;j<=i;j++) f[i][j]=(f[i-1][j]+1ll*f[i][j-1]*(n-j+1)%M*C(n*k-i-(j-1)*(k-1)-1,k-2)%M)%M;
	printf("%d",f[n][n]);
}