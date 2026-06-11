#include <cstdio>
#include <iostream>
#define MN 101000

typedef long long ll;

int n, rt;
int d[MN], v[MN];
ll c[MN];
bool ok = 1; 

int h[MN], nxt[2 * MN], to[2 * MN], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int fa)
{
	c[x] = v[x];
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs(to[i], x);
		c[x] -= c[to[i]];
	}
	if(c[x] < 0 || (x == rt && c[x] != 0)) ok = 0; 
	if(d[x] > 1)
	{
		ll sum = 0, Max = 0;
		for(int i = h[x]; i; i = nxt[i])
			if(to[i] != fa) sum += c[to[i]], Max = std::max(Max, c[to[i]]);
		if(((sum - c[x]) & 1) || sum - c[x] < 0) ok = 0;
		if((sum - c[x]) / 2 < Max - c[x]) ok = 0; 
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(int i = 1; i < n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		ins(a, b); ins(b, a); 
		d[a]++; d[b]++; 
	}
	if(n == 2)
	{
		if(v[1] == v[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		if(d[i] > 1) rt = i, v[i] *= 2;
	dfs(rt, 0);
	if(!ok) puts("NO");
	else puts("YES");
}