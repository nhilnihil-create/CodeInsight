#include <cstdio>
#include <algorithm>

using i32 = int;
using i64 = long long;
constexpr i32 maxn = 100000;

inline i32 in() {
	static i32 n;
	scanf("%d", &n);
	return n;
}

i32 a[maxn + 1];

i32 main() {
	const i32 n = in(), T = in();
	for (i32 i = 1; i <= n; ++i)
		a[i] = in();
	
	std::pair<i32, i32> ans = std::make_pair(0, 0);
	for (i32 i = n, mx = 0; i > 0; --i) {
		mx = std::max(mx, a[i]);
		const i32 val = mx - a[i];
		if (val > ans.first) ans = std::make_pair(val, 1);
		else if (val == ans.first) ++ans.second;
	}
	printf("%d\n", ans.second);
	
	return 0;
}