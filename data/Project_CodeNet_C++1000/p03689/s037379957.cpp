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
const int maxN = 507;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

int H, W, h, w, S;
int a[maxN][maxN];
LL sum = 0;

int main() {

	H = ri(), W = ri(), h = ri(), w = ri();
	rep (i, 1, H) rep (j, 1, W) a[i][j] = 1000;
	S = (h * w - 1) * 1000;
	for (int i = h; i <= H; i += h)
	for (int j = w; j <= W; j += w) a[i][j] = - S - 1;
	rep (i, 1, H) rep (j, 1, W) sum += a[i][j];
	
	if (sum <= 0) puts("No");
	else {
		puts("Yes");
		rep (i, 1, H) rep (j, 1, W) printf("%d%c", a[i][j], " \n"[j == W]);
	}

	return 0;
}