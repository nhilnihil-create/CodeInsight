#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
#define mod 1000000007
#define ll long long
using namespace std;
int dp[maxn][maxn],n,m,fac[maxn*maxn],inv[maxn*maxn];//dp[i][j]表示放了i个白球,其中j种颜色的球已经放完了
int c(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	cin>>n>>m;dp[0][0]=1;
	if(m==1){cout<<1<<endl;return 0;}
	fac[0]=1;inv[0]=inv[1]=1;
	for(int i=1;i<=n*m;i++)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=2;i<=n*m;i++)inv[i]=(mod-(ll)(mod/i)*inv[mod%i]%mod)%mod;
	for(int i=2;i<=n*m;i++)inv[i]=(ll)inv[i]*inv[i-1]%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j)(dp[i][j]+=(ll)dp[i][j-1]*c(n*m-i-(j-1)*(m-1)-1,m-2)%mod)%=mod;
		}
	}
	cout<<((ll)dp[n][n]*fac[n]%mod+mod)%mod;
	return 0;
}
