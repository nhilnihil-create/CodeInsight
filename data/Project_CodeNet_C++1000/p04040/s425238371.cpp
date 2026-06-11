#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 1000000007
#define N 100005
using namespace std;

int h, w, a, b, jc[N << 1], inv[N << 1], ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int C(int n, int m)
{
	if(n < 0 || m > n) return 0;
	return 1ll * jc[n] * inv[m] % mod * inv[n - m] % mod; 
}

int main()
{
	h = read <int> (), w = read <int> (), a = read <int> (), b = read <int> ();
	inv[0] = inv[1] = jc[0] = jc[1] = 1; 
	for(int i = 2; i <= 200000; i++)
	{
		jc[i] = 1ll * jc[i - 1] * i % mod;
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod; 
	}
	for(int i = 2; i <= 200000; i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % mod;
	ans = C(h + w - 2, h - 1); 
	for(int i = 1; i <= b; i++)
		ans = 1ll * ((1ll * ans - 1ll * C(h - a + i - 2, i - 1) * C(w - i + a - 1, a - 1) % mod) + mod) % mod; 
	printf("%d\n", ans); 
	return 0; 
}
