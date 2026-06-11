#include <bits/stdc++.h>
#define N 2010
#define mod 1000000007
#define ll long long
using namespace std;

ll f[N][N];
ll jc[N*N],inv[N*N];

ll C(int a,int b){
	if(a==b || b==0) return 1;
	if(a<b) return 0;
	return 1ll*jc[a]*1ll*inv[a-b]%mod*inv[b]%mod;
}
int main(){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	if(k==1){ puts("1");return 0; }
	jc[1]=inv[1]=1;
	for(i=0;i<=n;++i) f[i][0]=1;
	for(i=2;i<=n*k;++i) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for(i=2;i<=n*k;++i){
		jc[i]=1ll*jc[i-1]*i%mod;
		inv[i]=1ll*inv[i-1]*inv[i]%mod;
	}
	inv[1]=jc[1]=1;
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j)
			f[i][j]=(f[i-1][j]+1ll*f[i][j-1]*(n-j+1)%mod*C(n*k-i-(j-1)*(k-1)-1,k-2)%mod)%mod;		
	printf("%lld",f[n][n]);
}