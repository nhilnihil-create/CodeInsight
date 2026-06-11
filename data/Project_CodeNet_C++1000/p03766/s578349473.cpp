#include <bits/stdc++.h>
using namespace std;
#define M 1000010
#define MOD 1000000007
#define rep(i, x, y) for(int i = (x); i <= (y); i ++)
inline int read() {
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	} while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	} return x * f;
}
int f[M];
int sum = 0;
int main() {
	int n = read(); sum = f[1] = n;
	f[2] = 1ll * n * n % MOD; (sum += f[2]) %= MOD;
	rep(i, 3, n) {
		f[i] = 1ll * (n - 1) * (n - 1) % MOD;
		(f[i] += sum) %= MOD;
		(f[i] += MOD - f[i - 2]) %= MOD;
		(f[i] += n - i + 2) %= MOD;
		(sum += f[i]) %= MOD;
	} cout << f[n];
	return 0;
}