#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

int n, p;
int a, c[2];

ll dp[55][55];

int main() {
	rep(i, 0, 50) {
		dp[i][0] = dp[i][i] = 1;
		rep(j, 1, i - 1)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}
	
	scanf ("%d%d", &n, &p);
	rep(i, 1, n) {
		scanf ("%d", &a);
		c[a % 2]++;
	}
	
	ll s = 0;
	for (int i = 0; i <= c[1]; i += 2)
		s += dp[c[1]][i];
	s *= (1LL << c[0]);
	
	if (p) 
		s = (1LL << n) - s;
	printf ("%lld\n", s);
	
	
	return 0;
}	
