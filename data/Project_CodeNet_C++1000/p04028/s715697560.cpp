#include<bits/stdc++.h>
#define Mod 1000000007
#define N 5005
using namespace std;
int dp[N][N],n;char s[N];
inline int ksm(int x,int y){
	int ans1=1;while (y){
		if (y&1) ans1=1ll*ans1*x%Mod;
		y>>=1;x=1ll*x*x%Mod;
	}return ans1;
} 
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	int m=strlen(s+1);dp[0][0]=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++){
			dp[i+1][j+1]=1ll*(dp[i+1][j+1]+1ll*dp[i][j]*2%Mod)%Mod;
			dp[i+1][max(0,j-1)]=1ll*(dp[i+1][max(0,j-1)]+dp[i][j])%Mod;
		}
	}
	//cerr<<dp[n][m]<<endl;
	printf("%lld\n",1ll*dp[n][m]*ksm(ksm(2,m),Mod-2)%Mod);
	return 0;
}