#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int mod = 1e9 + 7;
const int MAXN = 222222;

int h, w, a, b;
lint fact[MAXN], invf[MAXN];

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

lint path(int sx, int sy, int ex, int ey){
	int d = ex - sx;
	int e = ey - sy;
	return fact[d+e] * (invf[d] * invf[e] % mod) % mod;
}

int main(){
	fact[0] = invf[0] = 1;
	for(int i=1; i<MAXN; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	cin >> h >> w >> a >> b;
	lint ret = 0;
	for(int i=1; i<=w-b; i++){
		ret += path(1, 1, a, i) * path(a+1, i, h, w) % mod;
	}
	cout << ret % mod << endl;
}
