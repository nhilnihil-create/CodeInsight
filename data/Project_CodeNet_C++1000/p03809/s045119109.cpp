#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
inline int read()
{
	int f = 1, x = 0;
	char ch;

	do{
		ch = getchar();
		if (ch == '-')
			f = -1;
	}while(ch < '0' || ch > '9');
	do{
		x = x * 10 + ch - '0';
		ch = getchar();
	}while(ch >= '0' && ch <= '9');
	return f * x;
}
const int N = 1e5;

int n;
int val[N + 1];
struct Edge {
	int to, next;
} edge[(N << 1) + 1];
int start[N + 1], tot;
int d[N + 1], up[N + 1];

inline void addedge(int u, int v)
{
	edge[++tot] = Edge{ v, start[u] };
	start[u] = tot;
	edge[++tot] = Edge{ u, start[v] };
	start[v] = tot;
	d[u]++;
	d[v]++;
	return;
}
inline bool dfs(int u, int fa)
{
	if (d[u] == 1) {
		up[u] = val[u];
		return false;
	}
	int sum = 0, maxx = 0;
	for (int i = start[u]; i; i = edge[i].next) {
		int v = edge[i].to;
		if (v != fa) {
			if (dfs(v, u))
				return true;
			sum += up[v];
			maxx = max(maxx, up[v]);
		}
	}
	up[u] = (val[u] << 1) - sum;
	if (up[u] < 0 || up[u] > val[u] || val[u] < maxx) {
		printf("NO\n");
		return true;
	}
	return false;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		val[i] = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		addedge(u, v);
	}
	if (n == 2) {
		if (val[1] == val[2])
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] > 1) {
			if (!dfs(i, 0)) {
				if (up[i])
					printf("NO\n");
				else
					printf("YES\n");
			}
			break;
		}
	}

	return 0;
}
