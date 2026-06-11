#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define N 2010
#define lint long long
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
int dp[N][N],f[N*N],fi[N*N];
inline int fast_pow(int x,int k,int ans=1)
{	for(;k;k>>=1,x=(lint)x*x%mod) (k&1)?ans=(lint)ans*x%mod:0;return ans; }
inline int prelude(int n)
{
	for(int i=f[0]=1;i<=n;i++) f[i]=(lint)f[i-1]*i%mod;
	fi[n]=fast_pow(f[n],mod-2);
	for(int i=n-1;i>=0;i--) fi[i]=fi[i+1]*(i+1ll)%mod;
	return 0;
}
inline int C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return (lint)f[n]*fi[m]%mod*fi[n-m]%mod;
}
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	dp[0][0]=1,prelude(n*k);
	if(k==1) return !printf("1\n");
	rep(i,0,n-1) rep(j,i,n) if(dp[i][j])
		(i<j?(dp[i+1][j]+=dp[i][j])%=mod:0),
		(dp[i][j+1]+=(lint)dp[i][j]*C((j+1)*(k-1)+i-1,k-2)%mod)%=mod;
//	rep(i,0,n) rep(j,i,n) debug(i)sp,debug(j)sp,debug(dp[i][j])ln;
	return !printf("%lld\n",(lint)dp[n][n]*f[n]%mod);
}