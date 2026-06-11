#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
const int maxn = 1e5 + 10;
struct Query
{
	int v, d, c;
}a[maxn];
vector<int> E[maxn];
int n, m, q;
int c[maxn], col[maxn];
void calc(int d)
{
	for(int i = q; i; --i) 
		if(a[i].d == d)
			col[a[i].v] = max(col[a[i].v], i);
	if(d > 0)
	{
		for(int i = 1; i <= n; ++i) c[i] = col[i];
		for(int i = 1; i <= n; ++i)
			for(auto v : E[i])
				c[v] = max(c[v], col[i]);
		for(int i = 1; i <= n; ++i)
			col[i] = c[i];
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) 
	{
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) scanf("%d%d%d", &a[i].v, &a[i].d, &a[i].c);
	for(int i = 10; ~i; --i) calc(i);
	for(int i = 1; i <= n; ++i)
		printf("%d\n", a[col[i]].c);
	return 0;
}