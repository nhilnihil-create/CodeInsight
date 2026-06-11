#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const ll mod = 1e9 + 7;
ll modpow(ll A, ll B) {
	ll kotae = 1;
	while (B > 0) {
		if (B & 1) kotae = kotae * A % mod;
		A = A * A % mod;
		B >>= 1;
	}
	return kotae;
}

ll dp[5001][5001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	string S;
	cin >> S;

	int M = S.size();

	dp[0][0] = 1;
	rep(i, N) {
		rep(j, i + 1) {
			dp[i + 1][j + 1] += dp[i][j];
			
			if (j) dp[i + 1][j - 1] += 2 * dp[i][j];
			else dp[i + 1][j] += dp[i][j];
			
		}
		rep(j, i + 2) dp[i + 1][j] %= mod;
	}

	co(dp[N][M]);

	Would you please return 0;
}