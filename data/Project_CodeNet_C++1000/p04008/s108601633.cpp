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
inline void chkmax(T&a, T b) { a = a > b ? a : b; }

const int MAXN = 100010;

int n;
int k;
int res;
int a[MAXN];
vector<int> to[MAXN];

inline int dfs(int x) {
	int mx = 1;
	for(auto u : to[x]) chkmax(mx, dfs(u) + 1);
	if(x != 1 && a[x] != 1 && mx == k) return ++res, 0;
	else return mx;
}

int main() {
#ifdef LOCAL
	FILE("");
#endif

	n = ri, k = ri;

	for(int i = 1; i <= n; i++) a[i] = ri;
	res = a[1] != 1;

	for(int i = 2; i <= n; i++) to[a[i]].push_back(i);

	dfs(1), printf("%d\n", res);
	return 0;
}