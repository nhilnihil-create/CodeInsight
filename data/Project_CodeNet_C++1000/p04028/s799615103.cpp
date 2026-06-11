#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll my_pow(ll x, ll n){
	ll ret = 1;
	while(n>0) {
		if(n&1) {
			ret *= x;
			ret %= mod;
		}
		x*=x;
		x%=mod;
		n>>=1;
	}
	return ret;
}


char s[5002];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int sl = strlen(s);

	vector<ll> dp(n+2, 0);

	dp[0] = 1;
	for(int i=1;i<=n;i++) {
		vector<ll> nxt(i+2, 0);

		nxt[0] = dp[0] + dp[1];
		for(int j=1;j<=i;j++) {
			nxt[j] = dp[j-1]*2 + dp[j+1];
			nxt[j] %= mod;
		}
		dp = nxt;
	}

	ll all = my_pow(2ll, (ll)sl);
	ll invall = my_pow(all, mod-2);

	ll ans = dp[sl]*invall%mod;
	printf("%lld", ans);
	return 0;
}