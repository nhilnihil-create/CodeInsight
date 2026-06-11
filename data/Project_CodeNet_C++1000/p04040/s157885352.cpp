#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int N = 1e5 + 5;
const int mod = 1e9 + 7; 
using namespace std;

int n, m, a, b, fac[N << 1], inv[N << 1], ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int fpow(int x, int y)
{
	int res = 1;
	for( ; y; y >>= 1, x = 1ll * x * x % mod)
		if(y & 1) res = 1ll * res * x % mod;
	return res; 
}

int C(int n, int m)
{
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod; 
}

int main()
{
	n = read <int> (), m = read <int> (), a = read <int> (), b = read <int> ();
	for(int i = (fac[0] = 1); i <= n + m; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n + m] = fpow(fac[n + m], mod - 2);
	for(int i = n + m - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
	for(int i = 1; i <= a; i++)
		ans = (1ll * C(b - 1 + n - i, b - 1) * C(m - b - 1 + i - 1, i - 1) + ans) % mod;
	ans = (C(n + m - 2, n - 1) - ans + mod) % mod;
	printf("%d\n", ans); 
	return 0; 
}
