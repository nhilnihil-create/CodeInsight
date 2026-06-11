#include <cstdio>
#include <iostream>
using namespace std;
const int mo = 1e9 + 7, N = 2e3 + 10, E = 5e6;
typedef long long ll;
ll f[N][N],jc[E],njc[E],suf[N][N];
ll n,k;
ll ksm(ll x,ll y) {
	ll ret = 1; for (; y; y>>=1) {if (y&1) ret = ret * x % mo;
		x = x * x % mo;
	}
	return ret;
}
ll C(ll x,ll y) {
	if (x < y) return 0;
	return jc[x] * njc[x-y] % mo * njc[y] % mo;
}
int main() {
	cin>>n>>k; if (k == 1) {
		printf("1"); return 0;
	}
	suf[0][0] = f[0][0] = 1;
	jc[0] = 1; for (int i = 1; i < E; i++) jc[i] = jc[i-1] * i % mo;
	njc[E-1] = ksm(jc[E - 1],mo-2);
	for (int i = E-2; ~i; i--) njc[i] = njc[i+1] * (i+1) % mo;
	for (int i = 1; i <= n; suf[i][0]=suf[i][1],i++) for (int j = i; j; j--) {
		f[i][j] = suf[i-1][j-1] * C(k+k*(i-1)-j-1,(i-1)*k-j+1) % mo;
		suf[i][j] = (suf[i][j+1] + f[i][j]) % mo;
	}
	printf("%lld\n",suf[n][1] * jc[n] % mo);
}