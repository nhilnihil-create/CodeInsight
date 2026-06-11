#include<cstdio>
using namespace std;
#define L 2003
#define N 4000006
#define LL long long
#define mod 1000000007
#define rep(i,j,k) for(i=j;i<=k;++i)
#define down(i,j,k) for(i=j;i>=k;--i)
int n,m,i,j,k,s1,s2;
int fac[N],inv[N],dp[L][L];
int quick_mi(int a,int b){
	int sum=1;
	for(;b;b>>=1,a=(a*1LL*a)%mod)
	if(b&1) sum=(sum*1LL*a)%mod;
	return sum;
}
int C(int n,int m){
	if(m>n) return 0;
	return (((fac[n]*1LL*inv[m])%mod)*1LL*inv[n-m])%mod;
}
int main(){
// 	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	if(m==1) {printf("1\n"); return 0;}
	fac[0]=1; k=n*m;
	rep(i,1,k) fac[i]=(fac[i-1]*1LL*i)%mod;
	inv[k]=quick_mi(fac[k],mod-2);
	down(i,k-1,0) inv[i]=(inv[i+1]*1LL*(i+1))%mod;
	dp[0][0]=1;
	rep(i,0,n)
	 rep(j,i,n)
	 if(i||j){
	 	if(i) dp[i][j]=dp[i-1][j];
		dp[i][j]+=(dp[i][j-1]*1LL*C(m-2+i+((j-1)*(m-1)),m-2))%mod;
	 	dp[i][j]%=mod;
	 }
	int ans=(dp[n][n]*1LL*fac[n])%mod;
	printf("%d\n",ans);
	return 0;
}