#include <bits/stdc++.h>
using namespace std;
#define maxn 500000
int n, K, ans, a[maxn];

int read()
{
	int x = 0, k = 1;
	char c; c = getchar();
	while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * k;
}

struct edge
{
	int cnp, to[maxn], last[maxn], head[maxn];
	edge() { cnp = 2; }
	void add(int u, int v)
	{ to[cnp] = v, last[cnp] = head[u], head[u] = cnp ++; }
}E1;

int dfs(int u)
{
	int ret = 0;
	for(int i = E1.head[u]; i; i = E1.last[i])
	{
		int v = E1.to[i];
		ret = max(ret, dfs(v)); 
	}
	if(a[u] != 1 && u != 1 && ret + 1 - (u == 1) >= K) { ans ++; return 0; }
	return ret + 1;
}

int main()
{
	n = read(), K = read();
	for(int i = 1; i <= n; i ++)
	{
		a[i] = read();
		if(i != 1) E1.add(a[i], i);
	}
	dfs(1);
	printf("%d\n", ans + (a[1] != 1));
	return 0;
}