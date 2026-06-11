//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()

#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
#define MAX_N (100001)
typedef long long ll;

using namespace std;

int fac[200001];
int rfac[200001];

int combi(int n, int r) {
	//if (r < 0 || n < r) return 0;
	//if (n - r < r) return combi(n, n - r);
	int res = 1;
	res = res * fac[n] %MOD;
	res = res * rfac[n - r] % MOD;
	res = res * rfac[r]%MOD;
	//cout << n << " " << r << " " << res << endl;
	return res;
}

int modpow(int n, int a) {
	int res = 1;
	while (a > 0) {
		if (a & 1) res = res * n % MOD;
		n = n * n % MOD;
		a >>= 1;
	}
	return res;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fac[0] = rfac[0] = 1;
	for (int i = 1; i < 200001; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		rfac[i] = modpow(fac[i], MOD - 2);
	}
	int h, w; cin >> h >> w;
	int a, b; cin >> a >> b;
	int ans = 0;
	rep(i, h - a) {
		int k = (combi(b + i -1, b - 1) * combi(h + w - 2 - b - i, w - b - 1))%MOD;
		//cout << k << endl;
		ans = (ans + k) % MOD;
	}
	cout << ans << endl;
}
