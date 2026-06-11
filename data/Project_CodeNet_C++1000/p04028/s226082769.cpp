//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 5000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 12;

int DP[N][N], n, m;
string s;

int POW(int x, int y){
	int res = 1;
	while (y){
		if (y & 1) res = res * 1ll * x % MOD;
		y >>= 1;
		x = x * 1ll * x % MOD;
	}
	return res;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	m = (int)s.size();
	DP[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for( int j = 0; j <= i; j++){
			if (j == 0) DP[j][i] = (DP[j][i - 1] + DP[j + 1][i - 1]) % MOD;
			else DP[j][i] = (DP[j - 1][i - 1] * 2 + DP[j + 1][i - 1]) % MOD;
		}
	}
	int res = 1;
	for (int i = 1; i <= m; i++) res =  res * 2ll % MOD;
	cout << (DP[m][n] * 1ll * POW(res, MOD - 2)) % MOD;











	return 0;
}
