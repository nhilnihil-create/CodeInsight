#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)
#define ERROR return puts("Impossible"), 0

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
inline void chkmax(T&a, T b) { a = a > b ? a : b; }

int c[110];
int mx;

int main() {
#ifdef LOCAL
	FILE("");
#endif

	int n = ri;
	for(int i = 1; i <= n; i++) {
		int x = ri;
		++c[x];
		chkmax(mx, x);
	}

	int mi = (mx + 1) >> 1;
	for(int i = mx; i > mi; --i) {
		if(c[i] < 2) ERROR;
		n -= c[i];
	}
	if(c[mi] != 1 + (mx & 1) || n != c[mi]) ERROR;
	puts("Possible");
	return 0;
}