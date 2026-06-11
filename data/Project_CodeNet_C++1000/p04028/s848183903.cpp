#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;

signed main(){

	int n, m;
	string s;
	cin >> n >> s;
	m = s.size();

	// n回虚無をするパターン数

	auto mpow = [&](i64 x, i64 y){
		i64 ret = y & 1 ? x : 1, z = x;
		while(z = (z * z) % MOD, y >>= 1)
			if(y & 1)
				ret = (ret * z) % MOD;

		return ret;
	};

	vector<i64> fac(2 * n + 1, 1), inv(2 * n + 1, 1);
	for(int i = 1; i <= 2 * n; ++i){
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = mpow(fac[i], MOD - 2);
	}

	vector<i64> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; ++i){
		vector<i64> nex(n + 1, 0);
		for(int j = 0; j < n; ++j){
			nex[j + 1] = (nex[j + 1] + dp[j] * 2) % MOD;
			nex[max(0, j - 1)] = (nex[max(0, j - 1)] + dp[j]) % MOD;
		}
		dp = move(nex);
	}
	cout << (dp[m] * mpow(mpow(2, m), MOD - 2)) % MOD;
}
