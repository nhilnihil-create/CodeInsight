#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R + 1) >> 1)
using namespace std;
const int MAXN = 100050;
const int mod = 998244353;
typedef long long LL;
int n;
bool f[MAXN];
char s[MAXN];
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> s;
	s[n] = s[0];
	s[n + 1] = s[1];
	n += 2;
	for (int T = 0; T < 4; ++T) {
		f[0] = T & 1;
		f[1] = T >> 1;
		for (int i = 2; i < n; ++i) {
			if (!f[i - 1]) {
				f[i] = f[i - 2] ^ (s[i - 1] == 'x');
			} else {
				f[i] = f[i - 2] ^ (s[i - 1] == 'o');
			}
		}
		if (f[0] == f[n - 2] && f[1] == f[n - 1]) {
			n -= 2;
			for (int i = 0; i < n; ++i) {
				putchar("SW"[f[i]]);
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}