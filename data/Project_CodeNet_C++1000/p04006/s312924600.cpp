#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2005;
ll n,x;
ll a[maxn],dp[maxn][maxn];
int main(){
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dp[i][0] = a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++){
			ll t = i-j;
			if(t<=0)
				t = t+n;
			dp[i][j] = min(dp[i][j-1],a[t]);
		}
	ll ans = 1e18;
	for(int i=0;i<n;i++){
		ll sum = 0;
		for(int j=1;j<=n;j++)
			sum += dp[j][i];
		ans = min(ans,x*i+sum);
	}
	printf("%lld\n",ans);
	return 0;
}