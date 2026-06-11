#include <bits/stdc++.h>
#define N 2050
#define mod 1000000007
using namespace std;
typedef long long LL;
const int tp = 4000000;

int n,k;
LL F[N][N],jc[N*N],inv[N*N],invjc[N*N];
inline int rd() {int r;scanf("%d",&r);return r;}

inline LL C(int x,int y) {
	if (x < y) return 0;
	return 1LL * jc[x] * invjc[y] % mod * invjc[x-y] % mod;
}

inline void inc(LL &x, LL y) {x=(x+y)%mod;}

int main() {
	n = rd(), k = rd();
	
	if (k == 1) {puts("1"); return 0;} 
	
	jc[0] = jc[1] = 1LL;
	for (int i=2;i<=tp;i++) jc[i] = 1LL * jc[i-1] * i % mod;
	
	inv[0] = inv[1] = 1LL;
	for (int i=2;i<=tp;i++) inv[i] = 1LL * (mod-mod/i) * inv[mod % i] % mod;
	
	invjc[0] = invjc[1] = 1LL;
	for (int i=2;i<=tp;i++) invjc[i] = 1LL * invjc[i-1] * inv[i] % mod;

	F[0][1] = 1LL;
	for (int i=2;i<=n;i++)
		F[0][i] = 1LL * F[0][i-1] * C(i*(k-1)-1, k-2) % mod;

	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++) {
			if (i-1 >= 0) inc(F[i][j], F[i-1][j]);
			if (j-1 >= 0) inc(F[i][j], 1LL * C(i+j*(k-1)-1, k-2) * F[i][j-1] % mod);
		}

	LL ans = 1LL * F[n][n] * jc[n] % mod;
	cout << ans << endl;
	return 0;
}