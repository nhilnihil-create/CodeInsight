#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define SF scanf
#define PF printf
#define MAXN 5010
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m;
char s[MAXN];
ll dp[MAXN][MAXN];
int main(){
	SF("%d",&m);
	SF("%s",s);
	n=strlen(s);
	if(n>m){
		PF("0");
		return 0;
	}
	dp[0][0]=1;
	for(int k=1;k<=m;k++)
		for(int i=0;i<=m;i++){
			if(i!=m)
				dp[i][k]+=2ll*dp[i+1][k-1];
			if(i!=0)
				dp[i][k]+=dp[i-1][k-1];
			if(i==0)
				dp[i][k]+=dp[i][k-1];
			dp[i][k]%=MOD;
		//	PF("%d %d %lld\n",i,k,dp[i][k]);
		}
	PF("%lld",dp[n][m]);
}