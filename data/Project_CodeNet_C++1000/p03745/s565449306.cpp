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
#define V std::vector
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, k, q, a[kN];
int main() { 
	int T = 1; //rd(T);
	while(T--) {
		rd(n); int cnt = 0, len = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
		}
		n = std::unique(a + 1, a + n + 1) - a - 1;
		for(int i = 1; i <= n; ++i, ++len) {
			if(len >= 2 && (a[i] >= a[i - 1]) != (a[i - 1] >= a[i - 2])) {
				++cnt; len = 0;
			}
		}
		printf("%d", cnt + 1);
	} return 0;
}