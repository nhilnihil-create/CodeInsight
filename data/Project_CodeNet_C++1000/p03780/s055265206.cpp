#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)
using namespace std;
inline int read() {
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}
typedef long long ll; const int N = 5005;
int n, K, a[N]; bool f[N]; ll sum;
int main() {
	int i, j; n = read(); K = read(); For (i, 1, n) sum += (a[i] = read());
	f[0] = 1; sort(a + 1, a + n + 1); Rof (i, n, 1) {
		int l = max(-sum + K, 0ll), r = K - 1; bool orz = 0;
		For (j, l, r) if (f[j]) {orz = 1; break;}
		if (!orz) return printf("%d\n", i), 0;
		sum -= a[i]; Rof (j, K, a[i]) f[j] |= f[j - a[i]];
	}
	puts("0"); return 0;
}