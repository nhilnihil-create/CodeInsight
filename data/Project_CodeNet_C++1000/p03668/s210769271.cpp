#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
int N;
int cnt = 1, Head[MAXN], Next[MAXM], To[MAXM];

inline void add_edge(int x, int y) {
	Next[++cnt] = Head[x], To[cnt] = y, Head[x] = cnt;
}

inline void insert_edge(int x, int y) {
	add_edge(x, y), add_edge(y, x);
}

inline int Dfs(int x, int fa = 0) {
	register int i; int res = 0;
	for(i = Head[x]; i; i = Next[i])
		if(To[i] != fa)
			res ^= Dfs(To[i], x) + 1;
	return res;
}

int main() {
	register int i; int x, y;
	scanf("%d", &N);
	for(i = 1; i < N; ++i)
		scanf("%d%d", &x, &y),
		insert_edge(x, y);
	puts(Dfs(1, 0) ? "Alice" : "Bob");
	return 0;
}