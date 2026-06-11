#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define N 100005

using namespace std;
typedef pair<int,int> Pair;
typedef long long ll;

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

int n, L, T, pos;
int x[N], d[N], ans[N];

int main() {
	read(n, L, T);
	for (int i = 1; i <= n; ++i) read(x[i], d[i]), d[i] = d[i] == 2 ? -1 : 1;
	for (int i = 1; i <= n; ++i) {
		x[i] = x[i] + T * d[i], pos += x[i] / L;
		if (x[i] % L < 0) --pos;
		x[i] = (x[i] % L + L) % L;
	}

	pos = (pos % n + n) % n + 1;
	sort(x + 1, x + n + 1);
	for (int i = pos; i <= n; ++i) printf("%d\n", x[i]);
	for (int i = 1; i < pos; ++i) printf("%d\n", x[i]);
	return 0;
}
