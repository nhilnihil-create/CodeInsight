#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
// head
const int maxn = 2e3 + 5;
int n, k;
LL f[maxn][maxn], fac[maxn*maxn], inv[maxn*maxn];

LL ksm(LL a, LL b) {
	LL res = 1;
	while(b) {
		if(b%2) res = res*a%mod;
		b /= 2;
		a = a*a%mod;
	}
	return res;
}

LL comb(LL a, LL b) {
	return fac[a]*inv[b]%mod*inv[a - b]%mod;
}

int main() {
	cin>>n>>k;
	if(k == 1) { 
		cout<<1<<endl;
		return 0;
	}
	fac[0] = inv[0] = 1;
	rep(i, 1, n*k)
	    fac[i] = fac[i - 1]*i%mod, inv[i] = ksm(fac[i], mod - 2);
	f[0][0] = 1;
	rep(i, 1, n)
	    rep(j, 0, i) {
	    	if(i > j) f[i][j] = (f[i][j] + f[i - 1][j])%mod;
	    	if(j) f[i][j] = (f[i][j] + f[i][j - 1]*(n - j + 1)%mod*comb(n*k - i - (j - 1)*(k - 1) - 1, k - 2)%mod)%mod;
	    }
	cout<<f[n][n]<<endl;
}