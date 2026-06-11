#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 100005, MQ = 100005;

int N, M;
std::vector<int> G[MN];
int Q, qv[MQ], qd[MQ], qc[MQ];
int tag[MN], tmp[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i) scanf("%d%d%d", &qv[i], &qd[i], &qc[i]);
	for (int j = 10; j >= 0; --j) {
		for (int u = 1; u <= N; ++u) tmp[u] = 0;
		for (int u = 1; u <= N; ++u) if (tag[u])
			for (int v : G[u]) tmp[v] = std::max(tmp[v], tag[u]);
		for (int u = 1; u <= N; ++u) tag[u] = std::max(tag[u], tmp[u]);
		for (int i = 1; i <= Q; ++i) if (qd[i] == j) tag[qv[i]] = std::max(tag[qv[i]], i);
	}
	for (int u = 1; u <= N; ++u) printf("%d\n", qc[tag[u]]);
	return 0;
}