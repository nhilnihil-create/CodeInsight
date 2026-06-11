#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

int N, M; LL K;
LL x[MN];
int per[MN], vis[MN], stk[MN], tp;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &x[i]);
	for (int i = N; i >= 2; --i) x[i] -= x[i - 1];
	for (int i = 1; i <= N; ++i) per[i] = i;
	scanf("%d%lld", &M, &K);
	while (M--) {
		int p;
		scanf("%d", &p);
		std::swap(per[p], per[p + 1]);
	}
	for (int i = 1; i <= N; ++i) if (!vis[i]) {
		tp = 0;
		int u = i;
		do vis[u] = 1, stk[tp++] = u, u = per[u]; while (u != i);
		for (int j = 0; j < tp; ++j) per[stk[j]] = stk[(j + K) % tp];
	}
	LL s = 0;
	for (int i = 1; i <= N; ++i) s += x[per[i]], printf("%lld\n", s);
	return 0;
}