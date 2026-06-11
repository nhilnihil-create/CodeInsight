#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Max(int a,int b){return a>b?a:b;}
const long long Mod=1e9+7;
long long inv[5005],dp[5005][5005];
long long quipow(long long x,long long n)  
{
    long long res=1;
    while(n>0)
    {
        if(n&1) res=res*x%Mod;
        x=x*x%Mod;
        n>>=1;
    }
    return res;
}
int main()
{
	int n,len;char s[5005];
	scanf("%d%s",&n,s);len=strlen(s);
    inv[0]=1;inv[1]=quipow(2,Mod-2);
    for(int i=2;i<5002;++i) inv[i]=1ll*inv[i-1]*inv[1]%Mod;
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j])%Mod;
			dp[i+1][Max(j-1,0)]=(dp[i+1][Max(j-1,0)]+dp[i][j])%Mod;
		}
	}
	printf("%I64d",1ll*dp[n][len]*inv[len]%Mod);
}