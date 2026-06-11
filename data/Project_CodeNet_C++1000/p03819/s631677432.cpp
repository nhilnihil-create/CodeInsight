#include <bits/stdc++.h>
//#define inf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define N 300005

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

template <class T> inline void chkmin(T &x, T y) { x = x < y ? x : y; }
template <class T> inline void chkmax(T &x, T y) { x = x > y ? x : y; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

int n, m;
int l[N], r[N], now;
Pair a[N];

inline bool cmp(Pair x, Pair y) {
	return (x.se - x.fi) > (y.se - y.fi);
}

struct BIT {
	int cnt[N];
	void Add(int x, int val) { for (; x < N; x += x & -x) cnt[x] += val; }
	int query(int x) { int res = 0; for (; x; x ^= x & -x) res += cnt[x]; return res; }
	void add(int l, int r) { Add(l, 1), Add(r + 1, -1); }
}bit;

int main() {
	read(n, m);
	for (int i = 1, l, r; i <= n; ++i)
		read(l, r), a[i] = make_pair(l, r);

	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i)
		l[i] = a[i].fi, r[i] = a[i].se;
	now = n;

	for (int d = 1; d <= m; ++d) {
		while (now && r[now] - l[now] + 1 < d)
			bit.add(l[now], r[now]), --now;
		int ans = now;
		for (int i = 0; i <= m; i += d)
			ans += bit.query(i);
		printf("%d\n", ans);
	}
	return 0;
}
