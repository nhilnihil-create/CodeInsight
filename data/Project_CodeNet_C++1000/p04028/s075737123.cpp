#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p (int)(1e9 + 7)

int MOD(ll a){
	return (int)((a %= p) >= 0 ? a : a + p);
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD((ll)a * a), N / 2);
	}
	else{
		return MOD((ll)a * power(a, N - 1));
	}
}

int f(int k, int l){
	if(k < l || (k - l) % 2 == 1){
		return 0;
	}
	else{
		return power(2, (k - l) / 2);
	}
}

signed main(){
	int N, i, j;
	scanf("%d", &N);
	string s;
	cin >> s;
	vector<vector<int>> dp(N + 1, vector<int>(N + 2, 0)), dp2(N + 1, vector<int>(N + 2, 0));
	dp[0][0] = 1;
	for(i = 1; i <= N; i++){
		for(j = 0; j <= N; j++){
			if(j > 0){
				dp[i][j] = MOD((ll)dp[i - 1][j - 1] + dp[i - 1][j + 1]);
			}
			else{
				dp[i][j] = dp[i - 1][j + 1];
			}
		}
	}
	dp2[0][0] = 1;
	for(i = 1; i <= N; i++){
		for(j = 0; j <= N; j++){
			if(j > 0){
				dp2[i][j] = MOD(2 * (ll)dp2[i - 1][j - 1] + dp2[i - 1][j + 1]);
			}
			else{
				dp2[i][j] = MOD((ll)dp2[i - 1][j] + dp2[i - 1][j + 1]);
			}
		}
	}
	int ans = 0;
	for(i = 1; i <= N; i++){
		ans = MOD(ans + (ll)MOD((ll)dp2[i - 1][0] * dp[N - i][s.size() - 1]) * f(N - i, s.size() - 1));
	}
	printf("%d\n", ans);
	return 0;
}