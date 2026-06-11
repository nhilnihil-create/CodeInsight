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

const int kN = 1e5 + 5, kD = 12;

int n, m, c[kN], t[kN][kD];
std::vector <int> E[kN];

int main() {
	rd(n, m);
	for(int i = 1; i <= m; ++i) {
		int x, y; rd(x, y);
		E[x].push_back(y); E[y].push_back(x);
	}
	int q; rd(q);
	for(int i = 1; i <= q; ++i) {
		int v, d; rd(v, d, c[i]);
		t[v][d] = i;
	}
	for(int k = 10; k; --k) 
		for(int i = 1; i <= n; ++i)
			for(auto v : E[i])
				t[v][k - 1] = std::max(t[i][k], t[v][k - 1]);
	for(int i = 1; i <= n; ++i) {
		int x = 0;
		for(int j = 0; j <= 10; ++j) x = std::max(x, t[i][j]);
		printf("%d\n", c[x]);
	}
	return 0;
}