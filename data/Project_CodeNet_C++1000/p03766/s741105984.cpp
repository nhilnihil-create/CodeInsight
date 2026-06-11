#include<bits/stdc++.h>
#define MOD 1000000007
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll dp[1000000];
int main() {
	ll n; scanf("%lld", &n);
	dp[0] = n;
	ll sum = n - 1;
	for (int i = 1; i < n; i++) {
		dp[i] = ((n - 1)*(n - 1) + dp[i - 1] + sum) % MOD;
		sum = (sum + (i - 2 >= 0 ? dp[i - 2] : 1) + MOD - (i - n > 0 ? dp[i - n - 1] : 1)) % MOD;
	}
	printf("%lld\n", dp[n - 1]);
}