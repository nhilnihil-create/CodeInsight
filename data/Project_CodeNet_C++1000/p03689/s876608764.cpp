#include <bits/stdc++.h>
//#define inf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define N 505

using namespace std;
typedef pair<int,int> Pair;
typedef long long ll;

const long double Pi = 3.14159265358979323846l;
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
	T x; char ch; while (!isdigit(ch = getchar()));
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

long long sum, a[N][N];
long long n, m, h, w;

int main() {
	read(n, m, h, w);
	for (int i = h; i <= n; i += h)
		for (int j = w; j <= m; j += w)
			a[i][j] = - 4000ll * (h * w - 1) - 1, sum += a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!a[i][j]) a[i][j] = 4000, sum += 4000;

	if (sum <= 0) return puts("No"), 0;
	puts("Yes");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) printf("%lld ", a[i][j]);
		printf("%lld\n", a[i][m]);
	}
	return 0;
}
