#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int MOD = 1e9 + 7;
const int LIM = 1e5 + 5;
lli col[LIM];
lli fac[2*LIM];

int h, w, a, b;

lli powerr(int a, int b) {
	if(b == 0) {
		return 1;
	} else if(b == 1) {
		return a;
	} else {
		lli base = powerr(a, b/2);
		lli ans = base*base % MOD;
		if(b%2) {
			ans *= a;
			ans %= MOD;
		}
		return ans;
	}
}

void initFac() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i < 2*LIM; i++) {
		fac[i] = i*fac[i-1];
		fac[i] %= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> h >> w >> a >> b;

	initFac();

	for(int i = 0; i < h; i++) {
		if(i < h - a) {
			col[i] = fac[i + b];
			col[i] %= MOD;
			col[i] *= powerr(fac[i], MOD - 2);
			col[i] %= MOD;
			col[i] *= powerr(fac[b], MOD - 2);
			col[i] %= MOD;
		} else {
			col[i] = col[i-1];
		}
	}

	lli ans = 0;

	if(b + 1 != w) {
		for(int i = 0; i < h; i++) {
			lli term = col[i];
			term *= fac[h+w-i-b-3];
			term %= MOD;
			term *= powerr(fac[w-b-2], MOD-2);
			term %= MOD;
			term *= powerr(fac[h-i-1], MOD-2);
			term %= MOD;

			ans += term;
			ans %= MOD;
		}
	} else {
		ans = col[h-1];
	}

	cout << ans << endl;

	return 0;
}