#include<iostream>
#include<cstdio>
//This code is written by Itst
using namespace std;

const int MAXN = 1e6 + 7 , MOD = 1e9 + 7;
int N , dp[MAXN];

int main(){
	cin >> N;
	dp[N] = N; dp[N - 1] = (1ll * N * N + dp[N]) % MOD;
	for(int i = N - 2 ; i > 0 ; --i)
		dp[i] = (dp[i + 1] - dp[i + 2] + (N - 1ll) * (N - 1) + dp[i + 3] + dp[i + 1] + i + 1 + MOD) % MOD;
	cout << (dp[1] - dp[2] + MOD) % MOD;
	return 0;
}
