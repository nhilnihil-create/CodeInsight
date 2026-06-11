#include <bits/stdc++.h>
#define N 2050
#define mod 1000000007
using namespace std;
typedef long long LL;

int n, k, tp;
LL fac[N*N], inv[N*N], infac[N*N], F[N][N];

void inc(LL &x, LL y) {x=(x+y)%mod;}

inline LL C(LL n, LL m) {
	if (n < m) return 0LL;
	if (n == m || m == 0) return 1LL;
	return 1LL * fac[n] * infac[m] % mod * infac[n-m] % mod;
}

int main() {
	cin >> n >> k;
	tp = (2000+1) * (2000+1);
	if (k == 1) return puts("1"), 0;
	fac[0] = fac[1] = 1LL;
	for (int i=2;i<=tp;i++)
		fac[i] = 1LL * fac[i-1] * i % mod;
	
	inv[0] = inv[1] = 1LL;
	for (int i=2;i<=tp;i++)
		inv[i] = 1LL * (mod-mod/i) * inv[mod%i] % mod;
	
	infac[0] = infac[1] = 1LL;
	for (int i=2;i<=tp;i++)
		infac[i] = 1LL * infac[i-1] * inv[i] % mod;
		
	F[0][0] = 1LL;
	
	for (int i=0;i<=n;i++)
		for (int j=i;j<=n;j++) {
			if (i) inc(F[i][j], F[i-1][j]);
			if (j) inc(F[i][j], 1LL * F[i][j-1] * C(i+(j-1)*(k-1)+k-2, k-2) % mod);
		}
	
	LL ans = 1LL * F[n][n] * fac[n] % mod;
	cout << ans << endl;
	return 0;
}