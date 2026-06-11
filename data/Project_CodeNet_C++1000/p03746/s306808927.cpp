
#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 100005;

int N, M;
std::vector<int> G[MN];
int vis[MN], A[MN], B[MN], C, D;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i <= M; ++i) 
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	A[C = 1] = 1;
	B[D = 1] = 1;
	vis[1] = 1;
	while (1) {
		int u = A[C], w = 0;
		for (int v : G[u]) if (!vis[v]) w = v;
		if (!w) break;
		vis[w] = 1, A[++C] = w;
	}
	while (1) {
		int u = B[D], w = 0;
		for (int v : G[u]) if (!vis[v]) w = v;
		if (!w) break;
		vis[w] = 1, B[++D] = w;
	}
	printf("%d\n", C + D - 1);
	for (int i = C; i >= 2; --i) printf("%d ", A[i]);
	for (int i = 1; i <= D; ++i) printf("%d%c", B[i], " \n"[i == D]);
	return 0;
}