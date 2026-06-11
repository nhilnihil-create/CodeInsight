#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

const int N=5005;
const int mod=1000000007;

int n,ans,m;
int dp[N][N];
char s[N];

int quickpow(int x,int y){
	int s=1;
	for (;y;y>>=1,x=1ll*x*x%mod)
		if (y&1) s=1ll*s*x%mod;
	return s;
}

void add(int &x,int y){
	x+=y;
	(x>=mod)?x-=mod:0;
}

int main(){
	int i,j;
	scanf("%d",&n);
	scanf("%s",s+1); m=strlen(s+1);
	dp[0][0]=1;
	for (i=1;i<=n;i++){
		for (j=0;j<=5000;j++){
			if (j) add(dp[i][j],2*dp[i-1][j-1]%mod);
			else add(dp[i][j],dp[i-1][j]);
			add(dp[i][j],dp[i-1][j+1]);
		}
	}
	ans=dp[n][m];
	for (i=1;i<=m;i++) ans=1ll*ans*quickpow(2,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}