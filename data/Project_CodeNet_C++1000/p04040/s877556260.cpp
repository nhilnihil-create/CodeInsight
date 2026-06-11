#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

llong gyaku(llong num, llong now){
	if(now == 1)
		return num;

	llong ret = gyaku(num, now/2);
	((ret %= mod) *= ret) %= mod;
	return ret * (now%2 ? num : 1) % mod;
}

int main(){
	int H, W, A, B;
	cin >> H >> W >> A >> B;

	vector<llong> nCr(H+W+1,1), nCr_r(H+W+1,1);
	for(int i = 1; i <= H+W; i++){
		nCr[i] = nCr[i-1] * i % mod;
		nCr_r[i] = nCr_r[i-1] * gyaku(i, mod-2) % mod;
	}

	llong ans = 0;
	for(int i = B+1; i <= W; i++){
		llong fst = nCr[H-A-1 + i-1] * nCr_r[H-A-1] % mod * nCr_r[i-1] % mod;
		llong snd = nCr[A-1 + W-i] * nCr_r[A-1] % mod * nCr_r[W-i] % mod;
		(ans += fst*snd) %= mod;
	}

	cout << ans << endl;

	return 0;
}