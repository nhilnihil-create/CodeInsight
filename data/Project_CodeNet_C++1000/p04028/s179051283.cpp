#include<iostream>
#include<string>
using namespace std;
typedef long long int ll;
static const int MAX_N = 5000;
static const int MOD = 1000000007;
ll mod_pow(ll x, ll n){
	if(n == 0) return 1;
	ll res = mod_pow(x * x % MOD, n / 2);
	if(n % 2 == 1) res = res * x % MOD;
	return res;
}
int main(){
	int N;
	string S;
	ll dp[5010][5010];
	cin >> N;
	cin >> S;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			if(i == 0 && j == 0) dp[i][j] = 1;
			else if(j == 0) dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
			else if(i >= 1 && j >= 1) dp[i][j] = 2 * dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}
	ll num = mod_pow(2, S.length());
	cout << dp[N][S.length()] * mod_pow(num, MOD - 2) % MOD << endl;
	return 0;
}