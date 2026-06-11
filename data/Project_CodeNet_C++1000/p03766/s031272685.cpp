#include <cstdio>

typedef long long ll;

const int MAXN = 1E6 + 10;
const int MOD = 1E9 + 7;

ll f[MAXN], s[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	if (n == 1){
		puts("1");
		return 0;
	}

	f[0] = s[0] = 1;
	f[1] = 1, s[1] = 2;
	for (int i = 2; i <= n; ++i){
		f[i] = (s[i - 1] - f[i - 2] + MOD) % MOD;
		s[i] = (s[i - 1] + f[i]) % MOD;
	}
	ll ans = (f[n] + f[n - 1] * (n - 1)) % MOD;
	ll t = (n - 1ll) * (n - 1) % MOD;
	for (int i = 0; i < n - 1; ++i)
		ans = (ans + (t + i + 1) * f[i]) % MOD;
	printf("%lld\n", ans);
	return 0;
}
