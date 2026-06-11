#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 13000005
using namespace std;

typedef long long ll;

ll n, dp[N];

ll fen[N];

void up(int x, int y){
	for(; x < N; x += x&-x)
		fen[x] = (fen[x] + y)%mod;
}

int qu(int x){
	ll top = 0;
	for(; x > 0; x -= x&-x)
		top = (top + fen[x])%mod;
	return top;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld",&n);
	dp[n] = n;
	up(n, n);
	for(int i = n + 1; i <= n+n; i++){
		dp[i] = 1;
		up(i, 1);
	}
	for(int i = n - 1; i >= 1; i--){
		dp[i] = (dp[i + 1])%mod;
		dp[i] = (dp[i] + qu(i + n + 1) - qu(i + 2) + mod)%mod;
		dp[i] = (dp[i] + (i + n + 1 - i - 2)*(n - 1)%mod)%mod;
		up(i, dp[i]);
		// for(int j = 2; j <= n; j++)
		// 	dp[i] = (dp[i] + dp[i + j + 1] + n - 1)%mod;
	}
	printf("%lld\n", dp[1]);
	return 0;
}