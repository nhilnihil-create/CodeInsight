#include <bits/stdc++.h>
using namespace std;
const int N=2005,mod=1e9+7;
int n,k;
int Fac[N*N],Inv[N*N],dp[N][N];
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1)
			ans=1LL*ans*x%mod;
	return ans;
}
int C(int n,int m){
	if (m<0||m>n)
		return 0;
	return 1LL*Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1){
		puts("1");
		return 0;
	}
	for (int i=Fac[0]=1;i<=n*k;i++)
		Fac[i]=1LL*Fac[i-1]*i%mod;
	Inv[n*k]=Pow(Fac[n*k],mod-2);
	for (int i=n*k-1;i>=0;i--)
		Inv[i]=1LL*Inv[i+1]*(i+1)%mod;
	dp[0][0]=1;
	for (int i=0;i<=n;i++)
		for (int j=i;j<=n;j++){
			dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			dp[i+1][j]=(1LL*dp[i][j]*C(k*(n-i)-(j-i)-1,k-2)+dp[i+1][j])%mod;
		}
	printf("%lld",1LL*dp[n][n]*Fac[n]%mod);
	return 0;
}