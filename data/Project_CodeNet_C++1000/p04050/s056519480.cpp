#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define ri rd<int>
using namespace std;
const int maxN = 107;
 
template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}
 
int n, m;
int a[maxN];
int cnt, c[2];
 
int main() {
 
	n = ri(), m = ri();
 
	if (m == 1) {
		int x = ri();
		if (x != 1) printf("%d\n2\n1 %d\n", x, x - 1);
		else printf("%d\n1\n%d\n", x, x);
		return 0;
	}
 
	rep (i, 1, m) {
		a[i] = ri();
		if (a[i] & 1) {
			if (cnt == 2) {
				puts("Impossible");
				return 0;
			}
			c[cnt++] = i;
		}
	}
 
	if (cnt >= 1) swap(a[1], a[c[0]]);
	if (cnt == 2) swap(a[m], a[c[1]]);
 
	rep (i, 1, m) printf("%d%c", a[i], " \n"[i == m]);
	printf("%d\n", m - (a[1] == 1));
	rep (i, 1, m) {
		if (i == 1) {if (a[i] != 1) printf("%d ", a[i] - 1);}
		else if (i == m) printf("%d\n", a[i] + 1);
		else printf("%d ", a[i]);
	}
 
	return 0;
}