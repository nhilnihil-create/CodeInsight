#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	int M = s.size();
	vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= i; j++){
			dp[i + 1][max(j - 1, 0)] += dp[i][j];
			dp[i + 1][max(j - 1, 0)] %= MOD;
			dp[i + 1][j + 1] += dp[i][j] * 2;
			dp[i + 1][j + 1] %= MOD;
		}
	}
	cout << dp[N][M] * modinv(modpow(2, M)) % MOD << endl;
}