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

ll a[kN], d[kN], c, M;

int main() {
	int n; rd(n); c = (ll)n * (n + 1) / 2;
	for(int i = 1; i <= n; ++i) rd(a[i]), M += a[i];
	if(M % c != 0) { printf("NO"); return 0; }
	M /= c;
	for(int i = 1; i <= n; ++i) d[i] = a[i % n + 1] - a[i];
	for(int i = 1; i <= n; ++i)
		if(d[i] > M || (M - d[i]) % n != 0) {
			printf("NO"); return 0;
		}
	printf("YES");
	return 0;
}