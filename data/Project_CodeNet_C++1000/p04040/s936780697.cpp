#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 
const int Mod = 1e9 + 7; 
const int MAX_N = 2e5 + 5; 
int fpow(int x, int y) { 
	int res = 1; 
	while (y) {
		if (y & 1) res = 1ll * res * x % Mod; 
		x = 1ll * x * x % Mod; 
		y >>= 1; 
	} 
	return res; 
} 
int N = 2e5, M, A, B; 
int fac[MAX_N], ifc[MAX_N]; 
int C(int n, int m) { 
	if (n < m || n < 0 || m < 0) return 0; 
	return 1ll * fac[n] * ifc[m] % Mod * ifc[n - m] % Mod; 
} 
int solve(int x, int y, int u, int v) { 
	return C(u - x + v - y, u - x); 
} 
int main () { 
	fac[0] = 1; for (int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % Mod; 
	ifc[N] = fpow(fac[N], Mod - 2); 
	for (int i = N - 1; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % Mod; 
	cin >> N >> M >> A >> B;
	int ans = 0; 
	for (int i = N - A, j = B + 1; i >= 0 && j <= M; i--, j++) { 
		ans = (ans + 1ll * solve(1, 1, i, j) * solve(i, j, N, M)) % Mod; 
	} 
	printf("%d\n", ans); 
    return 0; 
} 