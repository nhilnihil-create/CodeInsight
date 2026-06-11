#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 2005;

int n, k;
LL f[N][N], fac[N*N], inv[N*N];

LL Ksm(LL a, LL b) {
	LL res = 1;
	while(b) {
		if(b&1) res = res*a%mod;
		b /= 2;
		a = a*a%mod;
	}
	return res;
}

void Init() {
	fac[0] = inv[0] = 1;
	rep(i, 1, n*k)
	   fac[i] = fac[i - 1]*i%mod, inv[i] = Ksm(fac[i], mod - 2);
}

LL Cal(int n, int k) {
	return fac[n]*inv[k]%mod*inv[n - k]%mod;
}

int main() {
	cin>>n>>k;
	if(k == 1) {
		cout<<1<<endl;
		return 0;
	}
	Init();
	f[0][0] = 1;
	rep(i, 1, n)
	    rep(j, 0, i) {
	    	if(j < i) f[i][j] += f[i - 1][j];
	    	if(j) f[i][j] += f[i][j - 1]*(n - j + 1)%mod*Cal(n*k - j*k - i + j + k - 2, k - 2)%mod;
	    	f[i][j] %= mod;
	    }
	cout<<f[n][n]<<endl;
}