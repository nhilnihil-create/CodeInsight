#if 0
date +%Y.%m.%d

题解先咕着。
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 100005;
int head[maxn], nxt[maxn];

int dfs(int u) {
	std::vector<int> ve;
	for(int i = head[u]; i; i = nxt[i])
		ve.push_back(dfs(i));
	std::sort(ve.begin(), ve.end());

	int res = 0;
	for(int x : ve)
		res = std::max(x, res) + 1;
	return res;
}

int main() {
	int n = read;
	for(int i = 2; i <= n; i ++) {
		int f = read;
		nxt[i] = head[f];
		head[f] = i;
	}

	printf("%d\n", dfs(1));
}
