#include <bits/stdc++.h>

typedef long long ll;
const int N = 1000054, mod = 1000000007;

int n;
int f[N];
ll F[N];

int main() {
	int i; ll t;
    scanf("%d", &n), t = (n - 1ll) * (n - 1ll) % mod;
    for (F[n] = f[n] = n, i = n - 1; i; --i)
    	f[i] = (f[i + 1] + t + i + (i != n - 1) + F[i + 3]) % mod,
    	F[i] = F[i + 1] + f[i];
    printf("%d\n", f[1]);
    return 0;
}