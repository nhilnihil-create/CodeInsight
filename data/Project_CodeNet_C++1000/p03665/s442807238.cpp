#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, p; ll f[kN][2];

int main() {
	int T = 1; //rd(T);
	while(T--) {
		rd(n, p);
		f[0][0] = 1;
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			x &= 1;
			for(int j = 0; j < 2; ++j)
				f[i][j] += f[i - 1][j ^ x];
			for(int j = 0; j < 2; ++j)
				f[i][j] += f[i - 1][j];
		}
		printf("%lld\n", f[n][p]);
	} return 0;
}