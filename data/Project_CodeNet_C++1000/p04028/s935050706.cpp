#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

const ll inv2 = (MOD + 1) / 2;

ll dp[5001][5001];

int main() {
	
	int n;
	string s;
	cin >> n >> s;
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0)dp[i][j] += dp[i - 1][j];//Bを何もない状態で押す
			//任意の指定の長さの列を数え上げることにしてるので、
			if (j >= 1)dp[i][j] += dp[i - 1][j - 1] * 2;//(1, 0)のどれを出してもいいため、2倍
			if (j <= n - 1)dp[i][j] += dp[i - 1][j + 1];//Bで一文字消してるため、1通りの操作しかない
			dp[i][j] %= MOD;
		}
	}
	ll ans = dp[n][s.size()];
	for (int i = 0; i < s.size(); i++) {
		ans *= inv2;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}