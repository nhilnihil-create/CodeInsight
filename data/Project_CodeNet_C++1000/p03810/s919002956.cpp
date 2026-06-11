#include <bits/stdc++.h>
//#define inf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
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

template <class T> inline void chkmin(T &x, T &y) { x = x < y ? x : y; }
template <class T> inline void chkmax(T &x, T &y) { x = x > y ? x : y; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

int n, cnt;
int a[N];
long long sum;
bool flag, flag2;

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

void work() {
	int G = a[1];
	for (int i = 2; i <= n; ++i) G = gcd(G, a[i]);
	for (int i = 1; i <= n; ++i) a[i] /= G;
}

int main() {
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]), sum += a[i], cnt += a[i] & 1, flag2 |= a[i] == 1;
	if (n == 1) {
		if (a[1] & 1) return puts("Second"), 0;
		else return puts("First"), 0;
	}

	if ((sum - n) & 1) return puts("First"), 0;
	while (cnt == 1 && !flag2) {
		cnt = 0, flag ^= 1;
		for (int i = 1; i <= n; ++i)
			if (a[i] & 1) --a[i];
		while (!cnt) {
			flag2 = false, work();
			for (int i = 1; i <= n; ++i)
				cnt += a[i] & 1, flag2 |= a[i] == 1;
		}

		sum = 0;
		for (int i = 1; i <= n; ++i) sum += a[i];
		if ((sum - n) & 1) return puts(flag ? "Second" : "First"), 0;
	}

	puts(flag ? "First" : "Second");
	return 0;
}
