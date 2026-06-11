#include <bits/stdc++.h>

#define N 200020

using namespace std;

struct EDGE {
	int adj, next;
} edge[N * 2];

int n, gh[N], sg[N], top;

void addedge(int x, int y) {
	edge[++top].adj = y;
	edge[top].next = gh[x];
	gh[x] = top;
}

void dfs(int x, int root = 0) {
	sg[x] = 0;
	for (int p = gh[x]; p; p = edge[p].next)
		if (edge[p].adj != root) {
			dfs(edge[p].adj, x);
			sg[x] ^= sg[edge[p].adj];
		}
	sg[x] += 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	dfs(1);
	puts(sg[1] != 1 ? "Alice" : "Bob");
}