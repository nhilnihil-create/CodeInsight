#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;

ll mpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
#define N 200010
int fac[N], finv[N];
void factorization() {
    fac[0] = finv[0] = 1;
    rep(i, 1, N)fac[i] = 1LL * fac[i - 1] * i % mod;
    finv[N - 1] = mpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i; --i) finv[i] = 1LL * finv[i + 1] * (i + 1) % mod;
}
int nCr(int n, int m) {
    if (m < 0 || n < m) return 0;
    return 1LL * (1LL * fac[n] * finv[m] % mod) * finv[n - m] % mod;
}


int main() {
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	factorization();
	ll ans=0;
	rep(i,b,w+1){
		ans=(ans+1LL*nCr(h-a-1+i,i)*nCr(a-1+w-1-i,w-1-i))%mod;
	}
	printf("%lld",ans);
	return 0;
}
