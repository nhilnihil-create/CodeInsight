#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007LL;

int n;
char s[5050];
long long power[5050];
long long dp[5050][5050];
int lens = 0;

long long rek(int step, int len) {
	if(step >= n) {
		if(len == lens) {
			return 1LL;
		} else {
			return 0LL;
		}
	}

	if(dp[step][len] != -1) {
		return dp[step][len] % MOD;
	}

	long long rek1 = (long long) ((rek(step + 1, len + 1) % MOD * 2) % MOD);
	long long rek2 = (long long) (rek(step + 1, max(0, len-1)) % MOD);

	return dp[step][len] = (long long)((rek1 + rek2) % MOD);
}

long long pangkat(long long a, int b) {
	if(b == 0) return 1;
	if(b == 1) return a;

	long long aa = pangkat(a, b/2);
	if(b % 2 == 0) {
		return (aa * aa) % MOD;
	} else {
		return (((aa * aa) % MOD) * a) % MOD;
	}
}

int main() {
	power[0] = 1;
	for(int i = 1; i < 5005; i++) {
		power[i] = (power[i-1] * 2) % MOD;
	}

	memset(dp, -1LL, sizeof dp);
	scanf("%d", &n);
	scanf("%s", &s);

	lens = strlen(s);
	long long ans = rek(0, 0);
	long long inv = pangkat(power[lens], MOD - 2);

	printf("%lld\n", ((long long)(ans * inv)) % MOD);
	return 0;
}
