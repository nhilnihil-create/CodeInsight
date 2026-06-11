#include <cstdio>
using namespace std;

const int MAXN = 100000 + 10;

struct Edge {
	int next, to;
};

int n;
Edge e[MAXN << 1];
int tot, head[MAXN];
int dis1[MAXN], dis2[MAXN];
int sum1, sum2;

void Add_edge(int u, int v) {
	
	e[++tot].next = head[u]; e[tot].to = v; head[u] = tot;
	
}

void Pre() {
	
	for (int i = 0; i <= MAXN - 10; i++) {
		dis1[i] = -1; dis2[i] = -1;
	}
	
}

void dfs_1(int u, int dep) {
	
	dis1[u] = dep;
	
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (dis1[v] == -1)
			dfs_1(v, dep + 1);
	}
	
}

void dfs_2(int u, int dep) {
	
	dis2[u] = dep;
	
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (dis2[v] == -1)
			dfs_2(v, dep + 1);
	}
	
}

int main() {
	
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Add_edge(a, b); Add_edge(b, a);
	}
	
	Pre();
	
	dfs_1(1, 0);
	dfs_2(n, 0);
	
	for (int i = 1; i <= n; i++) {
		if (dis1[i] <= dis2[i])
			sum1++;
		else
			sum2++;
	}
	
//	printf("%d %d\n", sum1, sum2);
	
	if (sum1 > sum2)
		puts("Fennec");
	else
		puts("Snuke");
	
	return 0;
	
}