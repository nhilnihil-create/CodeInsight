#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL v[maxn];
int cnt, h[maxn];
struct edge
{
	int to, pre;
} e[maxn<<1];
void add(int from, int to)
{
	cnt++;
	e[cnt].pre = h[from];
	e[cnt].to = to;
	h[from] = cnt;
}
int deg[maxn], ok;
LL dfs(int x, int f)
{
	if(deg[x] == 1) return v[x];
	LL ret = v[x] + v[x];
	for(int i = h[x]; i; i = e[i].pre)
	{
		int to = e[i].to;
		if(to == f) continue;
		LL tmp = dfs(to, x);
		if(tmp > v[x]) ok = 0;
		if(tmp > ret) ok = 0;
		ret -= tmp;
	}
	if(ret > v[x]) ok = 0;
	return ret;
}
int N;
int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", v + i);
	for(int i = 1; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b);
		add(b, a);
		deg[a]++;
		deg[b]++;
	}
	if(N == 2)
	{
		if(v[1] == v[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	int rt = 0;
	for(int i = 1; i <= N; i++)
		if(deg[i] != 1)
		{
			rt = i;
			break;
		}
	ok = 1;
	if(dfs(rt, 0) != 0) ok = 0;
	puts(ok ? "YES":"NO");
	return 0;
}