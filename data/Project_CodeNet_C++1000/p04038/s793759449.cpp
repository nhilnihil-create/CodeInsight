#include<cstdio>
const int N = 2333,mo=1e9+7;
int n,k,f[N][N],g[N*N],fac[N];
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&k);if(k==1){puts("1");return 0;}
	for(int i=k-2,j=1;i<=n*k;i++)g[i]=j,j=1LL*j*(i+1)%mo*power(i-k+3,mo-2)%mo;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1LL*fac[i-1]*i%mo;
	for(int i=0;i<=n;i++)for(int j=i;j<=n;j++)
		if(i==0){
			if(j==0)f[i][j]=1;else f[i][j]=1LL*f[i][j-1]*g[i+j*k-j-1]%mo;
		}else f[i][j]=(f[i-1][j]+1LL*f[i][j-1]*g[i+j*k-j-1])%mo;
	printf("%lld",1LL*f[n][n]*fac[n]%mo);
	return 0;
}