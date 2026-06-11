#include<bits/stdc++.h>
using namespace std;
#define int long long
const int L=4000005,N=2005,M=1e9+7;
int fac[L],inv[L],dp[N][N],n,m;
int ksm(int x,int y){
	if (!y)return 1;
	int z=ksm(x,y/2);
	z*=z;z%=M;
	if (y&1)z*=x;
	return z%M;
}
int C(int x,int y){
	return fac[x]*inv[y]%M*inv[x-y]%M;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	if (m==1){
		puts("1");
		return 0;
	}
	fac[0]=inv[0]=1;
	for (int i=1;i<L;i++)fac[i]=fac[i-1]*i%M;
	inv[L-1]=ksm(fac[L-1],M-2);
	for (int i=L-2;i>=0;i--)inv[i]=(i+1)*inv[i+1]%M;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++)
			dp[i][j]=((j>0?dp[i][j-1]:0)+dp[i-1][j]*C((i-1)*m-(i-j-1)+m-2,m-2))%M;
	printf("%lld\n",dp[n][n]*fac[n]%M);		
}