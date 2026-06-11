#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5, mod = 1e9 + 7;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

int n, sum, ans, f[maxn];

int main()
{
	n = gi();
	sum = f[0] = 1;
	ans = ((ll)(n - 1) * (n - 1) + 1 + (n > 2)) % mod;
	for (int i = 1; i < n; ++i) {
		f[i] = sum;
		if (i >= 2) f[i] = (f[i] + mod - f[i - 2]) % mod;
		sum = (sum + f[i]) % mod;
		if (i != n - 1) ans = (ans + (ll)f[i] * ((ll)(n - 1) * (n - 1) % mod + min(n - 1, i + 2))) % mod;
		else ans = (ans + (ll)f[i] * n) % mod;
	}
	printf("%d\n", ans);
	
	return 0;
}
