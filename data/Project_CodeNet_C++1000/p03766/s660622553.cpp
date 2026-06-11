#include <cstdio>
const int MAXN = 1e6 + 5, mod = 1e9 + 7;
inline int addmod(int a, int b) { return (a + b) % mod; }
inline int mulmod(long long a, int b) { return (a * b) % mod; }
int n, f[MAXN], prefix[MAXN];
inline int get(int l, int r) {
	int res = 0;
	if(l < 0) {
		res = addmod(res, -l);
		l = 0;
	}
	res = addmod(res, prefix[r]);
	if(l > 0) res = addmod(res, mod - prefix[l - 1]);
	return res;
}
int main() {
	scanf("%d", &n);
	f[0] = 1;
	f[1] = n;
	prefix[0] = f[0];
	prefix[1] = f[0] + f[1];
	int tmp = mulmod(n - 1, n - 1);
	for(int i = 2; i <= n; i++) {
		f[i] = addmod(f[i - 1], addmod(tmp, get(i - n - 1, i - 3)));
		prefix[i] = addmod(prefix[i - 1], f[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}