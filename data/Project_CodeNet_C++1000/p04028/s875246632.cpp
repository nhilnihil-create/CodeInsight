#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const int MOD = 1e9 + 7;

int dp[5001][5001];
int n;
string s;

lli powe(int a, int b) {
	if(b == 0) return 1;
	else if(b == 1) return a;
	else {
		lli base = powe(a, b/2);
		lli ans = base*base;
		ans %= MOD;
		if(b&1) {
			ans *= a;
			ans %= MOD;
		}
		return ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 5001; i++) for(int j = 0; j < 5001; j++) dp[i][j] = 0;
	dp[0][0] = 1;

	cin >> n;
	cin >> s;

	//i - number of keys pressed
	for(int i = 1; i <= n; i++) {
		// length of existing string
		for(int j = 0; j <= n; j++) {
			//append b
			if(j == 0) {
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= MOD;
			} else {
				dp[i][j-1] += dp[i-1][j];
				dp[i][j-1] %= MOD;
			}

			//append a digit
			if(j != n) {
				dp[i][j+1] += 2*dp[i-1][j];
				dp[i][j+1] %= MOD;
			}
		}
	}

	cout << ((dp[n][s.length()]*powe(2, MOD-1-s.length())) % MOD) << endl;

	return 0;
}