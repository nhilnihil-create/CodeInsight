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
typedef long long LL;
const int maxN = 1e5 + 7;
const LL INF = (1LL << 61) + 7;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

inline LL getch() {
	static char s[5]; scanf("%s", s);
	return s[0] == '-' ? -1 : 1;
}

inline LL sgn(int x) {return (x & 1) ? -1 : 1;}

inline void Max(LL &x, LL y) {if (y > x) x = y;}

int n;
LL a[maxN], opr[maxN];
LL f[3][maxN];

int main() {
	
	n = ri();
	opr[1] = 1;
	rep (i, 1, n) a[i] = ri(), opr[i + 1] = getch();

	f[0][0] = 0; f[1][0] = f[2][0] = -INF;
	rep (i, 1, n) {
		rep (j, 0, 2) f[j][i] = -INF;
		rep (j, 0, 2) rep (k, 0, j) {
			Max(f[k][i], f[j][i - 1] + sgn(k) * opr[i] * a[i]);
		}
		if (opr[i] == -1) {
			per (j, 2, 1) {
				Max(f[j][i], f[j-1][i]);
			}
		}
	}

	printf("%lld\n", max(max(f[0][n], f[1][n]), f[2][n]));

	return 0;
}
