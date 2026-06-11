#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=2e3+5;
int n,k;
ll fac[N*N],inv[N*N],dp[N][N];
ll c(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main(){
	scanf("%d%d",&n,&k);
	if(k==1) return puts("1"),0;
	fac[0]=1;
	inc(i,1,n*k) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	inc(i,2,n*k) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	inc(i,2,n*k) inv[i]=inv[i]*inv[i-1]%mod;
	inc(i,0,n) dp[0][i]=1;
	inc(i,1,n){
		inc(j,i,n){
			dp[i][j]=(dp[i][j-1]+dp[i-1][j]*(n-i+1)%mod*c(n*k-(k-1)*(i-1)-j-1,k-2))%mod;
		} 
	}
	printf("%lld",dp[n][n]);
}