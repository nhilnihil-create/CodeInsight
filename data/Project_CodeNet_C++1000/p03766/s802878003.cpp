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
const int mod = 1e9 + 7;
const int maxN = 1e6 + 7;

inline int pls(int x, int y) {return (x + y) % mod;}
inline int mns(int x, int y) {return pls(x, mod - y);}
inline int mul(int x, int y) {return 1LL * x * y % mod;}
inline void Add(int &x, int y) {x = pls(x, y);}
inline void Mul(int &x, int y) {x = mul(x, y);}

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

int n;
int f[maxN], s[maxN];

int main() {

	n = ri();

	f[0] = 1, f[1] = n;
	s[0] = 1, s[1] = n + 1;
	rep (i, 2, n) {
		f[i] = f[i - 1];
		Add(f[i], mul(n-1, n-1));
		if (i == 2) Add(f[i], n-1);
		else {
			int l = i - 2;
			Add(f[i], s[i-3]);
			Add(f[i], n - 1 - l);
		}
		s[i] = pls(s[i-1], f[i]);
	}

	printf("%d\n", f[n]);

	return 0;
}
