#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long mod_pow(long long x, long long n){
    long long res = 1;
    while(n > 0){
        if(n & 1) res = res * x % MOD;

        x = (x * x) % MOD;
        n = n >> 1;
    }

    return res;
}

int main(){
	long long n; cin >> n;
	string s; cin >> s;
	long long m = (long long)s.size();
	vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 0));
	dp[0][0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			//1 or 0
			dp[i + 1][j + 1] += dp[i][j] * 2;
			dp[i + 1][j + 1] %= MOD;

			//B
			dp[i + 1][max(0, j - 1)] += dp[i][j];
			dp[i + 1][max(0, j - 1)] %= MOD;
		}
	}
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << (dp[n][m] % MOD) * ((mod_pow(mod_pow(2, m), (MOD - 2)) % MOD)) % MOD << endl;
	return 0;
}
