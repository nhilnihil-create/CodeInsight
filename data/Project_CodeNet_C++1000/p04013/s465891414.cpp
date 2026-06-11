#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a, x[51];
long long dp[51][51][2501];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 0; i <= n; i++) dp[0][i][0]++;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 0; k <= n * a; k++){
				dp[i][j][k] = dp[i][j - 1][k];
				if(k - x[j] > -1) dp[i][j][k] += dp[i - 1][j - 1][k - x[j]];
			}
	long long sum = 0;
	for(int i = 1; i <= n; i++) sum += dp[i][n][a * i];
	cout << sum << "\n";
	return 0;
}