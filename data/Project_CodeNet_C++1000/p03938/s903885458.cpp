#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }

typedef long long ll;

const int kN = 2e4 + 5;

int p[kN], pre[kN];

int main() {
	int n; Read(n);
	for(int i = 1; i <= n; ++i) Read(p[i]), pre[p[i]] = i;
	for(int i = 1; i <= n; ++i) printf("%lld ", (ll)n * i);
	printf("\n");
	for(int i = 1; i <= n; ++i) printf("%lld ", (ll)n * n + pre[i] - (ll)n * i);
	return 0;
}