/*--------------------------------
  Author: The Ace Bee
  Blog: www.cnblogs.com/zsbzsb
  This code is made by The Ace Bee
--------------------------------*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#define rg register
using namespace std;
template < typename T > inline void read(T& s) {
	s = 0; int f = 0; char c = getchar();
	while (!isdigit(c)) f |= (c == '-'), c = getchar();
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	s = f ? -s : s;
}

const int _ = 100010;

int n, L, q, x[_], nxt[22][_], pre[22][_];

inline int calc(int a, int b) {
	int res = 0;
	if (a < b) {
		for (rg int i = 20; ~i; --i) {
			if (nxt[i][a] < b)
				a = nxt[i][a], res += 1 << i;
			if (a == b) return res;
		}
	} else {
		for (rg int i = 20; ~i; --i) {
			if (pre[i][a] > b)
				a = pre[i][a], res += 1 << i;
			if (a == b) return res;
		}
	}
	return res + 1;
}

int main() {
	read(n);
	for (rg int i = 1; i <= n; ++i) read(x[i]);
	read(L), read(q);
	
	for (rg int i = 1, to = 0; i <= n; ++i)
	{ while (x[to + 1] - x[i] <= L && to < n) ++to; nxt[0][i] = to; }
	for (rg int i = n, to = n + 1; i >= 1; --i)
	{ while (x[i] - x[to - 1] <= L && to > 1) --to; pre[0][i] = to; }
	
	for (rg int j = 1; j <= 20; ++j)
		for (rg int i = 1; i <= n; ++i) {
			nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
			if (nxt[j][i] == 0) nxt[j][i] = n;
			pre[j][i] = pre[j - 1][pre[j - 1][i]];
			if (pre[j][i] == 0) pre[j][i] = 1;
		}

	for (rg int a, b, i = 1; i <= q; ++i)
		read(a), read(b), printf("%d\n", calc(a, b));
	
	return 0;
}
