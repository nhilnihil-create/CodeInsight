// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 5e3 + 5;

int DP[N][N];

int Power(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}

int main() {
 
	sync;

	DP[0][0] = 1;
	for (int i = 1; i < N; i++) for (int j = 0; j <= i; j++) {
		if (j) DP[i][j] = 2LL * DP[i - 1][j - 1] % MOD;
		else DP[i][j] = DP[i - 1][j];
		if (j + 1 < N) DP[i][j] = (DP[i][j] + DP[i - 1][j + 1]) % MOD;
	}
	
	int n; cin >> n;
	string s; cin >> s;
	cout << 1LL * DP[n][sz(s)] * Power(Power(2, sz(s)), MOD - 2) % MOD << endl;

	return 0;
}
