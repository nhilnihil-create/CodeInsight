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

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 1e5 + 5;

ll a[kN], s[kN], tot = 0; int n, k;

int main() {
	rd(n, k);
	for(int i = 1; i <= n; ++i)
		rd(a[i]), s[i] = s[i - 1] + a[i] * (a[i] < 0), tot += a[i] * (a[i] > 0);
	ll ans = 0;
	for(int i = k; i <= n; ++i) {
		ans = std::max(ans, tot + (s[i] - s[i - k]));
	}
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i] * (a[i] > 0);
	for(int i = k; i <= n; ++i) {
		ans = std::max(ans, tot - (s[i] - s[i - k]));
	}
	printf("%lld", ans);
	return 0;
}