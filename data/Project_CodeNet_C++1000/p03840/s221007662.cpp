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

ll Check(ll a1, ll a2, ll a4, ll a5) {
	return (a1 - a1 % 2) + a2 + (a4 - a4 % 2) + (a5 - a5 % 2);
}

int main() {
	ll a1, a2, a3, a4, a5, a6, a7;
	rd(a1, a2, a3, a4, a5, a6, a7);
	ll ans = Check(a1, a2, a4, a5);
	ans = std::max(ans, Check(a1 - 1, a2, a4 - 1, a5 - 1) + (a1 > 0 && a4 > 0 && a5 > 0) * 3);
	printf("%lld", ans);
	return 0;
}