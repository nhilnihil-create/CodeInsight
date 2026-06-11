#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N],sig[N];ll dp[N][10];
int main()
{
	scanf("%d%d",&n,&a[1]);
	for (int i=2;i<=n;i++){
		char ch;
		do ch=getchar();while (ch!='-'&&ch!='+');
		if (ch=='-') sig[i]=1;
		scanf("%d",&a[i]);
	}
	for (int i=0;i<=n;i++)
	for (int j=0;j<=5;j++)
		dp[i][j]=-1e16;
	dp[0][0]=0;
	for (int i=0;i<n;i++)
	for (int j=0;j<=5;j++){
		ll v=dp[i][j];int k=j+sig[i+1];
		dp[i+1][k]=max(dp[i+1][k],k&1?v-a[i+1]:v+a[i+1]);
		if (j) dp[i+1][k-1]=max(dp[i+1][k-1],k&1?v+a[i+1]:v-a[i+1]);
	}
	ll ans=-1e16;
	for (int i=0;i<=5;i++) ans=max(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}