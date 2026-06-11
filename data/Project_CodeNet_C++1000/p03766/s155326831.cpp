#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int dp[1145140],sum[1145140];
signed main(){
	int n;
	cin>>n;
	if( n == 1 ){ cout<<1<<endl; return 0;}
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	sum[0] = 1;
	sum[1] = 2;
	sum[2] = 3;
	int ans = 0;
	for(int i=3;i<=n;i++){
		dp[i] = sum[i-3] + dp[i-1]; dp[i] %= inf;
		sum[i] = sum[i-1] + dp[i]; sum[i] %= inf;
	}
	ans %= inf;
	ans += (n-1) * (n-2) + 1;
	ans %= inf;
	ans += dp[n];
	ans %= inf;
	ans += sum[n-1] * (n-1);
	ans %= inf;
	for(int i=1;i<=n-2;i++){
		ans += dp[i] * ( ( (n-1) * (n-2) + i + 1)%inf);
		ans %= inf;
	}
	cout<<ans<<endl;
	return 0;
}