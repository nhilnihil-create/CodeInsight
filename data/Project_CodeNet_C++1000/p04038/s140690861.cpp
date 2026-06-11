#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const int N=2010,V=N*N,pn=4e6+5;
int n,K;
int dp[N][N],zp[V],fp[V];
int C(int a,int b){return mul(zp[a],mul(fp[b],fp[a-b]));}
int main()
{
	int i,j,ans;
	zp[0]=fp[0]=1;
	for(i=1;i<=pn;i++) zp[i]=mul(zp[i-1],i);
	fp[pn]=inv(zp[pn]);
	for(i=pn-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	scanf("%d%d",&n,&K);
	if(K==1)
	{
		puts("1");return 0;
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			dp[i][j]=mul(dp[i-1][j],C((K-1)*i+j-1,K-2));
			if(j>0) upd(dp[i][j],dp[i][j-1]);
		}
	}
	ans=mul(dp[n][n],zp[n]);
	printf("%d",ans);
	return 0;
}