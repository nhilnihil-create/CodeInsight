#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T>
inline void chkmin(T&a, T b) { a = a < b ? a : b; }

const int MAXN = 100010;

int a[MAXN];

inline bool cmp(int a, int b) { return a > b; }

int main() {
#ifdef LOCAL
	FILE("");
#endif

	int n = ri;
	for(int i = 1; i <= n; i++) a[i] = ri;
	sort(a + 1, a + 1 + n, cmp);

	int pos = 1;
	while(a[pos + 1] >= pos + 1) ++pos;
	int U = a[pos] - pos, R = 0;
	while(a[pos + R + 1] >= pos) ++R;
	if((U & 1) || (R & 1)) puts("First");
	else puts("Second");
	return 0;
}