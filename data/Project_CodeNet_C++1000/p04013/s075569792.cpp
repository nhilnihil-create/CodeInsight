#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

int main() {FIN

	ll n, a, i, j, k, c = 0;
	cin >> n >> a;
	vll as(n);
	vvvll dp(n + 1, vvll(n * a + 1, vll(n + 1)));
	
	for (i = 0; i < n; i++)
		cin >> as[i];
	
	dp[0][0][0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n*a; j++) {
			if (j >= as[i-1]) {
				for (k = 0; k <= i; k++) {
					dp[i][j][k] = dp[i-1][j][k];
					if (k > 0)
						dp[i][j][k] += dp[i-1][j - as[i-1]][k - 1];
				}
			} else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	j = 1;
	for (i = a; i <= n * a; i += a)
		c += dp[n][i][j++];	
	
	cout << c << "\n";
	
	return 0;
}
