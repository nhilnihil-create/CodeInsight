#include<iostream>
#include<cstdio> 
using namespace std;
typedef long long ll;
const int N=2005;

int n,x,mymin,mymini;
ll ans,dp[N][N],a[N];

int main(){
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) dp[i][0]=a[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<n;j++){
			int k=i-j;
			if (k<=0) k+=n;
			dp[i][j]=min(dp[i][j-1],a[k]);
		}
	ll ans=1e18;
	for (int i=0;i<n;i++){
		ll sum=0;
		for (int j=1;j<=n;j++) sum+=dp[j][i];
		ans=min(ans,sum+i*x);
	}
	printf("%lld",ans);
	return 0;
}