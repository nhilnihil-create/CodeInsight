#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++i)
#define dep(i, j, k) for(int i = j; i >= k; --i)
#define inv(x) (ksm(x, P - 2))

using namespace std;

const int maxn = 4e6 + 5;
const int P = 1e9 + 7;

int n, k, f[2005][2005], fac[maxn], ifac[maxn];

inline int read() {
	char ch = getchar(); int u = 0, f = 1;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch))  { u = u * 10 + ch - 48; ch = getchar(); } return u * f;
}

inline int pls(int x, int y) { x += y; return x >= P ? x - P : x; }
inline int dec(int x, int y) { x -= y; return x < 0 ? x + P : x; }
inline int ksm(int x, int k, int rnt = 1) {
	for(int i = k; i; i >>= 1, x = 1ll * x * x % P) if(i & 1) rnt = 1ll * rnt * x % P;
	return rnt;
}

const int inv2 = inv(2);

inline int C(int n, int m) { return 1ll * fac[n] * ifac[n - m] % P * ifac[m] % P; }

int main() {
	n = read(); k = read(); fac[0] = 1; int N = n * k;
	if(k == 1) { puts("1"); return 0; }
	rep(i, 1, N) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N - 1] = inv(fac[N - 1]);
	dep(i, N - 2, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
	f[0][0] = 1;
	rep(i, 1, n) rep(j, 0, i) {
		f[i][j] = pls(f[i][j], f[i - 1][j]);
		if(j) f[i][j] = pls(f[i][j], 1ll * f[i][j - 1] * (n - j + 1) % P * C(N - i - (k - 1) * (j - 1) - 1, k - 2) % P);
	}
	cout << f[n][n] << endl;
	return 0;
}
/*
1 1 2 2
1 2 1 2
1 2 2 1
2 1 1 2
2 1 2 1
2 2 1 1

0 1 0 2
0 0 1 2
0 0 2 1
0 0 1 2
0 0 2 1
0 2 0 1
 0 1 
0 2 0 1
0 0 1 2
0 1 0 2
*/