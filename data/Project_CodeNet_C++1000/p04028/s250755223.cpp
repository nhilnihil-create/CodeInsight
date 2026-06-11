#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
const int N = 5005;
const int mod = 1e9 + 7; 
using namespace std;

int n, m, f[N][N]; 
char s[N]; 

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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), scanf("%s", s + 1), m = strlen(s + 1);
	f[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			f[i + 1][j + 1] = (2ll * f[i][j] + f[i + 1][j + 1]) % mod; 
			f[i + 1][max(j - 1, 0)] = (f[i][j] + f[i + 1][max(j - 1, 0)]) % mod; 
		}
	printf("%lld\n", 1ll * f[n][m] * fpow(fpow(2, m), mod - 2) % mod); 
	return 0; 
}
