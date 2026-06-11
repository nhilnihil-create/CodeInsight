#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char s[5010];
long long f[5010][5010];
long long inv[5010];

long long power(long long a, long long b){
	if (b == 0) return 1;
	long long t = power(a, b / 2);
	t = t * t % mod;
	return b & 1 ? t * a % mod : t;
}

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int len = strlen(s);
	inv[1] = 1, inv[2] = (mod - mod / 2) * inv[mod % 2] % mod;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			f[i][j] = (f[i][j] + 2 * f[i - 1][j - 1] % mod) % mod;
			f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
			if (j == 0) f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
		}
	}
	printf("%lld\n", f[n][len] * power(inv[2], len) % mod);
	return 0;
}
