#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define N 200005

using namespace std;
typedef pair<int,int> Pair;

const int mod = 1e9 + 7;
inline int add(int x, int y) { return (x += y) - (x >= mod ? mod : 0); }
inline void inc(int &x, int y) { (x += y) -= (x >= mod ? mod : 0); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int Power(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mul(res, x);
		x = mul(x, x), y >>= 1;
	} return res;
}

template <class T> inline T	input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

template <class T> inline void chkmin(T &x, T &y) { x = x < y ? x : y; }
template <class T> inline void chkmax(T &x, T &y) { x = x > y ? x : y; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

int w, h, a, b, ans;
int fac[N], ifac[N];

int C(int x, int y) {
	if (y < 0 || x < y) return 0;
	return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

int Path(int x, int y) { return C(x + y, x); }

void init() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
	ifac[N - 1] = inv(fac[N - 1]);
	for (int i = N - 2; i; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}

int main() {
	init();
	read(h, w, a, b);
	a = h - a + 1;

	for (int x = a - 1, y = b + 1; x && y <= w; --x, ++y)
		inc(ans, mul(Path(x - 1, y - 1), Path(h - x, w - y)));

	printf("%d\n", ans);
	return 0;
}
