#include <bits/stdc++.h>
using namespace std;
const int N=5005,Mod=1e9+7,inv=(Mod+1)>>1;
int dp[N][N];char a[N];
int mo(int x){return x>=Mod?x-Mod:x;}
int main (){
	int n;scanf ("%d",&n);
	scanf ("%s",a+1);
	int l=strlen(a+1);
	dp[0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++){
			dp[i+1][max(j-1,0)]=mo(dp[i][j]+dp[i+1][max(j-1,0)]);
			dp[i+1][j+1]=mo(mo(dp[i][j]*2)+dp[i+1][j+1]);
		}
	for (int i=1;i<=l;i++) dp[n][l]=1ll*dp[n][l]*inv%Mod;
	printf ("%d",dp[n][l]);
	return 0;
}
