#include <bits/stdc++.h>
//#define inf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define N 200005

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

int n, a[N];
bool flag;

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);

	for (int i = 2; i <= n; ++i) flag |= a[i] != a[i - 1];
	if (!flag) {
		if (a[1] == n - 1 || a[1] * 2 <= n) return puts("Yes"), 0;
		else return puts("No"), 0;
	}

	int MAX = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) chkmax(MAX, a[i]);
	for (int i = 1; i <= n; ++i) {
		if (MAX - a[i] > 1) return puts("No"), 0;
		if (a[i] == MAX) ++cnt;
	}

	debug("%d %d\n", MAX, cnt);
	if (MAX <= cnt / 2 + n - cnt && MAX > n - cnt) return puts("Yes"), 0;
	else return puts("No"), 0;
}
