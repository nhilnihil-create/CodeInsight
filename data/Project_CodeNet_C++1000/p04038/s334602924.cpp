#include <cstdio>
#define LL long long
const int maxn = 4e6 + 5;
const int mo = 1e9 + 7;
using namespace std;
LL f[2005][2005], fac[maxn], inv[maxn];
LL C(int n, int m){
	if (m == 0 || m == n) return 1;
	if (m > n) return 0;
	return fac[n] * inv[n - m] % mo * inv[m] % mo;
}
LL pow(LL x, int t){
	LL res = 1; x %= mo;
	while (t > 0){
		if (t & 1) res = res * x % mo;
		x = x * x % mo;
		t >>= 1;
	}
	return res;
}
int n, k; 
int main(){
	scanf("%d%d", &n, &k);
	if (k == 1){
		puts("1");
		return 0;
	}
	fac[0] = 1; 
	for (int i = 1; i <= n * k; i++) fac[i] = fac[i - 1] * i % mo;
	inv[n * k] = pow(fac[n * k], mo - 2);
	for (int i = n * k - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mo;
	for (int i = 0; i <= n; i++)
		for (int j = i; j <= n; j++){
			if (i == 0 && j == 0) f[i][j] = 1;
			if (j != 0) f[i][j] = (f[i][j] + f[i][j - 1]) % mo;
			if (i != 0) f[i][j] = (f[i][j] + f[i - 1][j] * (n - i + 1) % mo * C(n * k - (i - 1) * (k - 1) - j - 1, k - 2) % mo) % mo;
		}
	printf("%lld\n", f[n][n]);
	return 0;
}