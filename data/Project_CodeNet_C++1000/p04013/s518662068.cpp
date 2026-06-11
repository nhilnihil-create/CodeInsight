#include <cstdio>
#define rr register
using namespace std;
int n,A,x; long long ans,dp[51][2511];
signed main(){
	scanf("%d%d",&n,&A),dp[0][0]=1;
	for (rr int i=1;i<=n;++i){
		scanf("%d",&x);
		for (rr int j=i;j;--j)
		for (rr int m=A*n;m>=x;--m)
		    dp[j][m]+=dp[j-1][m-x];
	}
	for (rr int i=1;i<=n;++i) ans+=dp[i][i*A];
	return !printf("%lld\n",ans);
}