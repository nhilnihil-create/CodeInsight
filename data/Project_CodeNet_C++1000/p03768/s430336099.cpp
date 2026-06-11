#include <bits/stdc++.h>

using namespace std;
const int N = 2e5;

int n, q, m;
int vis[N][20], color[N], v[N], d[N], c[N];
vector < int > a[N];

int read(void)
{
	int s = 0, w = 0; char c = getchar();
	while (c < '0' || c > '9') w |= c == '-', c = getchar();
	while (c >= '0' && c <= '9') s = s*10+c-48, c = getchar();
	return w ? -s : s;
}

void dfs(int v,int d,int c)
{
	if (vis[v][d]) return;
	vis[v][d] = 1;
	if (!color[v]) color[v] = c;
	if (d == 0) return;
	for (int i=0;i<a[v].size();++i)
	{
		int y = a[v][i];
		dfs(y,d-1,c);	
	} 
	return;
}

int main(void)
{
	n = read(), m = read();
	for (int i=1,x,y;i<=m;++i)
	{
		x = read(), y = read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int q = read();
	for (int i=1;i<=q;++i) {
		v[i] = read();
		d[i] = read();
		c[i] = read();
	}
	while (q) dfs(v[q],d[q],c[q]), q --;
	for (int i=1;i<=n;++i)
		printf("%d\n", color[i]);
	return 0;
}