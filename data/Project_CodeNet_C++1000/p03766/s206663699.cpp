#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int N = 1e6 + 5;
const int mod = 1e9 + 7; 
using namespace std; 

int n, sum[N], f[N], ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin);
#endif
	n = read <int> (), f[0] = sum[0] = 1; 
	for(int res = 0, i = 1; i < n; i++)
	{
		if(i >= 3) res = (res + sum[i - 3]) % mod;
		f[i] = (res + 1) % mod, sum[i] = (sum[i - 1] + f[i]) % mod; 
	}
	f[n] = 1ll * (n - 1) * sum[n - 2] % mod, f[n] = (f[n] + 1) % mod; 
	for(int i = 0; i <= n; i++)
	{
		if(i + 2 <= n) ans = (1ll * f[i] * (n - 1) % mod * (n - 1) + ans) % mod;
		else if(i + 1 <= n) ans = (1ll * f[i] * (n - 1) + ans) % mod;
		else ans = (ans + f[i]) % mod; 
	}
	printf("%d\n", ans); 
	return 0; 
}
