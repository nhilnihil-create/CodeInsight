#include <bits/stdc++.h>
using namespace std;

#define IL inline 
IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f; 
}
const int maxn = 5005;
int n, len;
char s[maxn];
const int mod = 1e9 + 7;
int f[maxn][maxn];
IL int pls(int x, int y) { x += y; return x >= mod ? x - mod : x; }
IL int dec(int x, int y) { x -= y; return x < 0 ? x + mod : x; }
IL int mul(int x, int y) { return 1ll * x * y % mod; }
IL int fpw(int x, int y) {	
	int r = 1;
	for (; y; y >>= 1, x = mul(x, x)) 	
		if (y & 1) r = mul(r, x);
	return r;
}
int main() {
	n = read();
	scanf("%s", s + 1);
	len = strlen(s + 1);
	
	f[0][0] = 1;	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j != 0) f[i][j] = pls(f[i][j], mul(2, f[i - 1][j - 1]));
			else f[i][j] = f[i - 1][j];
			f[i][j] = pls(f[i][j], f[i - 1][j + 1]);
		}
	}	
	cout << mul(f[n][len], fpw(fpw(2, len), mod - 2));
	return 0;
}