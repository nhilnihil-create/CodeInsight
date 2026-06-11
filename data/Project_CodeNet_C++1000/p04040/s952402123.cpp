#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];


void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
	COMinit();
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	ll res = 0;
	REP(i, h - a) {
		res += COM(b - 1 + i, b - 1)*COM(w - b - 1 + h - 1 - i, w - b - 1);
		res %= mod;
	}
	cout << res << endl;

	return 0;
}