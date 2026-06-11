#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
inline long long read()
{
	long long x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=1;ch=getchar();break;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	if(f) x=-x;return x;
}
long long poww(long long a,long long b){long long c=1;while(b){if(b&1) c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
long long n,k,dp[2010][2010],jc[5000000]={1},inv[5000000]={1};
long long C(long long x,long long y){return jc[x]*inv[y]%mod*inv[x-y]%mod;}
int main()
{
	for(long long i=1;i<=4000000;i++) jc[i]=jc[i-1]*i%mod;
	inv[4000000]=poww(jc[4000000],mod-2);
	for(long long i=3999999;i>=1;i--) inv[i]=(inv[i+1]*(i+1))%mod;
	n=read();k=read();
	if(k==1){puts("1");return 0;}
	dp[0][0]=1;
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j) dp[i][j]=(dp[i][j]+dp[i][j-1]*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod)%mod;
		}
	printf("%lld",dp[n][n]*jc[n]%mod);
}