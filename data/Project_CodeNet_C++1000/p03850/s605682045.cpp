#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,a[N],dp[N][3],opt[N];
int get(){
	char s[2];
	scanf("%s",s);
	if (s[0]=='-')return 1;
	return 0;
}
signed main(){
	scanf("%lld",&n);
	scanf("%lld",&a[1]);
	for (int i=2;i<=n;i++)opt[i]=get(),scanf("%lld",&a[i]);
	dp[1][0]=a[1];
	dp[1][1]=dp[1][2]=-1e18;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=2;j++)dp[i][j]=-1e18;
		for (int j=0;j<=2;j++){
			int t=(opt[i]==1),now=((j^t)&1)?-a[i]:a[i];
			if (t&&j<2)dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+now);
			for (int l=0;l<=j;l++)dp[i][l]=max(dp[i][l],dp[i-1][j]+now);
		}
	}
	printf("%lld\n",max(max(dp[n][0],dp[n][1]),dp[n][2]));
}
