#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 100005;

int N, K, A[MN], Ans;
std::vector<int> G[MN];

int dep[MN], kpar[MN], per[MN], stk[MN], tp;
void DFS(int u) {
	stk[++tp] = u;
	if (dep[u] > K) kpar[u] = stk[tp - K + 1];
	for (int v : G[u]) dep[v] = dep[u] + 1, DFS(v);
	--tp;
}

int del[MN];
void Del(int u) {
	del[u] = 1;
	for (int v : G[u]) if (!del[v]) Del(v);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	if (A[1] != 1) A[1] = 1, Ans = 1;
	for (int i = 2; i <= N; ++i) G[A[i]].push_back(i);
	DFS(1);
	for (int i = 1; i <= N; ++i) per[i] = i;
	std::sort(per + 1, per + N + 1, [](int i, int j) { return dep[i] > dep[j]; });
	for (int i = 1; i <= N; ++i) if (kpar[per[i]] && !del[per[i]]) ++Ans, Del(kpar[per[i]]);
	printf("%d\n", Ans);
	return 0;
}
