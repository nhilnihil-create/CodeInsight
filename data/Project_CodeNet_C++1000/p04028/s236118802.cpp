#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define ll long long
using namespace std;
const int N=5e3+10;
const ll mod=1e9+7;
int n,len;
ll dp[N][N];
char ss[N];
inline int mx(int a,int b){return a>b ? a : b;}
inline ll powe(ll aa,ll tt){
	ll ans=1;
	for(ll i=tt;i;i>>=1, aa=aa*aa%mod) if(i&1) (ans*=aa)%=mod;
	return ans;
}
int main()
{
//	freopen("Unhappy Hacking.in","r",stdin);
	scanf("%d%s",&n,ss);
	len=strlen(ss);
	dp[0][0]=1;
	for(RG int i=0;i<=n;i++)
	 for(RG int j=0;j<=i;j++)
	 {
		(dp[i+1][j+1]+=2*dp[i][j])%=mod;
		(dp[i+1][mx(0,j-1)]+=dp[i][j])%=mod;
	 }
	printf("%lld",dp[n][len]*powe(powe(2,len),mod-2)%mod);
	return 0;
}