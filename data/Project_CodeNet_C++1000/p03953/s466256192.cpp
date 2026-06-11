/********************************************************************************
	
	Code by a weak man who named CYJian, and he hopes the code can get more points.

	Algorithm: 

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define ra read_alpha()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline char read_alpha() { char c = ge; while(!isalpha(c) && c != EOF) c = ge; return c; }
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

const int MAXN = 100010;

int p[MAXN];
int pos[MAXN];
int res[MAXN];

int cir[MAXN];
int len;

int main() {
#ifdef LOCAL
	FILE("");
#endif
	int n = ri;
	for(int i = 1; i <= n; i++) p[i] = ri;
	for(int i = 1; i <= n; i++) pos[i] = i;
	for(int i = n; i >= 1; i--) p[i] -= p[i - 1];
	int m = ri, x; ll k = rl;
	for(int i = 1; i <= m; i++) x = ri, swap(pos[x], pos[x + 1]);
	for(int i = 1; i <= n; i++) {
		if(!pos[i]) continue;
		int p = i;
		len = 0;
		while(pos[p]) {
			cir[++len] = pos[p];
			int tp = pos[p];
			pos[p] = 0, p = tp;
		}
		for(int j = 1; j <= len; j++)
			res[cir[j]] = cir[(j + k - 1) % len + 1];
	} ll P = 0;
	for(int i = 1; i <= n; i++) P += p[res[i]], printf("%lld.0\n", P);
	return 0;
}