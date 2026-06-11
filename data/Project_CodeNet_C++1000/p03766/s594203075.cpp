#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10,p=1e9+7;
int inc(int x,int y){x+=y;return x>=p?x-p:x;}
int mul(int x,int y){return (ll)x*y%p;}
int n,dp[N],sum[N];
int main()
{
	scanf("%d",&n);
	if (n==1) return puts("1"),0;
	dp[0]=sum[0]=1;
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if (i>=3) dp[i]=inc(dp[i],sum[i-3]);
		sum[i]=inc(sum[i-1],dp[i]);
	}
	int ans=0;
	//最后循环的不是1且完全循环
	ans=inc(ans,mul(sum[n-1],n-1));
	//最后循环的不是1且不是完全循环
	ans=inc(ans,mul(sum[n-2],mul(n-1,n-2)));
	//最后循环的是1且完全循环
	ans=inc(ans,dp[n-1]);
	//最后循环的是1且溢出了
	for (int i=0;i<n-2;i++) ans=inc(ans,mul(dp[i],i+2));
	ans=inc(ans,mul(dp[n-2],n-1));
	printf("%d\n",ans);
	return 0;
}