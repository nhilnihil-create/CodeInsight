#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1000000007;
int n;
ll dp[2000010], s[2000010];

int main(){
	scanf("%d", &n);
	for(int i = 2 * n + 5; i >= 1; i--){
		if(i > n) dp[i] = 1;
		else if(i == n) dp[i] = n;
		else dp[i] = (1LL * (n - 1) * (n - 1) + dp[i + 1] + s[i + 3] - s[i + n + 2] + M) % M;
		s[i] = (s[i + 1] + dp[i]) % M;
	}
	printf("%lld\n", dp[1]);
}