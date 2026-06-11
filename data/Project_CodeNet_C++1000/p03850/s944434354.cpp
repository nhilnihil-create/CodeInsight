#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
//#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define N 100005

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

int n;
long long a[N], opt[N];
long long f[N][3];
char s[2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%lld%s", a + i, s);
		opt[i + 1] = s[0] == '-' ? -1 : 1;
	}
	scanf("%lld", a + n), opt[1] = 1;

	f[0][1] = f[0][2] = -inf;
	for (int i = 1; i <= n; ++i) {
		if (opt[i] == 1) {
			f[i][0] = f[i - 1][0] + a[i];
			f[i][1] = max(f[i - 1][1] - a[i], f[i - 1][2] + a[i]);
			f[i][2] = f[i - 1][2] + a[i];
		} else {
			f[i][0] = f[i][1] = max(f[i - 1][0] - a[i], f[i - 1][1] + a[i]);
			f[i][2] = max(f[i - 1][2] - a[i], f[i - 1][1] + a[i]);
		}
	}

	printf("%lld\n", f[n][0]);
	return 0;
}
