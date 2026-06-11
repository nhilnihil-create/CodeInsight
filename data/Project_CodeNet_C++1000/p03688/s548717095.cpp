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

int n, mx, mn, a[kN], cnt;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n); mx = 0; mn = n;
		for(int i = 1; i <= n; ++i)
			rd(a[i]), mx = std::max(mx, a[i]), mn = std::min(mn, a[i]);
		if(mn == mx && mn == n - 1) return printf("Yes\n"), 0;
		if(mx - mn > 1) return printf("No\n"), 0;
		if(mn == mx) --mn;
		for(int i = 1; i <= n; ++i)
			if(a[i] == mn) ++cnt;
		for(int i = 1; i <= n; ++i) {
			int dlt = (a[i] == mn);
			//printf("%d %d\n", cnt - dlt + 1, (n - cnt) / 2);
			if(a[i] < cnt - dlt + 1 || a[i] > cnt - dlt + (n - cnt) / 2)
				return printf("No\n"), 0;
		}
		printf("Yes\n");
	} return 0;
}