#include <cstdio>
#include <algorithm>

using i32 = int;
using i64 = long long;
constexpr i32 maxn = 20000;

inline i32 in() {
	i32 n;
	scanf("%d", &n);
	return n;
}

i32 p[maxn + 1],
	a[maxn + 1],
	b[maxn + 1];
i32 main() {
	const i32 n = in();
	for (i32 i = 1; i <= n; ++i)
		a[i] = 30000 * i, b[n + 1 - i] = a[i];
	for (i32 i = 1; i <= n; ++i)
		p[i] = in(), a[p[i]] += i;

		
	for (i32 i = 1; i <= n; ++i)
		printf("%d%c", a[i], " \n"[i == n]);
	for (i32 i = 1; i <= n; ++i)
		printf("%d%c", b[i], " \n"[i == n]);
	
	return 0;
}