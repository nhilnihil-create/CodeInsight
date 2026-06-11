#include <iostream>
typedef long long ll;
using namespace std;

ll mod=1000000007;
ll dp[1000010], sum[1000010];

int main() {
	ll N;
	cin >> N;
	ll ans=0, m=((N-1)*(N-1))%mod;
	dp[0]=sum[0]=1;
	for(ll i=0; i<N-1; ++i){
		(ans += (dp[i]*m)%mod) %= mod;
		if(i<N-2){
			(ans += dp[i]*(i+2)) %= mod;
		}else{
			(ans += dp[i]*(i+1)) %= mod;
		}
		if(i>0){
			dp[i+1]=(sum[i]-dp[i-1]+mod)%mod;
		}else{
			dp[i+1]=1;
		}
		sum[i+1]=(sum[i]+dp[i+1])%mod;
	}
	(ans += dp[N-1]*N) %= mod;
	cout << ans << endl;
	return 0;
}