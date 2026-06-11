#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1000000007;
ll f1[200010], f2[200010], fv[200010];
void init() {
	f2[0] = f2[1] = fv[0] = fv[1] = f1[1] = 1;
	for(ll i = 2; i < 200010; i ++) {
		f1[i] = MOD - f1[MOD % i] * (MOD / i) % MOD;
		f2[i] = f2[i - 1] * i % MOD;
		fv[i] = fv[i - 1] * f1[i] % MOD;
	}
}
ll comp(ll a, ll b) {
	if(a < b) {
		return 0;
	}
	return f2[a] * (fv[b] * fv[a - b] % MOD) %  MOD;
}
int main() {
	ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	init();
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	W --, H --;
	ll res = comp(H + W,W);
	for(int i = 0; i < B; i ++) {
		ll rel = comp(H - A + i, i);
		ll des = comp(W + A - i - 1, A - 1);
		res -= rel * des % MOD;
		if(res < 0) {
			res += MOD;
		}
	}
	cout << res << endl;
	return 0;
}