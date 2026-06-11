#include <cstdio>
const int MAXN = 1e5 + 5, mod = 1e9 + 7;
inline int addmod(int a, int b) { return ((a + b) % mod + mod) % mod; }
inline int mulmod(long long a, int b) { return ((a * b) % mod + mod) % mod; }

int n, m, x[MAXN], y[MAXN], suffix[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &y[i]);

	int sum = 0;
	for(int i = n; i >= 1; i--) suffix[i] = addmod(suffix[i + 1], x[i]);
	for(int i = n; i >= 1; i--) sum = addmod(sum, suffix[i]);
	for(int i = 1; i <= n; i++) sum = addmod(sum, mod - mulmod(n - i + 1, x[i]));

	int sumy = 0;
	suffix[m + 1] = 0;
	for(int i = m; i >= 1; i--) suffix[i] = addmod(suffix[i + 1], y[i]);
	for(int i = m; i >= 1; i--) sumy = addmod(sumy, suffix[i]);
	for(int i = 1; i <= m; i++) sumy = addmod(sumy, mod - mulmod(m - i + 1, y[i]));

	printf("%d\n", mulmod(sum, sumy));
	return 0;
}