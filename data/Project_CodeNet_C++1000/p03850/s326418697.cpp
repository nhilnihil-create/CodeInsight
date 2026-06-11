#include <cstdio>
#include <iostream>
#include <cstring>
#define oo 1e17
#define N 100005
#define ll long long
#define F(i,j,k) for(int i=(j);i<=(k);++i)
#define D(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
char op[N];
int n,mx;
ll a[N],ans,dp[N][3];
int main(){
	//freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%lld ",&a[0]);F(i,1,n-1)scanf("%c %lld ",&op[i],&a[i]);
	ans=-oo;
	memset(dp,-0x7f,sizeof(dp));
	dp[0][0]=0;
	//F(i,0,n-1)printf("%d %lld %lld %lld\n",i,dp[i][0],dp[i][1],dp[i][2]);
	F(i,1,n-1){
		if(op[i]=='+'){
			dp[i][2]=dp[i-1][2]+a[i];
			dp[i][1]=max(dp[i-1][1]-a[i],dp[i][2]);
			dp[i][0]=max(dp[i-1][0]+a[i],dp[i][1]);
		}
		else{
			dp[i][2]=max(dp[i-1][2]-a[i],dp[i-1][1]+a[i]);
			//printf("%d %lld %lld %lld\n",i,dp[i-1][2]-a[i],dp[i-1][1]+a[i],dp[i][2]);
			dp[i][1]=max(max(dp[i-1][1]+a[i],dp[i-1][0]-a[i]),dp[i][2]);
			dp[i][0]=max(dp[i-1][0]-a[i],dp[i][1]);
		}
		//printf("%d %lld %lld %lld\n",i,dp[i][0],dp[i][1],dp[i][2]);
	}
	ans=max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
	printf("%lld\n",ans+a[0]);
	return 0;
} 